//Module implementing a half-Subtractor
module halfSubtractor(op1, op2, difference, borrow);

    //Inputs for the half-Subtractor
    input op1, op2;

    //Outputs: difference and borrow.
    output difference, borrow;

    assign difference =  op1 ^ op2;     //difference = op1 XOR op2
    assign borrow =  !op1 & op2;        //borrow = NOT(op1) AND op2

endmodule

//Module implementing a full-Subtractor
module fullSubtractor(A, B, BIn, difference, BOut);

    //Inputs for the full-Subtractor.
    input A, B, BIn;

    //Outputs: difference, B out
    output difference, BOut;

    //Wires need to connect the two full-subtractors
    wire c, d, e, f;

    halfSubtractor u1(A, B, c, d);      // C = difference,  d = borrow value
    halfSubtractor u2(c, BIn, e, f);    // The 2nd half-adder will hace c(difference) and BIn as inputs

    assign difference = e;              //difference = e(Differnce 2nd half-subtractor)
    assign BOut =  f | d;               // BOut = f(Borrow value - 2nd half-Subtractor) OR d
    
endmodule