`timescale 1ns / 1ns
`include "mux4x1.v"

module mux4x1_tb;

reg A, B, C, D, Sel0, Sel1;
wire O;

mux_4x1 uut(A, B, C, D, Sel0, Sel1, O);

initial begin
  $dumpfile("mux4x1_tb");
  $dumpvars(0, mux4x1_tb);

  A = 0; B = 1; C = 0; D = 1;
  {Sel1, Sel0} = 2'd0; #20;
  {Sel1, Sel0} = 2'd1; #20;
  {Sel1, Sel0} = 2'd2; #20;
  {Sel1, Sel0} = 2'd3; #20;

  $display("Complete!");
end

endmodule