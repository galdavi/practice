
//Module implements the NAND gate using two inputs and one output.
module NANDgate(A,B,Q);

    input A, B;
    output Q;

    assign Q = !(A&B); //Assign the negation of (A & B) to q.

endmodule

//Module implements the NOR gate only using NAND Gates
module NORusingNAND(A, B, Q);

    input A, B;
    output Q;

    wire C, D, E, F;

    NANDgate u1(A, A, C);       //Take the NAND of input A - !(A*A) - and assign it to wire C.
    NANDgate u2(B, B, D);       //Take the NAND of input B - !(B*B) - and assign it to wire D.
    NANDgate u3(C, D, E);       //Take the NAND of wires C and D - !(C*D) - and assign it to wire E.
    NANDgate u4(E, E, F);       //Take the NAND of wire - !(E*E) - and assign it to wire F.

    assign Q = F;               //Assign wire F to output Q.
endmodule