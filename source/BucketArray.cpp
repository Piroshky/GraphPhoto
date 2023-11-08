#include <vector>
#include <cstdint>

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

  int bucket_count = 0;  
  std::vector<Bucket<T, items_per_bucket> *> all_buckets;
  
  int unfull_bucket_count = 0;
  std::vector<Bucket<T, items_per_bucket> *> unfull_buckets;

  iterator<T, items_per_bucket> begin() {return iterator{this};}
  iterator<T, items_per_bucket> end()   {return iterator{this, count};}

  // public
  BucketLocator  add(T *obj);
  T             *request();   // gives a pointer an unused bucket slot and initializes the memory with default constructor.
  T             *get(int index);
  void           remove(T *obj);

  // internal
  void add_bucket();
  void debug();  
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
  pointer   operator->()      { return ptr; }
    
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


//// public BucketArray functions

// add(T *obj)
template<typename T, int items_per_bucket>
BucketLocator BucketArray<T, items_per_bucket>::add(T *obj) {
  if (unfull_bucket_count == 0) {
    add_bucket();
  }

  Bucket<T, items_per_bucket> *bucket = unfull_buckets[0];
  
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
  count  += 1;

  if (bucket->count == items_per_bucket) {
    unfull_buckets.erase(unfull_buckets.begin());
    unfull_bucket_count -= 1;
  }

  return BucketLocator{bucket->bucket_index, index};
}

// request();
template<typename T, int items_per_bucket>
T *BucketArray<T, items_per_bucket>::request() {
  if (unfull_bucket_count == 0) {
    add_bucket();
  }

  Bucket<T, items_per_bucket> *bucket = unfull_buckets[0];
  
  int index = -1;
  for (int i = 0; i < items_per_bucket; ++i) {
    if (!bucket->fill_mask[i]) {
      index = i;
      break;
    }
  }

  bucket->fill_mask[index] = true;
  bucket->data[index] = T{};
  bucket->count += 1;
  count  += 1;

  if (bucket->count == items_per_bucket) {
    unfull_buckets.erase(unfull_buckets.begin());
    unfull_bucket_count -= 1;
  }

  return &(bucket->data[index]);
}

// get(int index);
template<typename T, int items_per_bucket>
T *BucketArray<T, items_per_bucket>::get(int index) {
  for (auto b : all_buckets) {
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

// remove(T *obj);
template<typename T, int items_per_bucket>
void BucketArray<T, items_per_bucket>::remove(T *obj) {
  for (auto b : all_buckets) {
    if ((uintptr_t)b < (uintptr_t)obj  &&  (uintptr_t)obj < (uintptr_t)(b + 1)) {
      int calc_index = ((uintptr_t)obj - (uintptr_t)b->data) / (sizeof(T));      
      b->fill_mask[calc_index] = false;

      if(b->count == items_per_bucket) {
	unfull_bucket_count += 1;
	unfull_buckets.push_back(b);
      }	
      
      b->count -= 1;
      count -= 1;
      break;
    }
  }
}


//// internal functions

// add_bucket();
template<typename T, int items_per_bucket>
void BucketArray<T, items_per_bucket>::add_bucket() {
  Bucket<T, items_per_bucket> *new_bucket = new Bucket<T, items_per_bucket>;
  new_bucket->bucket_index = bucket_count;
    
  all_buckets.push_back(new_bucket);
  bucket_count += 1;
  unfull_buckets.push_back(new_bucket);  
  unfull_bucket_count += 1;    
}

// debug();
template<typename T, int items_per_bucket>
void BucketArray<T, items_per_bucket>::debug() {
  printf("---------------------------------------------\n"
	 "     items_per_bucket = %d\n"
	 "                count = %d\n\n"
	 "         bucket_count = %d\n"
	 "     full_bucket size = %d\n\n"
	 "  unfull_bucket_count = %d\n"
	 "   unfull_bucket size = %d\n",
	 items_per_bucket,
	 count,
	 bucket_count,
	 all_buckets.size(),
	 unfull_bucket_count,
	 unfull_buckets.size());

  if (bucket_count > 0) {
    printf("\nall buckets:\n");
    for (int i = 0; i < bucket_count; ++i) {
      Bucket<T, items_per_bucket> *b = all_buckets[i];
      printf("   bucket_index = %d, (%d / %d)\n", b->bucket_index, b->count, items_per_bucket);
      printf("     [");
      for(auto fill : b->fill_mask) {
	printf(" %c", fill ? 'X' : '_');
      }
      printf(" ]\n");
    }
  }
}
