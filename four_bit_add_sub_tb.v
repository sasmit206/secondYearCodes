`timescale 1ns/1ns
`include "four_bit_add_sub.v"

module four_bit_add_sub_tb();
    reg [3:0] a;
    reg [3:0] b;
    reg cin;              
    wire [3:0] s;
    wire cout;

    four_bit_add_sub dut(a, b, cin, s, cout);

    initial begin
        $dumpfile("four_bit_add_sub.vcd");
        $dumpvars(0, four_bit_add_sub_tb);

        cin = 0; a = 5; b = 3; #10;
        cin = 0; a = 9; b = 6; #10; 

        cin = 1; a = 9; b = 4; #10; 
        cin = 1; a = 7; b = 10; #10;

        $finish;
    end
endmodule

