#include <vector>

struct BucketLocator {
  int bucket_index;
  int slot_index;
};

template<typename T, int items_per_bucket> 
struct Bucket {
  int bucket_index = 0;
  int count = 0;

  bool fill_mask[items_per_bucket] = {false};
  T data[items_per_bucket];
};

template<typename T, int items_per_bucket> struct iterator;

template<typename T, int items_per_bucket> 
struct BucketArray {
  int count = 0;

  int    bucket_count = 0;  
  std::vector<Bucket<T, items_per_bucket> *> all_buckets;
  
  int unfull_bucket_count = 0;
  std::vector<Bucket<T, items_per_bucket> *> unfull_buckets;

  iterator<T, items_per_bucket> begin() {return iterator{this};}
  iterator<T, items_per_bucket> end()   {return iterator{this, count};}
  
};

template<typename T, int items_per_bucket>
struct iterator {
  using iterator_category = std::forward_iterator_tag;
  using difference_type   = std::ptrdiff_t;
  using value_type        = T;
  using pointer           = T*;
  using reference         = T&;

  BucketArray<T, items_per_bucket> *array;
  int index = 0;
  int bucket_index = 0;
  int slot_index = 0;
  pointer ptr = NULL;
    
  iterator(BucketArray<T, items_per_bucket> *a) {
    array = a;
    for (auto b : array->all_buckets) {
      slot_index = 0;
      while (slot_index < items_per_bucket) {
	if (b->fill_mask[slot_index]) {
	  ptr = &(b->data[slot_index]);
	  return;
	}
	slot_index += 1;
      }
      bucket_index += 1;
    }
  }

  iterator(BucketArray<T, items_per_bucket> *a, int b) {
    array = a;
    index = b;
  }

  reference operator*() const { return *ptr; }
  pointer operator->() { return ptr; }
    
  iterator& operator++() {
    index += 1;
    while (bucket_index < array->bucket_count) {
      auto b = array->all_buckets[bucket_index];
      while (slot_index < items_per_bucket - 1) {
	slot_index += 1;
	if (b->fill_mask[slot_index]) {
	  ptr = &(b->data[slot_index]);
	  return *this;
	}
      }
      slot_index = -1;
      bucket_index += 1;
    }
    return *this;
  }

  iterator operator++(int) { iterator tmp = *this; ++this; return tmp; }

  friend bool operator== (const iterator& a, const iterator& b) { return a.index == b.index; }
  friend bool operator!= (const iterator& a, const iterator& b) { return a.index != b.index; }
};

template<typename T, int items_per_bucket>
void BucketArray_add_bucket(BucketArray<T, items_per_bucket> *array) {
  Bucket<T, items_per_bucket> *new_bucket = new Bucket<T, items_per_bucket>;
  new_bucket->bucket_index = array->bucket_count;
    
  array->all_buckets.push_back(new_bucket);
  array->bucket_count += 1;
  array->unfull_buckets.push_back(new_bucket);  
  array->unfull_bucket_count += 1;
}

template<typename T, int items_per_bucket>
BucketLocator BucketArray_add(BucketArray<T, items_per_bucket> *array, T *obj) {
  if (array->unfull_bucket_count == 0) {
    BucketArray_add_bucket(array);
  }

  Bucket<T, items_per_bucket> *bucket = array->unfull_buckets[0];
  
  int index = -1;
  for (int i = 0; i < items_per_bucket; ++i) {
    if (!bucket->fill_mask[i]) {
      index = i;
      break;
    }
  }

  bucket->fill_mask[index] = true;
  bucket->data[index] = *obj;
  bucket->count += 1;
  array->count  += 1;

  if (bucket->count == items_per_bucket) {
    array->unfull_buckets.erase(array->unfull_buckets.begin());
    array->unfull_bucket_count -= 1;
  }

  return BucketLocator{bucket->bucket_index, index};
}

template<typename T, int items_per_bucket>
T *BucketArray_get(BucketArray<T, items_per_bucket> *array, int index) {
  for (auto b : array->all_buckets) {
    if (b->count >= index + 1) {
      int ix = -1;
      for(int i = 0; i < items_per_bucket; ++i) {
	if (b->fill_mask[i]) {
	  ix += 1;
	  if (ix == index) {
	    break;
	  }
	}
      }      
      return &(b->data[ix]);
      
    } else {
      index -= b->count;
    }
  }
  return NULL;
}

template<typename T, int items_per_bucket>
void BucketArray_debug(BucketArray<T, items_per_bucket> *array) {
  printf("---------------------------------------------\n"
	 "     items_per_bucket = %d\n"
	 "                count = %d\n"
	 "         bucket_count = %d\n"
	 "  unfull_bucket_count = %d\n",
	 items_per_bucket,
	 array->count,
	 array->bucket_count,
	 array->unfull_bucket_count);

  if (array->bucket_count > 0) {
    printf("\nall buckets:\n");
    for (int i = 0; i < array->bucket_count; ++i) {
      Bucket<T, items_per_bucket> *b = array->all_buckets[i];
      printf("   bucket_index = %d\n", b->bucket_index);
    }
  }
}
