`timescale 1ns/1ns
`include "mux2to1.v"
module mux2to1_tb();
reg a;
reg b;
reg s;
wire f;

mux2to1 e(a,b,s,f);

initial begin
	$dumpfile("mux2to1.vcd");
	$dumpvars(0,mux2to1_tb);
	a=1;b=1;s=0;
	#10;
	a=0;b=1;s=0;
	#10;
	a=1;b=1;s=1;
	#10;
	$finish;
end
endmodule
