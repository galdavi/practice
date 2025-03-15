//Module implements a 8x1 multiplexer using 3 4x1 multiplexers.
module mux_8x1(a, b, c, d, e, f, g, h, sel0, sel1, sel2, out);

    input a, b, c, d, e, f, g, h, sel0, sel1, sel2;
    output out;
    
    //These wires will act as our two 4x1 multiplexers.
    wire mux1, mux2;

    //Since we need 8 inputs for our 8x1 mux, we need 2 4x1 muxes
    //We use two inner and one outer ternary operator ( ? : ) for each selector in our mux.
    //High voltage returns the expression before the colon and low voltage returns the expressions after
    //The outer ternary operator uses the input sel1 to selects between which group of variable we are going to choose from
    //The two inner ternary operator use the input sel0 to assign a specific input to our mux
    assign mux1 = sel1 ? (sel0 ? d : c) : (sel0 ? b : a);        
    assign mux2 = sel1 ? (sel0 ? h : g) : (sel0 ? f : e);       

    //This is the third mux used to combine inputs/outputs of mux1 and mux2
    assign out =  sel2 ? (sel0 ? mux2 : mux1) : (sel0 ? mux2 : mux1);   

endmodule