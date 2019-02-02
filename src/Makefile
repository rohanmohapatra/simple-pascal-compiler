compiler:	parser.tab.c parser.tab.h lexer.c
	gcc -o executable/compiler parser.tab.c lexer.c
parser.tab.c:	parser.y
	yacc parser.y -d -b "parser"
parser.tab.h:	parser.y
	yacc parser.y -d -b "parser"	
lexer.c:	lexer.lex	
	lex --outfile="lexer.c" lexer.lex
remove_comments:    remove_comments.c
	gcc -o remove_comments remove_comments.c -lfl
remove_comments.c: remove_comments.lex
	lex --outfile="remove_comments.c" remove_comments.lex