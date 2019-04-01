compiler:	parser.tab.c parser.tab.h lexer.c
	gcc -g -o executable/compiler parser.tab.c lexer.c -lrt
parser.tab.c:	parser.y
	yacc parser.y -d -b "parser"
parser.tab.h:	parser.y
	yacc parser.y -d -b "parser"
lexer.c:	lexer.lex	
	lex --outfile="lexer.c" lexer.lex
ast_handle.o: ast_handle.c
	gcc -g -c ast_handle.c
var_type.o: var_type.c
	gcc -g -c var_type.c
utils.o: spc/utils.c
	gcc -g -c spc/utils.c
all: ast_handle.o var_type.o utils.o
	lex --outfile="lexer.c" lexer.lex
	yacc parser.y -v -d -b  "parser"	
	gcc -g -o executable/compiler parser.tab.c lexer.c ast_handle.o var_type.o intermediate_code_generation.c utils.o -lrt
clean:
	rm lexer.c;rm parser.tab.c;rm parser.tab.h;rm *.o