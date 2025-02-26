module halfSubtractor(op1, op2, difference, borrow);

    input op1, op2;
    output difference, borrow;

    assign difference =  op1 ^ op2;
    assign borrow =  !op1 & op2;

endmodule

module fullSubtractor(A, B, BIn, difference, BOut);

    input A, B, BIn;
    output difference, BOut;

    wire c, d, e, f;

    halfSubtractor u1(A, B, c, d);      // C = difference,  d = borrow value
    halfSubtractor u2(c, BIn, e, f);    // e = dfference, f = borrow value.

    assign difference = e;
    assign BOut =  f | d;               // BOut = f XOR d
    
endmodule