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

struct ast_if_node // for "if/else" statements
{
  int node_type;

  struct ast_node * condition;

  struct ast_node * if_branch;

  struct ast_node * else_branch;
};

struct ast_while_node // for "while" statements
{
  int node_type;

  struct ast_node * condition;

  struct ast_node * while_branch;
};

struct ast_assignment_node // for assignment expressions
{
  int node_type;

  struct symbol_node * symbol;

  struct ast_node * value;
};

