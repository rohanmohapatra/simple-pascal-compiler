#define MAX_TYPE 20

struct type_node_info {
	char **new_types;
	int type_identifier_top;
	char *actual_type;
};

struct type_node_info type_node_stack[20];
int type_node_stack_top = -1;