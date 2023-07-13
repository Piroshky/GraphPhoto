
#include <gegl.h>

struct ui_node {
  GeglNode *node; 
  GeglOperationClass *klass;
};

ui_node gp_create_gegl_node(GeglOperationClass *klass) {
  GeglNode *gegl_node = gegl_node_new_child(graph, "operation", klass->name, NULL);
  ui_node node = {gegl_node, klass};
  return node;
}
