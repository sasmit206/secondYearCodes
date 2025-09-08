`timescale 1ns/1ns
`include"four_bit_adder.v"
module four_bit_adder_tb();
reg [3:0]a;
reg[3:0]b;
wire [3:0]s;
wire cout;

four_bit_adder e(a,b,s,cout);

initial begin
	$dumpfile("four_bit_adder.vcd");
	$dumpvars(0,four_bit_adder_tb);
	a=4'b0100;
	b=4'b1010;
	#10;
	a=9;
	b=8;
	#10;
	$finish;
	end
	endmodule
	
