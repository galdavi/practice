`timescale 1ns/1ns
`include "NORusingNAND.v"

//Module test the functionality of moduel NORusingNAND
module NORusingNAND_tb;

reg A, B;
wire Q;

NORusingNAND uut(A,B,Q);

initial begin

    $dumpfile("NORusingNAND_tb.vcd");
    $dumpvars(0, NORusingNAND_tb);

    A = 0; B = 0; #20
    A = 0; B = 1; #20
    A = 1; B = 0; #20
    A = 1; B = 1; #20

    $display("Complete!");
end

endmodule