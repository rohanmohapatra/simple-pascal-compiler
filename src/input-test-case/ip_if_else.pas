program hello;
uses crt;
type
   uReal = real;
   uString = string;
   uInteger = integer;
{* Here the main program block starts *}
var
   a : integer;
   b : integer;
begin
   writeln("What");
   a:=100;
   if (a<=100) then 
   	a:=10;
   else
     b := -100; 
   writeln("Exact value of a is: ");
end.
