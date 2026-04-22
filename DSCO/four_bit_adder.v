`include "full_adder.v"
module four_bit_adder(
input [3:0]a,
input [3:0]b,
input cin,
output [3:0]s,
output cout
);
wire [3:1]x;
full_adder stage0(a[0],b[0],1'b0,s[0],x[1]);
full_adder stage1(a[1],b[1],x[1],s[1],x[2]);
full_adder stage2(a[2],b[2],x[2],s[2],x[3]);
full_adder stage3(a[3],b[3],x[3],s[3],cout);
endmodule


