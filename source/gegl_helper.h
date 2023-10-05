#pragma once
#include <gegl.h>
#include <gegl-plugin.h>
#include <map>
#include <vector>

// Degug libs
#include <string>

// GEGL makes you create an instance of an operation if you want to see what pads it has,
// so instead we'll just load the operations once and cache the info.
// There might be a way to get it from the GeglOperationClass, but GObject is such an insane,
// inscrutable system that I've already wasted enough time trying to untangle. The most prudent
// option is to Cut The Gordian Knot.
struct node_io {
  uint8_t io;
  GeglOperationClass *klass;
};

struct node_category {
  uint8_t io;
  std::vector<node_io> operations;
};

int initialize_gegl();
void test_operation(const char *operation);

extern std::vector<node_io> node_info;
extern std::map<std::string, node_category> categories;

