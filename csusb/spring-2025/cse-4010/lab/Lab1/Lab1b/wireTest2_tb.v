`timescale 1ns/1ns
`include "wireTest2.v"

module wireTest2_tb;


//create two register to hold temporary values
reg W;
reg X;
//create a wire to have as our output
wire Y;
wire Z;

//Instantiates a wireTest2 module named uut.
wireTest2 uut(W,X,Y,Z);

initial begin

    $dumpfile("wireTest2_tb.vcd");       //$dumpfile specifies which vcd file we are dumping our vairables into
    $dumpvars(0, wireTest2_tb);          //Dump all the variables within module wireTest2_tb

    W = 0;      //Set W and X to 0
    X = 0;  
    #20         //wait 20ns

    W = 1;      //Set W to 1
    #20         //wait 20ns

    X = 1;      //Set X to 1
    #20         // wait 20ns

    W = 0;      //Set W to 0
    #20         //wait 20ns

    X = 0;      //set X to 0

    $display("Wire test complete!");    //Display the wire test is complete! on the terminal
    
end
endmodule