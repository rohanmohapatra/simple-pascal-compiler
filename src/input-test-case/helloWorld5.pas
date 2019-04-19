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
function max(num1,num2: integer): integer;
var
   {* local variable declaration *}
   result: integer;
   max : integer;
begin
   max := result;
   max :=4+5;
end;

function min(num1,num2: integer): integer;
var
	result : uInteger;
	num3 : integer;
	min : integer;

begin
	min := result;
end;

begin
	z := 1+10;
	for i:= 1 to 10 
	do 
		writeln("Hello");
		x:=4;

	while (x>0) do writeln("While");
	writeln("Hello, World!");
	
	z := z+10;

end. 
