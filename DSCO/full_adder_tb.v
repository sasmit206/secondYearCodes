`timescale 1ns/1ns
`include"full_adder.v"
module full_adder_tb();
reg a,b,cin;
wire s,cout;

full_adder e(a,b,cin,s,cout);

initial begin
	$dumpfile("full_adder.vcd");
	$dumpvars(0,full_adder_tb);
	a=1;b=0;cin=0;#10;
	a=1;b=1;cin=1;#10;
	$finish;
	end
	endmodule


