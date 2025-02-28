`timescale 1 ns / 1 ns
`include "fullSubtractor.v"

//Module implementing a testbench for the full-subtractor module
module fullSubtractor_tb;
 
 //Declares three register to hold our temporary values.
 reg A, B, BIn;

 //Declares wires to hold our outputs from the full-subtractors/
 wire difference, BOut;

//Instantiates full-subtractor unit test
 fullSubtractor uut(A, B, BIn, difference, BOut);

 initial begin

    $dumpfile("fullSubtractor_tb.vcd");
    $dumpvars(0, fullSubtractor_tb);
    
    //Following lines of code implement our truth table for the full-Subtractors
    {A, B, BIn} = 3'd0; #20;        //Assign A, B, and BIn to the 3-bit length decimal value 0. A,B,Bin = 000 (0)
    {A, B, BIn} = 3'd1; #20;        //A, B, BIn = 001(1)
    {A, B, BIn} = 3'd2; #20;
    {A, B, BIn} = 3'd3; #20;
    {A, B, BIn} = 3'd4; #20;
    {A, B, BIn} = 3'd5; #20;
    {A, B, BIn} = 3'd6; #20;
    {A, B, BIn} = 3'd7; #20;        //A, B, BIn = 111 (7)
    $display("Finished additions!");    
end

endmodule