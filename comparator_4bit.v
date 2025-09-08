module comparator_4bit(
input [3:0]a,
input [3:0]b,
output aeqb,
output agtb,
output altb
);
wire e1,e2,e3,e4;
assign e1=~(a[0]^b[0]);
assign e2=~(a[1]^b[1]);
assign e3=~(a[2]^b[2]);
assign e4=~(a[3]^b[3]);
assign aeqb= e1&e2&e3&e4 ;
assign agtb = (a[3] & ~b[3]) |
              (e4 & a[2] & ~b[2]) |
              (e4 & e3 & a[1] & ~b[1]) |
              (e4 & e3 & e2 & a[0] & ~b[0]);
assign altb=~(aeqb|agtb);

endmodule
