#include "ast_handle.h"
#include "symbol_table.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define COUNT 5
void padding ( char ch, int n ){
  int i;
  if(ch == 45){
    for ( i = 0; i < n*COUNT; i++ )
    printf ( "%c", ch );
  }
  else {
    for ( i = 0; i < n; i++ )
    printf ( "%c", ch );
  }
}
/*
void structure ( struct node *root, int level ){
  int i;
  
  if ( root == NULL ) {
    padding ( '\t', level );
    puts ( "~" );
  } else {
    structure ( root->right, level + 1 );
    padding ( '\t', level );
    printf ( "%d\n", root->node_type );
    structure ( root->left, level + 1 );
  }
}

void print_tree(struct ast_node *root) {
  structure(root,0);
}
*/
void print_tree(struct ast_node *root) {
  print_initial_tree(root,0);
}

void print_initial_tree(struct ast_node *root,int level){
  if(root == NULL)
    return;
  switch(root->node_type){
    case 'R': {
                  struct ast_root_node *node = (struct ast_root_node*) root;
                  print_initial_tree(node->block_node,level+1);
                  padding ( 45, level );
                  printf ( "%s\n", "Root" );
                  print_initial_tree(node->program_node,level+1);
                  
                  break;
                }
    case 'P': {
                  struct ast_program_node *node = (struct ast_program_node*) root;
                  padding ( 45, level );
                  printf ( "%s", "Program" );
                  padding ( 45, level );
                  printf ( "%s\n", node->program_name );
                  break;
                }
    case 'B': {
                  struct ast_block_node *node = (struct ast_block_node*) root;
                  print_initial_tree(node->execution_node,level+1);
                  print_initial_tree(node->uses_node,level+1);
//		  print_initial_tree(node->variable_node, level+1);
		  print_initial_tree(node->func_proc_list_node, level+1);
                  padding ( 45, level );
                  printf ( "%s \n", "Block");
                  break;
                }    
    case 'U': {
                  struct ast_uses_node *node = (struct ast_uses_node*) root;
                  
                  for (int i = 0; i <= node->n_packages; ++i)
                  {
                    padding ('\t', level);
                    padding ( 45, level );
                    printf("%s\n",node->package_names[i] );
                  }
                  printf("\n");
                  padding ( 45, level );
                  printf ( "%s", "Uses" );
                  printf("\n");
                  break;
                }
    case 'E': {
                  struct ast_exec_body_node *node = (struct ast_exec_body_node*) root;
                  print_initial_tree(node->stmts,level+1);
                  print_initial_tree(node->exec_body,level);
                  //padding ( 45, level );
                  //printf("%s\n","Execution" );
                  break;
              }
    case 'I': {
                  struct ast_if_node *node = (struct ast_if_node*) root;
                  //print_initial_tree(node->condition,level+1);
                  //printf("%s\n","If Else1" );
                  print_initial_tree(node->else_branch,level+1);
                  padding ('\t', level);
                  padding ( 45, level );
                  printf("%s\n","Else" );
                  print_initial_tree(node->if_branch,level+1);
                  //printf("%s\n","If Else2" );
                  
                  padding ('\t', level);
                  padding ( 45, level );
                  printf("%s\n","If" );
                  break;
              }
    case 170: {

                struct ast_write_node *node = (struct ast_write_node*) root;
                padding ('\t', level-1);
                padding ( 45, level );
                printf("Write:%s\n",node->string );
                break;
              }  
    case 'W': {
                  struct ast_while_node *node = (struct ast_while_node*) root;
                  print_initial_tree(node->while_branch,level+1);
                  padding ('\t', level);
                  padding ( 45, level );
                  printf("%s\n","While" );
                  break;
              }
    case ('A'+'S'): {
                  struct ast_assignment_stmts_node *node = (struct ast_assignment_stmts_node*) root;
                  
                 //printf("%s\n","Assignment Statements" );
                  print_initial_tree(node->assignment_stmts_node,level);
                  print_initial_tree(node->assignment_node,level+1);
                  break;
              }
    case 'A':  {
                  struct ast_assignment_node *node = (struct ast_assignment_node*) root;
                  
                  padding ('\t', level);
                  padding ( 45, level );
                  char *var = strtok(node->symbol->var_name,"$");
                  printf("Variable Name: %s\n",var );
                  padding ('\t', level);
                  padding ( 45, level );
                  printf("%s\n","Assignment" );
                  print_initial_tree(node->value,level+1);
                  break;
              }
    case 'N': {
                struct ast_number_node *node = (struct ast_number_node *) root;
                padding ('\t', level);
                padding ( 45, level );
                printf("Value : %d\n",node->value);
                break;
              }
    case 'S': {
                struct ast_symbol_reference_node *node = (struct ast_symbol_reference_node *) root;
                padding ('\t', level);
                padding ( 45, level );
                char *var = strtok(node->symbol->var_name,"$");
                printf("%s\n",var);
                break;
              }
	     
    case 'F'+'P': {
			struct ast_func_or_proc_node *node = (struct ast_func_or_proc_node *) root;
		  	padding('\t', level);
                  	padding ( 45, level );
			printf("Function/Procedure Name: %s\n", node->func_or_proc_name);
			print_initial_tree(node->exec_body, level+1);
		  }
    case 'F'+'P'+'B': {
		struct ast_func_proc_list_node* node = (struct ast_func_proc_list_node *) root;
		for(int i = 0; i < node->n_func_proc; ++i){
 			print_initial_tree((struct ast_node *)node->func_or_proc_node_list[i], level+1);
		}
		break;
		}
    default :  {
                print_initial_tree(root->right,level+1);
                padding ('\t', level);
                padding ( 45, level );
                printf("  %c\n",root->node_type );
                print_initial_tree(root->left,level+1);
              }
    
  }
}

