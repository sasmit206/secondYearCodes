`timescale 1ns/1ns
`include "multiplier_2_3_bit.v"
module multiplier_2_3_bit_tb();
reg [1:0]a;
reg [2:0]b;
wire [4:0]p;

multiplier_2_3_bit e(a,b,p);

initial begin
	$dumpfile("multiplier_2_3_bit.vcd");
	$dumpvars(0,multiplier_2_3_bit_tb);
	a=2'b01;
	b=3'b101;
	#10;
	a=2'b10;
	b=3'b111;
	#10;
	$finish;
	end
	endmodule
	

