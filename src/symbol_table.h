#include "../uthash/src/uthash.h"
union data {
		int int_value;
		float float_value;
		char string_value[256];
};

	struct symbol_table {
		char var_name[31]; //Holds the Name of the Identifier
		// struct var_info var;
		// YYLTYPE var_decl_loc;
		char type[10]; //Holds the DataType of Identifier
		char *scope_level;
		//int current_size; //Size of the Symbol Table
		int line_no;
		int col_no;
		union data var_value;
		UT_hash_handle hh; //Hash Structure for Optimized Access
};