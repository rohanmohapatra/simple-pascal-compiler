compiler:	parser.tab.c parser.tab.h lexer.c
	gcc -o executable/compiler parser.tab.c lexer.c -lrt
parser.tab.c:	parser.y
	yacc parser.y -d -b "parser"
parser.tab.h:	parser.y
	yacc parser.y -d -b "parser"
lexer.c:	lexer.lex	
	lex --outfile="lexer.c" lexer.lex
all:
	lex --outfile="lexer.c" lexer.lex
	yacc parser.y -d -b "parser"	
	gcc -o executable/compiler parser.tab.c lexer.c -lrt
	lex --outfile="lexer.c" lexer.lex