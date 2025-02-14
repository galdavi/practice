`timescale 1ns/1ns
`include "NANDusingNOR.v"

//Module test the functionality of module NANDusingNOR
module NANDusingNOR_tb;

reg A, B;
wire Q;

//We instantiate a NANDusingNOT module
NANDusingNOR uut(A,B,Q);

initial begin

    $dumpfile("NANDusingNOR_tb.vcd");
    $dumpvars(0, NANDusingNOR_tb);

    //The following lines of code mimic a truth table, after 20ns both inputs switch into the next row of the table.
    A = 0; B = 0; #20
    A = 0; B = 1; #20
    A = 1; B = 0; #20
    A = 1; B = 1; #20

    $display("Complete!");
end

endmodule