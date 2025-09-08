`timescale 1ns/1ns
`include"mux4to1.v"
module mux4to1_tb();
reg [3:0]d;
reg [1:0]s;
wire f;

mux4to1 e(d,s,f);

initial begin
	$dumpfile("mux4to1.vcd");
	$dumpvars(0,mux4to1_tb);
	d=1011;
	s=10;
	#10;
	d=1111;
	s=00;
	#10;
	d=1001;
	s=01;
	#10;
	$finish;
end 
endmodule


