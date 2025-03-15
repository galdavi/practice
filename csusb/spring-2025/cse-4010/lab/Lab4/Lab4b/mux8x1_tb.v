`timescale 1ns / 1ns
`include "mux8x1.v"

//Module implements a test bench for our 8x1 mux 
module mux8x1_tb;

//Declares 11 input variables and one output variable (O)
reg A, B, C, D, E, F, G, H, Sel0, Sel1, Sel2;
wire O;

mux_8x1 uut(A, B, C, D, E, F, G, H, Sel0, Sel1, Sel2, O);

initial begin
    $dumpfile("mux8x1_tb");
    $dumpvars(0, mux8x1_tb);
    
    //Assign our input values.
    A = 0; B = 1; C = 0; D = 1;
    E = 0; F = 1; G = 0; H = 1;
    
    //Following lines of code assign 3-bit lenght decimal to our Sel2, Sel1 and Sel0 with a 20ns interval
    {Sel2, Sel1, Sel0} = 3'd0; #20;     //Sel2, Sel1, Sel0 = 000 (0) 
    {Sel2, Sel1, Sel0} = 3'd1; #20;     //Sel2, Sel1, Sel0 = 001 (1)
    {Sel2, Sel1, Sel0} = 3'd2; #20;     //Sel2, Sel1, Sel0 = 010 (2)
    {Sel2, Sel1, Sel0} = 3'd3; #20;     //And a similar pattern follows for the remaining values
    {Sel2, Sel1, Sel0} = 3'd4; #20;
    {Sel2, Sel1, Sel0} = 3'd5; #20;
    {Sel2, Sel1, Sel0} = 3'd6; #20;
    {Sel2, Sel1, Sel0} = 3'd7; #20;

    $display("Complete!");
end
endmodule
