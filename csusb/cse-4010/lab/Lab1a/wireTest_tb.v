`timescale 1ns/1ns
`include "wireTest.v"

module wireTest_tb;

reg A;      //Creates a register variable named A, that can hold temporary values
wire B;     //Create a wire variable B and C
wire C;

//Instatiates a wireTest module using the data types above it is named utt.
wireTest uut(A,B,C);

initial begin

    $dumpfile("wireTest_tb.vcd");       //$dumpfile specifies which vcd file we are dumping our vairables into
    $dumpvars(0, wireTest_tb);          //Dump all the variables within module wireTest_tb

    //Cycle between 0 and 1 with a 20ns gap
    A = 0;
    #20

    A = 1;
    #20

    A = 0;
    #20

    A = 1;
    #20

    $display("Wire test complete!");    //Display the wire test is complete! on the terminal
    
end
endmodule