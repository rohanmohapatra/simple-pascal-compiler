program hello;
uses crt;
type
	uReal = real;
	uString = string;
	uInteger = integer;
{* Here the main program block starts *}
var
	i : integer;
	x : integer;
	y : array [9...25] of boolean;
	z : uInteger;
	a : string;

begin
	z := 1+10;
	for i:= 1 to 10 
	do 
		writeln("Hello");
		x:=4;

	while (x>0) do x:=5;
	writeln("Hello, World!");
	
	z := z+10;

end. 