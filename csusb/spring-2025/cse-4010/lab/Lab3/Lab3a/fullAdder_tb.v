`timescale 1 ns / 1 ns      
`include "fullAdder.v"

//Module implementing a testbench for the full-adder modules.
module fullAdder_tb;

//Declare three register to hold our temporary values.
reg A, B, carryIn;

//Declares wires to hold our outputs from the full-adder.
wire sum, carryOut;

//Instantiates a full-adder unit test
fullAdder uut(A, B, carryIn, sum, carryOut);

initial begin

    $dumpfile("fullAdder_tb.vcd");
    $dumpvars(0, fullAdder_tb);
    
    //Following lines of code implement our truth table for the full-adders
    {A, B, carryIn} = 3'd0; #20;        //Assign A, B, and carryIn to the 3-bit length decimal value 0. A,B,Bin = 000  (0)
    {A, B, carryIn} = 3'd1; #20;        //A, B, carryIN = 001 (1)
    {A, B, carryIn} = 3'd2; #20;
    {A, B, carryIn} = 3'd3; #20;
    {A, B, carryIn} = 3'd4; #20;
    {A, B, carryIn} = 3'd5; #20;
    {A, B, carryIn} = 3'd6; #20;
    {A, B, carryIn} = 3'd7; #20;        //A, B, carryIn = 111(7)
    $display("Finished additions!");    
end

endmodule