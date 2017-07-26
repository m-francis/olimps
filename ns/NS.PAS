program ns;
var f:text;
    i,j,code,summa,cipars:integer;
    rezultats,cip:string;
	skaitli: array[1..8] of string;
begin
assign(f,'ns.dat');
reset(f);
for i:=1 to 8 do
readln(f,skaitli[i]);
close(f);

rezultats:='';

for i:=1 to length(skaitli[1]) do begin
	summa:=0;
	for j:=1 to 8 do begin
		VAL(skaitli[j][i],cipars,code);
		summa:=summa + cipars;
	end;
	cipars:= 45 - summa;
	str(cipars,cip);
	rezultats:=rezultats + cip; 
end;


assign(f,'ns.rez');
rewrite(f);
writeln(f,rezultats);
close(f);
end.