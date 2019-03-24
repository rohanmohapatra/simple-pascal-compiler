#include "ast_handle.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define COUNT 5
void padding ( char ch, int n ){
  int i;
  for ( i = 0; i < n*COUNT; i++ )
    printf ( "%c", ch );
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
                  print_initial_tree(node->uses_node,level+1);
                  padding ( 45, level );
                  printf ( "%s\n", "Block" );
                  break;
                }    
    case 'U': {
                  struct ast_uses_node *node = (struct ast_uses_node*) root;
                  padding ( 45, level );
                  printf ( "%s", "Uses" );
                  for (int i = 0; i <= node->n_packages; ++i)
                  {
                    padding ( 45, level );
                    printf("%s",node->package_names[i] );
                  }
                  printf("\n");
                  break;
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
  struct ast_node *function_node,
  struct ast_node *procedure_node,
  struct ast_node *execution_node)
{
  struct ast_block_node *ast_node;
  ast_node = (struct ast_block_node*) malloc(sizeof(struct ast_block_node));

  ast_node->node_type = 'B';
  ast_node->uses_node = uses_node;
  ast_node->constant_node = constant_node;
  ast_node->type_node = type_node;
  ast_node->variable_node = variable_node;
  ast_node->function_node =  function_node;
  ast_node->procedure_node = procedure_node;
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