`include "mux2to1.v"
module mux4to1(
input [3:0]d,
input [1:0]s,
output f
);
wire f1,f2;
mux2to1 e1(d[3],d[2],s[0],f1);
mux2to1 e2(d[1],d[0],s[0],f2);
mux2to1 e(f1,f2,s[1],f);
endmodule

