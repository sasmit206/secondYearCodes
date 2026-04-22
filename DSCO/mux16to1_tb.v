`timescale 1ns/1ns
`include "mux16to1.v"
module mux16to1_tb();

reg [15:0]d;
reg [3:0]s;
wire f;

mux16to1 e(d,s,f);

initial begin
	$dumpfile("mux16to1.vcd");
	$dumpvars(0,mux16to1_tb);
	d=16'b1010_1000_0101_0001;
	s=4'b1010;
	#10;
	d=16'b1011_1100_0111_0001;
	s=4'b1000;
	#10;
	for (integer i = 0; i < 16; i = i + 1) begin
        s = i;
        #10;
    	end
    
	$finish;
	end
	endmodule
