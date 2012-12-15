(* (example.pas) Este programa demostra de um modo geral todo o set da lingaguem aceite pelo compilador. *)

program Example; 

var 
 i1, i2: integer;
 r1, r2: real;
 b1, b2: boolean;


function test(a, b: integer) : integer;
var c, d : integer;
begin
    c := 10;
    d := 10;
    test := a + b + c + d;
end;


function rtest(i : integer; r : real) : real;
begin
    rtest := r + i;
end;


function btest(b : boolean; j : integer; k : real) : boolean;
var
    i : integer;
    r : real;
begin

    i := test(j, j) + test(j, j);
    r := rtest(i, k);
    writeln(i, ' ', r);
    
    if b then
        btest := false;
    else
        btest := true;
end;

begin

    i1 := 10 + 20 div 2;
    i2 := i1 * i1;
    writeln(i1, ' ** 2 = ', i2);

    r1 := 3.1415;
    r2 := r1 * 2;
    writeln(r2, ' = ', r1 * 2.0);

    b1 := true;
    b2 := false;
    b2 := b2;
    writeln(b1, ' <> ', b2);


    if i2 > i1 then
        writeln('i2 > i1');
    else
        writeln('i2 < i1');


    if r2 > r1 then
    begin
        writeln('r2 > r1');
    end;
    else
    begin
        writeln('r2 < r1');
    end;


    i1 := 0;

    while i1 < 3 do
    begin
        writeln('i: ', i1);
        i1 := i1 + 1;
    end;


    i1 := 10;
    i2 := i1;
    i1 := test(i1, i2);
    writeln(i1);

    i1 := 10;
    r1 := 10.5;
    r1 := rtest(i1, r1);
    writeln(r1);

    b1 := true;
    b2 := btest(b1, 10, 2.0);
    writeln(b2);

end.
