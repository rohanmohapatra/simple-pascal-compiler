program hello;
uses crt;
type
   uReal = real;
   uString = string;
   uInteger = integer;
{* Here the main program block starts *}
var
   a : integer;
begin
   writeln("What");
   a:=100;
   if (a=100) then 
      writeln("Value of a is 10");

   else if ( a = 20 ) then
      writeln("Value of a is 20");

   else if( a <= 30 ) then 
      writeln("Value of a is 30");
   
   else
      writeln("None of the values is matching");
      
   writeln("Exact value of a is: ");
end.