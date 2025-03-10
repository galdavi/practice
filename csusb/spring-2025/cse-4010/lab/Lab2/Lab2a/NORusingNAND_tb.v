`timescale 1ns/1ns
`include "NORusingNAND.v"

//Module test the functionality of module NORusingNAND
module NORusingNAND_tb;

reg A, B;
wire Q;

//We instantiate NORusingNAND  module
NORusingNAND uut(A,B,Q);

initial begin

    $dumpfile("NORusingNAND_tb.vcd");
    $dumpvars(0, NORusingNAND_tb);

    //The following lines of code mimic a truth table, after 20ns both inputs switch into the next row of the table.
    A = 0; B = 0; #20
    A = 0; B = 1; #20
    A = 1; B = 0; #20
    A = 1; B = 1; #20

    $display("Complete!");
end

endmodule