(* (fibonacci.pas) Este programa é um exemplo de recursividade utilizada para calcular a sequência de Fibonacci. *)

program Fibonacci; 

var n, f, max: integer;

function fibonacci(n : integer) : integer;
begin
    if n = 0 or n = 1 then
        begin
        fibonacci := n;
        end;
    else
        begin
        fibonacci := fibonacci(n - 1);
        fibonacci := fibonacci + fibonacci(n - 2);
        end;
end;

begin
    max := 20;

    n := 1;
    while n <= max do
    begin
        f := fibonacci(n);
        writeln('fibonacci(', n,') = ', f);
        n := n + 1;
    end;

end.
