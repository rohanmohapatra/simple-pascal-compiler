#define MAX_VAR 20

struct var_node_info {
	char **new_vars;
	int var_name_stack_top;
	char *data_type;
};

struct var_node_info var_node_stack[20];
int var_node_stack_top = -1;