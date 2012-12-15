(* (primes.pas) Este programa calcula número primos usando para tal um algortimo que calcula raizes inteiras de um dado número. *)

program Primes; 

var
    i, j, h, k, max: integer;
    isprime: boolean;


function isqrt (n : integer) : integer; (* integer square root *)
var
    k, xa, xo: integer;
    run : boolean;
begin
    xa := 0;
    xo := n;
    run := true;

    while run do
    begin
        xa := (xo + (n div xo)) div 2;

        if ((xa >= xo) and ((xa - xo) <= 1)) or ((xa < xo) and ((xo - xa) <= 1)) then
            run := false;

        xo := xa;
    end;

    isqrt := xa;
end;

begin

    i := 1;
    max := 20;

    while i <= max do begin
        isprime := true;
        j := 2;
        k := isqrt(i);

        while j <= k do
        begin
            if (i div j) * j = i then
                isprime := false;

            j := j + 1;
        end;

        if isprime then
            writeln(i, ' is prime! (1..', k, ')');

        i := i + 1;
        if i > 3 then (* jump even numbers *)
            i := i + 1;
    end;

end.
