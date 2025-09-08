module mux4to1_c(
input [3:0]d,
input  [1:0]s,
output f
);
assign f=s[0]?(s[1]?d[3]:d[1]):(s[1]?s[2]:s[0]);
endmodule
