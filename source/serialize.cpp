#include <sstream>
#include <fstream>
#include <cstdint>
#include <cstring>

#define GP_FILE_VERSION 1
#define GP_FILE_SIGNATURE "graphphoto"

struct filedata {
  uintmax_t length;
  uintmax_t ix;
  char *data;
};

void get_whole_file(const char *filename, filedata *fd) {
  std::FILE *fp = std::fopen(filename, "rb");
  if (fp) {
    std::fseek(fp, 0, SEEK_END);
    fd->length = std::ftell(fp);
    char *buffer = new char [fd->length];
    fd->data = buffer;
    std::rewind(fp);
    std::fread(fd->data, 1, fd->length, fp);
    std::fclose(fp);
    fd->ix = 0;    
    return;
  }
  fprintf(stderr, "Failed to open file %s", filename);
  throw(errno);
}

void save_file() {
  std::stringstream builder;
  builder << GP_FILE_SIGNATURE;
  uint32_t version = GP_FILE_VERSION;
  builder.write(reinterpret_cast<const char*>(&version), sizeof(version));

  
  struct node nodes[] = {{1, 0, 0}, {2, 12, 15}};
  uint32_t num_nodes = sizeof(nodes) / sizeof(struct node);
  printf("num_nodes %d\n", num_nodes);
  
  builder.write(reinterpret_cast<const char*>(&num_nodes), sizeof(num_nodes));

  for (int i = 0; i < num_nodes; ++i) {
    builder.write(reinterpret_cast<const char*>(&nodes[i]), sizeof(struct node));
  }

  
  std::ofstream file;
  file.open("./out.save");
  file << builder.rdbuf();
  file.close();
}

// Copies n bytes from fd->data[ix] to dest, returning false if that
// exceeds the size of fd->data
bool read_n_bytes_from_filedata(filedata *fd, std::byte *dest, uintmax_t n) {
  if (fd->ix + n > fd->length) {
    printf("fd->ix : %d\nn : %d\nfd-length : %d\n", fd->ix, n, fd->length);
    return false;
  }
  
  std::memcpy(dest, &(fd->data[fd->ix]), n);
  fd->ix += n;
  return true;
}

#define GET_N_BYTES(variable) if (!read_n_bytes_from_filedata(&fd, (std::byte*)&variable, sizeof(variable))) {fprintf(stderr, "Unexpected end of file when trying to read " #variable "\n"); return false;}

bool read_file(const char *filename) {
  filedata fd{0,0,0};
  get_whole_file(filename, &fd);
  printf("File length: %ld\n", fd.length);

  // Read File Signature
  char signature[] = FILE_SIGNATURE;
  int sig_len = sizeof(signature) - 1;
  if (sig_len > fd.length) {
    fprintf(stderr, "File `%s` is not large enough to be a GraphPhoto save file\n", filename);
    return false;
  }  
  int ret = strncmp(fd.data, signature, sig_len);
  if (ret != 0) {
    fprintf(stderr, "File `%s` is not a GraphPhoto save file (%d)\n", filename, ret);
    return false;
  }
  fd.ix += sig_len;
  
  // Read File Version
  // sizeof(uint32_t)
  uint32_t version;
  GET_N_BYTES(version);
  if (version != 1) {
    fprintf(stderr, "GraphPhoto save file `%s` uses an unsported version (%d). This application can only read version 1\n", filename, version);
    return false;
  }  
  printf("version %u\n", version);

  uint32_t num_nodes;
  GET_N_BYTES(num_nodes);
  printf("num_nodes %d\n", num_nodes);

  node *nodes = new node[num_nodes];
  
  for (uint32_t i = 0; i < num_nodes; ++i) {
    GET_N_BYTES(nodes[i]);
  }

  for (uint32_t i = 0; i < num_nodes; ++i) {
    printf("id %d\nx %d\ny %d\n\n", nodes[i].id, nodes[i].x, nodes[i].y);
  }

  
  return true;
}
