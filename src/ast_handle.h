
/* All Definations to be Added Here
node_type : Stores the type of the node , eg: +,-,/ etc
left :Left Child of Node
right :Right Child of Node
*/

struct ast_node // for binary/unary operators and expression lists
{
  int node_type;

  struct ast_node * left;

  struct ast_node * right;
};

struct ast_root_node // for Root Node
{
  int node_type;

  struct ast_node *program_node;

  struct ast_node *block_node;
};

struct ast_block_node // for Block Node
{
  int node_type;

  struct ast_node *uses_node;

  struct ast_node *constant_node;

  struct ast_node *type_node;

  struct ast_node *variable_node;

  struct ast_node *function_node;

  struct ast_node *procedure_node;

  struct ast_node *execution_node;
};

struct ast_program_node // for Root Node
{
  int node_type;

  char* program_name;
};

struct ast_uses_node // for Root Node
{
  int node_type;

  char** package_names;

  int n_packages;
};
struct ast_structured_stmts_node
{
  int node_type;

  struct ast_node * conditional_stmts;

  struct ast_node * repetitive_stmts;
};

struct ast_exec_body_node
{
  int node_type;

  struct ast_node * exec_body;

  struct ast_node * stmts;
};

struct ast_if_node // for "if/else" statements
{
  int node_type;

  struct ast_node * condition;

  struct ast_node * if_branch;

  struct ast_node * else_branch;
};

struct ast_write_node // for function calls
{
  int node_type;
  
  char* string;
};

struct ast_relational_node // for relational operators
{
  int node_type;

  //enum relational_operator operator; Check this please

  struct ast_node * left;

  struct ast_node * right;
};

struct ast_function_node // for function calls
{
  int node_type;
  // Needs to be filled
};



struct ast_while_node // for "while" statements
{
  int node_type;

  struct ast_node * condition;

  struct ast_node * while_branch;
};


struct ast_assignment_stmts_node // for assignment statements
{
  int node_type;

  struct ast_node * assignment_node;

  struct ast_node * assignment_stmts_node;
};

struct ast_assignment_node // for assignment expressions
{
  int node_type;

  struct symbol_table * symbol;

  struct ast_node * value;
};

struct ast_number_node // for constant integer numbers
{
  int node_type;

  int value;
};

struct ast_symbol_reference_node // for symbol references
{
  int node_type;

  struct symbol_table * symbol;
};

void print_initial_tree(struct ast_node *root,int level);
void print_tree(struct ast_node *root);

struct ast_node *new_ast_root_node (
  struct ast_node *program_node,
  struct ast_node *block_node);

struct ast_node *new_ast_block_node (
  struct ast_node *uses_node,
  struct ast_node *constant_node,
  struct ast_node *type_node,
  struct ast_node *variable_node,
  struct ast_node *function_node,
  struct ast_node *procedure_node,
  struct ast_node *execution_node);

struct ast_node *new_ast_program_node (
  char* program_name);

struct ast_node *new_ast_uses_node (
  int n_args,
  char **package_names);

struct ast_node *new_ast_if_node (struct ast_node * condition,
                 struct ast_node * if_branch,
                 struct ast_node * else_branch);

struct ast_node *new_ast_structured_stmts_node (
  struct ast_node *conditional_stmts,
  struct ast_node *repetitive_stmts);

struct ast_node *new_ast_exec_body_node (
  struct ast_node *exec_body,
  struct ast_node *stmts);

struct ast_node *new_ast_write_node (
  char * string);

struct ast_node *new_ast_while_node (struct ast_node * condition,
                 struct ast_node * while_branch);

struct ast_node *new_ast_assignment_stmts_node(
  struct ast_node *assignment_node,
  struct ast_node *assignment_stmts_node);

struct ast_node *new_ast_assignment_node(
  struct symbol_table *symbol,
  struct ast_node *value);

struct ast_node * new_ast_node (
  char* node_type,
  struct ast_node * left,
  struct ast_node * right);

struct ast_node *new_ast_number_node (int value);

struct ast_node *new_ast_symbol_reference_node (struct symbol_table * symbol);