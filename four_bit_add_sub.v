`include "four_bit_adder.v"
module four_bit_add_sub(
input [3:0]a,
input [3:0]b,
input cin,
output [3:0]s,
output cout
);

wire [3:1]x;
wire [3:0]bmod;
assign bmod=b^{4{cin}};

four_bit_adder stage0(a,bmod,cin,s,cout);

endmodule