struct ast_node *new_ast_root_node (
  struct ast_node *program_node,
  struct ast_node *block_node)
{
  struct ast_root_node *ast_node;
  ast_node = (struct ast_root_node*) malloc(sizeof(struct ast_root_node));

  ast_node->node_type = 'R';
  ast_node->program_node = program_node;
  ast_node->block_node = block_node;
  return (struct ast_node *) ast_node;
}


struct ast_node *new_ast_block_node (
  struct ast_node *uses_node,
  struct ast_node *constant_node,
  struct ast_node *type_node,
  struct ast_node *variable_node,
  struct ast_node *func_proc_list_node,
  struct ast_node *execution_node)
{
  struct ast_block_node *ast_node;
  ast_node = (struct ast_block_node*) malloc(sizeof(struct ast_block_node));
  //printf("Hey I am here %p\n", func_proc_list_node);
  ast_node->node_type = 'B';
  ast_node->uses_node = uses_node;
  ast_node->constant_node = constant_node;
  ast_node->type_node = type_node;
  ast_node->variable_node = variable_node;
  ast_node->func_proc_list_node =  func_proc_list_node;
  ast_node->execution_node = execution_node;

  return (struct ast_node*) ast_node;
}

struct ast_node *new_ast_program_node (
  char* program_name)
{
  struct ast_program_node *ast_node;
  ast_node = (struct ast_program_node*) malloc(sizeof(struct ast_program_node));
  ast_node ->node_type = 'P';
  char *new_name = malloc(strlen(program_name)+1);
  strcpy(new_name,program_name);
  ast_node->program_name = new_name;
  return (struct ast_node*) ast_node;
}

struct ast_node *new_ast_uses_node (
  int n_args,
  char **package_names){
  struct ast_uses_node *ast_node;
  ast_node = (struct ast_uses_node*) malloc(sizeof(struct ast_uses_node));
  ast_node->node_type = 'U';
  ast_node->package_names = package_names;
  ast_node->n_packages = n_args;
  for (int i = 0; i <= n_args; ++i)
  {
    //printf("%s\n",package_names[i] );
  }
  return (struct ast_node*) ast_node;
}

struct ast_node *
new_ast_if_node (struct ast_node * condition,
                 struct ast_node * if_branch,
                 struct ast_node * else_branch)
{
  struct ast_if_node * ast_node = malloc (sizeof (struct ast_if_node));

  ast_node->node_type = 'I';

  ast_node->condition = condition;
  ast_node->if_branch = if_branch;
  ast_node->else_branch = else_branch;
  
  return (struct ast_node *) ast_node;
}

