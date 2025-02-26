`timescale 1 ns / 1 ns
`include "fullAdder.v"

module fullAdder_tb;

reg A, B, carryIn;
wire sum, carryOut;

fullAdder uut(A, B, carryIn, sum, carryOut);

initial begin

    $dumpfile("fullAdder_tb.vcd");
    $dumpvars(0, fullAdder_tb);

    {A, B, carryIn} = 3'd0; #20;
    {A, B, carryIn} = 3'd1; #20;
    {A, B, carryIn} = 3'd2; #20;
    {A, B, carryIn} = 3'd3; #20;
    {A, B, carryIn} = 3'd4; #20;
    {A, B, carryIn} = 3'd5; #20;
    {A, B, carryIn} = 3'd6; #20;
    {A, B, carryIn} = 3'd7; #20;
    $display("Finished additions!");    
end

endmodule