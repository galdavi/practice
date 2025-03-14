`timescale 1ns / 1ns
`include "mux8x1.v"

module mux8x1_tb;

reg A, B, C, D, E, F, G, H, Sel0, Sel1, Sel2;
wire O;

mux_8x1 uut(A, B, C, D, E, F, G, H, Sel0, Sel1, Sel2, O);

initial begin
    $dumpfile("mux8x1_tb");
    $dumpvars(0, mux8x1_tb);
    A = 0; B = 1; C = 0; D = 1;
    {Sel2, Sel1, Sel0} = 3'd0; #20;
    {Sel2, Sel1, Sel0} = 3'd1; #20;
    {Sel2, Sel1, Sel0} = 3'd2; #20;
    {Sel2, Sel1, Sel0} = 3'd3; #20;
    {Sel2, Sel1, Sel0} = 3'd4; #20;
    {Sel2, Sel1, Sel0} = 3'd5; #20;
    {Sel2, Sel1, Sel0} = 3'd6; #20;
    {Sel2, Sel1, Sel0} = 3'd7; #20;

    $display("Complete!");
end
endmodule
