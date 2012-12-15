(* (errors.pas) Este programa gera todos os erros e avisos detecados pelo compilador (listados nas próximas páginas). *)

program Errors; 

var 
 i, ii, i: integer; (* Error *)
 r, rr: real;
 b, bb: boolean;

function test(): integer; (* Error *)
var z : integer;
begin
    i := 10; (* Error *)
end;

function itest(a : integer; b : real; c : boolean): integer ;
begin
    itest := 1;
end;

function rtest(a : integer; b : real; c : boolean): real ;
begin
    rtest := 1.5;
end;

function btest(a : integer; b : real; c : boolean): boolean ;
begin
    btest := true;
end;

begin

    z := 0; (* Error *)

    i := 1;
    i := 1.5; (* Warning *)
    i := true; (* Error *)
    i := i; 
    i := r; (* Warning *)
    i := b; (* Error *)
    i := z; (* Error *)

    r := 1;
    r := 1.5;
    r := true; (* Error *)
    r := i; 
    r := r;
    r := b; (* Error *)

    b := 1; (* Error *)
    b := 1.5; (* Error *)
    b := true;
    b := i; (* Error *)
    b := r; (* Error *)
    b := b;

    i := 1 + 1.5; (* Warning *)
    i := 1 + 1.5 + true; (* Warning, Error *)
    i := i + r + b + z; (* Warning, Error, Error *)

    r := 1 + 1.5;
    r := 1 + 1.5 + true; (* Error *)
    r := i + r + b; (* Error *)

    b := 1 + 1.5; (* Error, Error *)
    b := 1 + 1.5 + true; (* Error, Error *)
    b := i + r + b; (* Error, Error *)

    writeln(i + 1);
    writeln(i + 1.5); (* Warning *)
    writeln(i + true); (* Error *)
    writeln(i + i);
    writeln(i + r); (* Warning *)
    writeln(i + b); (* Error *)
    writeln(i + z); (* Error *)
    writeln(z + i); (* Error *)

    writeln(r + 1);
    writeln(r + 1.5);
    writeln(r + true); (* Error *)
    writeln(r + i);
    writeln(r + r);
    writeln(r + b); (* Error *)
    writeln(r + z); (* Error *)

    writeln(b + 1); (* Error *)
    writeln(b + 1.5); (* Error *)
    writeln(b + true);
    writeln(b + i); (* Error *)
    writeln(b + r); (* Error *)
    writeln(b + b);
    writeln(b + z); (* Error *)

    if i < 1 then writeln('t');
    if i < 1.5 then writeln('t');
    if i < true then writeln('t'); (* Error *)
    if i < i then writeln('t');
    if i < r then writeln('t');
    if i < b then writeln('t'); (* Error *)
    if i < z then writeln('t'); (* Error *)

    if r < 1 then writeln('t');
    if r < 1.5 then writeln('t');
    if r < true then writeln('t'); (* Error *)
    if r < i then writeln('t');
    if r < r then writeln('t');
    if r < b then writeln('t'); (* Error *)
    if r < z then writeln('t'); (* Error *)

    if b < 1 then writeln('t'); (* Error *)
    if b < 1.5 then writeln('t'); (* Error *)
    if b < true then writeln('t');
    if b < i then writeln('t'); (* Error *)
    if b < r then writeln('t'); (* Error *)
    if b < b then writeln('t');
    if b < z then writeln('t'); (* Error *)

    i := itest(1, 1.5, true);
    i := rtest(1, 1.5, true); (* Warning, Warning *)
    i := btest(1, 1.5, true); (* Error *)

    r := itest(1, 1.5, true);
    r := rtest(1, 1.5, true);
    r := btest(1, 1.5, true); (* Error *)

    b := itest(1, 1.5, true); (* Error *)
    b := rtest(1, 1.5, true); (* Error *)
    b := btest(1, 1.5, true);

    i := itest(1.5, true); (* Error, Error *)
    r := rtest(1, true); (* Error, Error *)
    b := btest(1, 1.5); (* Error *)

end.
