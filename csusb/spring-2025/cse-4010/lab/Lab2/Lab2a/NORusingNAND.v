//Module implements the NAND gate using two inputs and one output.
module NANDgate(A,B,Q);

    input A, B;
    output Q;

    assign Q = !(A&B); //Assign the negation of (A & B) to q.

endmodule

//1 Module implements the NOR gate only using NAND Gates
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

//2
module NOTusingNAND(A, A, Q);
    input A;
    output Q;

    NANDgate u1(A, A, Q);
endmodule

//3
module ANDusingNAND(A, B, Q);

    input A, B;
    output Q;
    wire C, D;

    NANDgate u1(A, B, C);
    NANDgate u2(C, C, D);

    assign Q = D;
endmodule

//4
module ORusingNAND(A, B, Q);
    
    input A, B;
    output Q;
    wire C, D, E;

    NANDgate u1(A, A, C);
    NANDgate u2(B, B, D);
    NANDgate u3(C, D, E);

    assign Q = E;
endmodule

//5
module NANDusingNAND(A, B, Q);
    input A, B;
    output Q;

    NANDgate u1(A, B, Q);
endmodule

//6\
module XORusingNAND(A, B, Q);
    input A, B;
    output Q;

    wire C, D, E, F;

    NANDgate u1(A, B, C);
    NANDgate u2(A, C, D);
    NANDgate u3(B, C, E);
    NANDgate u4(D, E, F);

    assign Q = F;
endmodule

//7
module XNORusingNAND(A, B, Q);
    input A, B;
    output Q;

    wire C, D, E, F, G;

    NANDgate u1(A, B, C);
    NANDgate u2(A, C, D);
    NANDgate u3(B, C, E);
    NANDgate u4(D, E, F);
    NANDgate u5(F, F, G);
    
    assign Q = G;
endmodule