#include "var_type.h"

void clear_variable_type_info(struct variable_type_info *var)
{
	var->is_int = 0;
	var->is_float = 0;
	var->is_bool = 0;
	var->is_str = 0;
}
