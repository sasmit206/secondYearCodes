module mux8to1(
input [7:0]d,
input [2:0]s,
output reg f
);
always @ (*)
	begin
	case (s)
	3'b000:f=d[0];
	3'b001:f=d[1];
	3'b010:f=d[2];
	3'b011:f=d[3];
	3'b100:f=d[4];
	3'b101:f=d[5];
	3'b110:f=d[6];
	3'b111:f=d[7];
	
	endcase
end
endmodule
	
	