struct ast_node *new_ast_structured_stmts_node (
  struct ast_node *conditional_stmts,
  struct ast_node *repetitive_stmts)
{
  struct ast_structured_stmts_node * ast_node = malloc (sizeof (struct ast_structured_stmts_node));
  ast_node->node_type = 'S' + 'S';
  ast_node->conditional_stmts = conditional_stmts;
  ast_node->repetitive_stmts = repetitive_stmts;

  return (struct ast_node *) ast_node;
}

struct ast_node *new_ast_exec_body_node (
  struct ast_node *exec_body,
  struct ast_node *stmts)
{
  struct ast_exec_body_node * ast_node = malloc (sizeof (struct ast_exec_body_node));
  ast_node->node_type = 'E';
  ast_node->exec_body = exec_body;
  ast_node->stmts = stmts;

  return (struct ast_node *) ast_node;
}

struct ast_node *new_ast_write_node (
  char * string){
  struct ast_write_node *ast_node = malloc(sizeof(struct ast_write_node));
  ast_node->node_type = 170;//'W' + 'S';
  char *new_name = malloc(strlen(string)+1);
  strcpy(new_name,string);
  ast_node->string = new_name;
}

struct ast_node *new_ast_while_node (struct ast_node * condition,
                 struct ast_node * while_branch)
{
  struct ast_while_node * ast_node = malloc (sizeof (struct ast_while_node));

  ast_node->node_type = 'W';

  ast_node->condition = condition;
  ast_node->while_branch = while_branch;
  
  return (struct ast_node *) ast_node;
}

struct ast_node *new_ast_assignment_stmts_node(
  struct ast_node *assignment_node,
  struct ast_node *assignment_stmts_node)
{
  struct ast_assignment_stmts_node * ast_node = malloc(sizeof(struct ast_assignment_stmts_node));

  ast_node->node_type = 'A' + 'S';
  ast_node->assignment_node = assignment_node;
  ast_node->assignment_stmts_node = assignment_stmts_node;

  return (struct ast_node *) ast_node;
}

struct ast_node *new_ast_assignment_node(
  struct symbol_table *symbol,
  struct ast_node *value)
{
  struct ast_assignment_node * ast_node = malloc(sizeof(struct ast_assignment_node));

  ast_node->node_type = 'A';
  ast_node->symbol = symbol;
  ast_node->value = value;
}

struct ast_node * new_ast_node (
  char* node_type,
  struct ast_node * left,
  struct ast_node * right)
{
  struct ast_node * ast_node = malloc (sizeof (struct ast_node));

  ast_node->node_type = node_type[0];

  ast_node->left = left;
  ast_node->right = right;

  return ast_node;
}

struct ast_node *new_ast_number_node (int value)
{
  struct ast_number_node * ast_node = malloc (sizeof (struct ast_number_node));

  ast_node->node_type = 'N';

  ast_node->value = value;

  return (struct ast_node *) ast_node;
}
struct ast_node *new_ast_symbol_reference_node (struct symbol_table * symbol)
{
  struct ast_symbol_reference_node * ast_node =malloc (sizeof (struct ast_symbol_reference_node));

  ast_node->node_type = 'S';

  ast_node->symbol = symbol;

  return (struct ast_node *) ast_node;
}
struct ast_node *new_ast_func_proc_list_node (int ast_func_or_proc_list_top, struct ast_func_or_proc_node** ast_func_or_proc_node_list)
{
  struct ast_func_proc_list_node* ast_node = malloc(sizeof(struct ast_func_proc_list_node));
  //printf("HEY I AM HERE\n");
  for(int i = 0; i <= ast_func_or_proc_list_top; ++i)
  {
    printf("%s\n", ast_func_or_proc_node_list[i]->func_or_proc_name);
    ast_node->func_or_proc_node_list[i] =  ast_func_or_proc_node_list[i];
    //printf(" In Function with Name =%s\n",ast_func_or_proc_node_list[i]->func_or_proc_name );
  }
  ast_node->node_type = 'F'+'P'+'B';
  ast_node->n_func_proc = ast_func_or_proc_list_top+1;
  return (struct ast_node *) ast_node;
}

struct ast_node* new_ast_func_or_proc_node (char* func_or_proc_name)
{
  struct ast_func_or_proc_node* ast_node = malloc (sizeof(struct ast_func_or_proc_node));

  ast_node->node_type = 'F'+'P';

  ast_node->func_or_proc_name = strdup(func_or_proc_name);

  return (struct ast_node* ) ast_node;
}
