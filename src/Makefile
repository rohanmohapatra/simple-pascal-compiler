compiler:	parser.tab.c parser.tab.h lexer.c
	gcc -g -o executable/compiler parser_icg.tab.c lexer.c -lrt
parser_icg.tab.c:	parser_icg.y
	yacc parser_icg.y -d -b "parser_icg"
parser_icg.tab.h:	parser_icg.y
	yacc parser_icg.y -d -b "parser_icg"
lexer.c:	lexer.lex	
	lex --outfile="lexer.c" lexer.lex
ast_handle.o: ast_handle.c
	gcc -g -c ast_handle.c
var_type.o: var_type.c
	gcc -g -c var_type.c
utils.o: spc/utils.c
	gcc -g -c spc/utils.c
intermediate_code_generation.o:	intermediate_code_generation.c
	gcc -g -c intermediate_code_generation.c
all: ast_handle.o var_type.o utils.o intermediate_code_generation.o
	lex --outfile="lexer.c" lexer.lex
	yacc parser_icg.y -v -d -b  "parser_icg"	
	gcc -g -o executable/compiler parser_icg.tab.c lexer.c ast_handle.o var_type.o intermediate_code_generation.o utils.o -lrt
clean:
	rm lexer.c;rm parser_icg.tab.c;rm parser_icg.tab.h;rm *.o
