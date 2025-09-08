`timescale 1ns/1ns 
`include "half_adder.v"
module half_adder_tb();
reg a,b;
wire s,cout;

half_adder e(a,b,s,cout);

initial begin
	$dumpfile("half_adder.vcd");
	$dumpvars(0,half_adder_tb);
	a=1;b=1;
	#10;
	a=0;b=1;
	#10;
end
endmodule
