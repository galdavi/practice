`timescale 1ns / 1ns
`include "mux4x1.v"

//Module implements a testbench for our 4x1 mux
module mux4x1_tb;

//Declare 6 input variable and 1 output variable (O) for our mux
reg A, B, C, D, Sel0, Sel1;
wire O;

//Instantiates a mux_4x1 unit test.
mux_4x1 uut(A, B, C, D, Sel0, Sel1, O);

initial begin

  $dumpfile("mux4x1_tb");
  $dumpvars(0, mux4x1_tb);

  //Assign our input values.
  A = 0; B = 1; C = 0; D = 1;
  
  //Following lines of code assign 2-bit lenght decimal to our Sel1 and Sel0 with a 20ns interval
  {Sel1, Sel0} = 2'd0; #20;     //Sel1, Sel0 = 00 (0).
  {Sel1, Sel0} = 2'd1; #20;     //Sel1, Sel0 = 01 (1)
  {Sel1, Sel0} = 2'd2; #20;     //Sel1, Sel0 = 10 (2)
  {Sel1, Sel0} = 2'd3; #20;     //Sel1, Sel0 = 11 (3)

  $display("Complete!");
end

endmodule