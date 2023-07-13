#include "gegl_helper.h"

#define HAS_INPUT_PAD       (1<<0)  
#define HAS_OUTPUT_PAD      (1<<1)  
#define HAS_INPUT_PROPERTY  (1<<2) 
#define HAS_OUTPUT_PROPERTY (1<<3)



std::vector<node_io> node_info;
std::map<std::string, node_category> categories;

// gets a list of the GEGL operations
static GList * gegl_operations_build(GList *list, GType type) {
  GeglOperationClass *klass;
  GType *ops;
  guint  children;
  
  if (!type) {
    return list;
  }
  // g_print("%s\n", g_type_name(type));
  
  klass = (GeglOperationClass*)g_type_class_ref (type);
  if (klass->name != NULL) {
    list = g_list_prepend (list, klass);
    // g_print("\t%s\n", klass->name);

    unsigned int n_properties;
    GParamSpec **properties = g_object_class_list_properties((GObjectClass*) klass, &n_properties);
    // for (unsigned int i = 0; i < n_properties; ++i) {
    //   g_print("\t\t%s\n", g_param_spec_get_name(properties[i]));
      
    // }

    //   g_print("\t\t--- Properties\n");
    //   unsigned int n_properties;
    //   auto properties = gegl_operation_list_properties(operations[i], &n_properties);      
  }

  ops = g_type_children (type, &children);

  for (guint no=0; no<children; no++) {
    list = gegl_operations_build (list, ops[no]);
  }
  if (ops)
    g_free (ops);
  return list;
}

GeglNode *graph;
int initialize_gegl() {

  gegl_init(nullptr, nullptr);
  // g_object_set (gegl_config (),
  // 		"application-license", "GPL3",
  // 		NULL);
  graph = gegl_node_new();

  GList *operations = NULL;
  operations = gegl_operations_build(NULL, GEGL_TYPE_OPERATION);
  
  for (GList *iter=operations; iter; iter=g_list_next(iter)) {
    GeglOperationClass *klass = (GeglOperationClass*) iter->data;
    uint8_t io = 0;

    unsigned int n_properties;
    GParamSpec **properties = g_object_class_list_properties((GObjectClass*) klass, &n_properties);
    if (n_properties > 0) {
      io |= HAS_INPUT_PROPERTY;      
    }
    
    // const char *title = gegl_operation_class_get_key(klass, "title");
    {
      GeglNode *node = gegl_node_new_child(graph, "operation", klass->name, NULL);
            
      char **input_pads  = gegl_node_list_input_pads(node);
      if (input_pads != NULL && *input_pads != 0) {
	io |= HAS_INPUT_PAD;
      }
      g_strfreev(input_pads);
    
      char **output_pads = gegl_node_list_output_pads(node);    
      if (output_pads != NULL && *output_pads != 0) {
	io |= HAS_OUTPUT_PAD;
      }
      g_strfreev(output_pads);
    
      g_object_unref(node);
    }

    // printf("%s\n", klass->name);
    const char *categories_string = gegl_operation_class_get_key(klass, "categories");
    const char *title = gegl_operation_class_get_key(klass, "title");
    // if (title) {
    //   printf("%s\n", title);
    // } else {
    //   printf("no title\n");
    // }

    const char *description = gegl_operation_class_get_key (klass, "description");
    // if (title) {
    //   printf("%s\n", description);
    // } else {
    //   printf("no description\n");
    // }        
    
    const char *ptr = categories_string;
    while (ptr && *ptr) {
      gchar category[64]="";
      gint i=0;
      while (*ptr && *ptr!=':' && i<63) {
	category[i++]=*(ptr++);
	category[i]='\0';
      }
      if (*ptr==':') {ptr++;}

      node_io info = {io, klass};
      
      if (categories.count(category) > 0) {
	// printf("already contains %s\n", category);
	auto& ref = categories[category];
	ref.io |= io;
	ref.operations.push_back(info);

	// printf("op len %ld\n", ref.operations.size());
	
      } else {
	// printf("adding %s\n", category);
	struct node_category s = {io, {info}};	
	categories.insert(std::make_pair((char *)category, s));
      }

      // printf("\t%s\n", category);
    }
  }

  // printf("---Categories---/n");
  // for (auto c : categories) {
  //   printf("%s ~ %d :", c.first.c_str(), c.second.io);

  //   for (auto op : c.second.operations) {
  //     printf(" %s", op.klass->name);
      
  //   }
  //   printf("\n\n");
  // }
  
  // unsigned int n_operations;
  // auto operations = gegl_list_operations(&n_operations );
  // g_print("Available operations:\n");
  // for(unsigned int i=0; i < n_operations; i++) {
  //   g_print("\t%s\n", operations[i]);

  //   g_print("\t\t--- Properties\n");
  //   unsigned int n_properties;
  //   auto properties = gegl_operation_list_properties(operations[i], &n_properties);
    
  //   for (unsigned int j = 0; j < n_properties; ++j) {
  //     g_print("\t\t%s\n",g_param_spec_get_name(properties[j]));
  //   }

  //   GeglNode *node = gegl_node_new_child(graph, "operation", operations[i], NULL);
  //   GType instance_gtype = G_TYPE_FROM_INSTANCE(node);
  //   g_print("\tinstance gtype name: %s\n", g_type_name(instance_gtype));

  //   GValue operation_gvalue = G_VALUE_INIT;
  //   g_object_get_property((GObject*) node, "operation", &operation_gvalue);
  //   GType gvalue_gtype = G_VALUE_TYPE(&operation_gvalue);
  //   g_print("\tgvalue gtype name: %s\n", g_type_name(gvalue_gtype));
  //   g_print("\tdegug: %s", g_strdup_value_contents(&operation_gvalue));
    
  //   // const gchar *operation_type_name = g_strdup_printf("GeglOperation%s", operations[i]);
  //   // g_print("\toperation_type_name %s\n", operation_type_name);
  //   // GType operation_g_type = g_type_from_name(&operation_type_name);
  //   //GeglOperationClass *operation_class = (GeglOperationClass*) g_type_class_ref(operation_g_type);
    

  //   gchar **input_pads = gegl_node_list_input_pads(node);
  //   g_print("\t\t--- Input Pads\n");
  //   for (char **c = input_pads; c != NULL && *c != 0; ++c) {
  //     g_print("\t\t%s\n", *c);
  //   }

    
  //   gchar **output_pads = gegl_node_list_output_pads(node);
  //   g_print("\t\t--- Output Pads\n");
  //   for (char **c = output_pads; c != NULL && *c != 0; ++c) {
  //     g_print("\t\t%s\n", *c);
  //   }

  // }
  // g_free(operations);
  
  return 0;
}
