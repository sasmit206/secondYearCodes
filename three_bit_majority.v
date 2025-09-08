`include "mux4to1.v"
module three_bit_majority(
input [2:0]a,
output f
);
mux4to1 m1({1'b1,a[0],a[0],1'b0},{a[2],a[1]},f);
endmodule

