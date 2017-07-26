program uzbraukt;
{2012 gads 10.marts autors: Edgars Francis}
var n,i,up,down,level:integer;
    mas:array [1..30001] of integer;
    errcode:integer;
    f:text;
    up_flag, down_flag, level_flag:boolean;
begin
assign(f,'uzbraukt.dat');
reset(f);
readln(f,n);
for i:=1 to n do begin
    readln(f,mas[i]);
end;
mas[n+1]:=mas[1];
close(f);

up_flag:=false; down_flag:=false; level_flag:=false;
for i:=2 to n + 1 do begin
if((mas[i-1] < mas[i]) and (up_flag=false)) then begin
   up_flag := true; down_flag:= false; level_flag:= false;
   up:=up+1;
end
else if((mas[i-1] > mas[i]) AND (down_flag<>true)) then begin
   up_flag:=false; down_flag:=true; level_flag:=false;
   down:=down+1;
end
else if((mas[i-1] = mas[i]) AND (level_flag<>true)) then begin
   up_flag:=false; down_flag:=false; level_flag:=true;
   level:=level+1;
end;
end;

assign(f,'uzbraukt.rez');
rewrite(f);
writeln(f,up,down,level);
close(f);
end.
