`include "three_bit_majority.v"
`timescale 1ns/1ns
module three_bit_majority_tb();
reg [2:0]a;
wire f;

three_bit_majority e(a,f);

initial begin
	$dumpfile("three_bit_majority.vcd");
	$dumpvars(0,three_bit_majority_tb);
        a = 3'b000; #10;
        a = 3'b001; #10;
        a = 3'b010; #10;
        a = 3'b011; #10;
        a = 3'b100; #10;
        a = 3'b101; #10;
        a = 3'b110; #10;
        a = 3'b111; #10;
end
endmodule
        

