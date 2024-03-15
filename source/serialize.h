#include <sstream>
#include <fstream>
#include <cstdint>
#include <cstring>

#include "gpnode.h"

#define GP_FILE_VERSION 1
#define GP_FILE_SIGNATURE "graphphoto"

struct filedata {
  uintmax_t length;
  uintmax_t ix;
  char *data;
};

void save_project(GPNode::NodeEditor *editor);
bool open_project(const char *filename);

// Not using an enum because cpp
#define GP_TYPE_U32 1
#define GP_TYPE_S32 2
#define GP_TYPE_U64 3
#define GP_TYPE_U32 1

enum SF_TYPE : unsigned int {
  U32 = 1,
  S32 = 2,
  U64 = 3,
    S64 = 4,
    STRING = 5,
    NODES_ARRAY = 6,          
};
