(* (power.pas) Este programa é um exemplo de recursividade utilizada para calcular potências. *)

program Power; 

var a, b, n: integer;

function power(a, b : integer) : integer;
begin
    if b = 1 then
        power := a;
    else
        power := a * power(a, b - 1);
end;

begin

    a := 3;
    b := 6;
    n := power(a, b);
    writeln(a, '^', b, ' = ', n);

end.
