module mux2to1(
input a,
input b,
input s,
output reg f
);
always@(*)
	begin
		if(s==1'b0)
			f=a;
		if(s==1'b1)
			f=b;
	end
endmodule
