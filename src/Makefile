remove_comments:    remove_comments.c
	gcc -o remove_comments remove_comments.c -lfl
remove_comments.c: remove_comments.lex
	lex --outfile="remove_comments.c" remove_comments.lex
