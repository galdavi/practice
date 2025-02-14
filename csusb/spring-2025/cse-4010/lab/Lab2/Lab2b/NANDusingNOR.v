//Module implements the NOR gate using two inputs and giving one ouput.
module NORgate(A, B, Q);

    input A, B; 
    output Q;

    assign Q = !(A|B);
endmodule

//Module implements the NAND gate only using NOR gates
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