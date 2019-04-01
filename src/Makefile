compiler:	parser.tab.c parser.tab.h lexer.c
	gcc -g -o executable/compiler parser.tab.c lexer.c -lrt
parser.tab.c:	parser.y
	yacc parser.y -d -b "parser"
parser.tab.h:	parser.y
	yacc parser.y -d -b "parser"
lexer.c:	lexer.lex	
	lex --outfile="lexer.c" lexer.lex
all:
	lex --outfile="lexer.c" lexer.lex
	yacc parser.y -v -d -b  "parser"	
	gcc -g -o executable/compiler parser.tab.c lexer.c ast_handle.c var_type.c intermediate_code_generation.c -lrt
clean:
	rm lexer.c
	rm parser.tab.c
	rm parser.tab.h