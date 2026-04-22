`timescale 1ns/1ns
`include "comparator_4bit.v"
module comparator_4bit_tb();
reg [3:0]a;
reg [3:0]b;
wire aeqb;
wire agtb;
wire altb;

comparator_4bit e(a,b,aeqb,agtb,altb);

initial begin
	$dumpfile("comparator_4bit.vcd");
	$dumpvars(0,comparator_4bit_tb);
	a=5;b=7;
	#10;
	a=9;b=9;
	#10;
	a=3;b=2;
	#10;
	end
	endmodule
	
