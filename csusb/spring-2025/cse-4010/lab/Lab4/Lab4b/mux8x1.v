module mux_8x1(a, b, c, d, e, f, g, h, sel0, sel1, sel2, out);

    input a, b, c, d, e, f, g, h, sel0, sel1, sel2;
    output out;
    
    reg mux1, mux2;
    assign mux1 = sel1 ? (sel0 ? d : c) : (sel0 ? b : a);
    
    assign mux2 = sel1 ? (sel0 ? h : g) : (sel0 ? f : e);
    
    assign out =  sel2 ? mux2 : mux1; 
endmodule