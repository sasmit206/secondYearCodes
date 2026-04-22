`include "full_adder.v"
module multiplier_2_3_bit(
input [1:0]a,
input [2:0]b,
output [4:0]p
);
wire [2:0]c;
full_adder s0(a[0]&b[0],1'b0,1'b0,p[0],c[0]);
full_adder s1(a[0]&b[1],a[1]&b[0],1'b0,p[1],c[1]);
full_adder s2(a[0]&b[2],a[1]&b[1],c[1],p[2],c[2]);
full_adder s3(a[1]&b[2],1'b0,c[2],p[3],p[4]);
endmodule

