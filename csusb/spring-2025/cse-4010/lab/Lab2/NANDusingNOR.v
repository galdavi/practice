
//Module implements the NOR gate using two inputs and giving one ouput.
module NORgate(A, B, Q);

    input A, B; 
    output Q;

    assign Q = !(A+B);
endmodule

module NANDusingNOR(A,B,Q);
    input A, B;
    output Q;

    wire C, D, E, F;
endmodule