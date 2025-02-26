module halfAdder(op1, op2, sum, carry);
    
    input op1, op2;
    output sum, carry;

    assign sum = op1 ^ op2;
    assign carry = op1 & op2;

endmodule

module fullAdder(A, B, carryIn, sum, carryOut);

    input A, B, carryIn;
    output sum, carryOut;

    wire c, d, e, f;

    halfAdder u1(A, B, c, d);
    halfAdder u2(carryIn, c, e, f);

    assign carryOut = f | d;
    assign sum = e;
endmodule