//Module implementing a half-adder
module halfAdder(op1, op2, sum, carry);
    
    //Inputs for the half-adder.
    input op1, op2;
    
    //Outputs: sum and carry
    output sum, carry;

    //Assign the sum and carry to the appropiate logic gates
    assign sum = op1 ^ op2;             // Sum = op1 XOR op2
    assign carry = op1 & op2;           // Carry = op1 AND op2

endmodule

//Module implementing a full-adder
module fullAdder(A, B, carryIn, sum, carryOut);

    //Inputs for the full-adder.
    input A, B, carryIn;
    
    //Output: sum and carry out
    output sum, carryOut;

    //Wires needed to connect the two half-adders.
    wire c, d, e, f;

    halfAdder u1(A, B, c, d);           //The outputs of the first half adder are assigned to c(sum) and d(carry)
    halfAdder u2(carryIn, c, e, f);     //The second half-adder will have a carry in and the sum as inputs.

    assign carryOut = f | d;            //Carryout = f(carry-2nd half-adder) OR d (carry)
    assign sum = e;                     //Sum = e(sum - 2nd half-adder)
endmodule