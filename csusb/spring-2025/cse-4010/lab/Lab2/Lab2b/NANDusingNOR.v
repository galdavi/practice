//Module implements the NOR gate using two inputs and giving one ouput.
module NORgate(A, B, Q);

    input A, B; 
    output Q;

    assign Q = !(A|B);
endmodule

// 1Module implements the NAND gate only using NOR gates
module NANDusingNOR(A,B,Q);
    input A, B;
    output Q;

    wire C, D, E, F;
   
    NORgate u1(A, A, C);        //Take the NOR of input A - !(A | A) - and assign it to wire C.
    NORgate u2(B, B, D);        //Take the NOR of input B - !(B | B) - and assign it to wire D.
    NORgate u3(C, D, E);        //Take the NOR of wires C and D - !(C | D) - and assign it to wire E.
    NORgate u4(E, E, F);        //Take the NOR of wire - !(E|E) - and assing it to wire F.
    
    assign Q = F;               //Assign wire F to output Q.
endmodule

//2
module NOTusingNOR(A, A, Q);
    input A;
    output Q;

    NORgate u1(A, A, Q);
endmodule

//3
module ANDusingNOR(A, B, Q);

    input A, B;
    output Q;
    wire C, D, E;

    NORgate u1(A, A, C);
    NORgate u2(B, B, D);
    NORgate u3(C, D, E);

    assign Q = E;
endmodule

//4
module ORusingNOR(A, B, Q);
    
    input A, B;
    output Q;
    wire C, D, E;

    NORgate u1(A,B,C);
    NORgate u2(C, C, E);
    assign Q = E;
endmodule



//5
module XORusingNOR(A, B, Q);
    input A, B;
    output Q;

    wire C, D, E, F, G;
    NORgate u1(A, B, C);
    NORgate u2(A, C, D);
    NORgate u3(B, C, E);
    NORgate u4(D, E, F);
    NORgate u5(F, F, G);

    assign Q = G;
endmodule

//6
module NORusingNOR(A, B, Q);
    input A, B;
    output Q:

    NORgate u1(A, B, Q);
endmodule

//7
module XNORusingNOR(A, B, Q);
    input A, B;
    output Q;

    wire C, D, E, F;

    NORgate u1(A, B, C);
    NORgate u2(A, C, D);
    NORgate u3(B, C, E);
    NORgate u4(D, E, F);

    
    assign Q = F;
endmodule