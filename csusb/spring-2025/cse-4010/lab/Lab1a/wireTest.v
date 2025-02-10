
//Creates a module named wireTest, which accepts one input (A) and gives two outputs(B and C)
module wireTest(A,B,C);

    input A;        //Our variable A will be an input
    output B;       //Our variables B, C will be an output
    output C;

    assign B = A;       //Assign the value of A to B
    assign C = !A;      //Assign the negation of A to C.

endmodule