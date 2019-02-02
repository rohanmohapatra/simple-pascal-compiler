# ./remove_comments < $1 > $2
#./executable/compiler
if [ -z "$1" ]
then
	echo "Enter your Input to Lex Analyser..."
	./executable/compiler
else
	./executable/compiler "$1"
fi
