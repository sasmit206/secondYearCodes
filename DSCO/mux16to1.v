`include "mux8to1.v"
`include "mux2to1.v"
module mux16to1(
input [15:0]d,
input [3:0]s,
output f
);

wire [1:0]x;
mux8to1 e1(d[7:0],s[2:0],x[0]);
mux8to1 e2(d[15:8],s[2:0],x[1]);
mux2to1 e(x[0],x[1],s[3],f);
endmodule
