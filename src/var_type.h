struct variable_type_info{
	int is_int;
	int is_float;
	int is_bool;
	int is_str;
};

void clear_variable_type_info(struct variable_type_info *var);

void set_variable_to_int(char **assignment_name_stack,int assignment_name_stack_top, int int_value,char* curr_scope_level);
void set_variable_to_float(char **assignment_name_stack,int assignment_name_stack_top, float float_value,char* curr_scope_level);
void set_variable_to_string(char **assignment_name_stack,int assignment_name_stack_top, char *string_value,char* curr_scope_level);