

//Implements a module named wireTest2, which takes two inputs (X and W) and gives two outputs (Y, Z).
module wireTest2(W, X, Y,Z);

    input W;
    input X;
    
    output Y;
    output Z;
    
    assign Y = !X;      //Assign the negation of X to Y.
    assign Z = !Y;      //Assign the negation of Y to Z.

endmodule