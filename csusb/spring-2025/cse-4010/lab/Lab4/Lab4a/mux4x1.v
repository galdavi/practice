module mux_4x1(a, b, c, d, sel0, sel1, out);
    
    input a, b, c, d, sel0, sel1;
    output out;

    assign out = sel1 ? (sel0 ? d : c) : (sel0 ? b : a);

endmodule