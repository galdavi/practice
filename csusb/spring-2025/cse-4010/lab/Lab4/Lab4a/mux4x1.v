//Module uses a one ternary operator to implement a 4x1 multiplexer
module mux_4x1(a, b, c, d, sel0, sel1, out);
    
    input a, b, c, d, sel0, sel1;
    output out;

    //We use two inner and one outer ternary operator ( ? : ) for our mux.
    //High voltage returns the expression before the colon and low voltage returns the expressions after
    //The outer ternary operator uses the input sel1 to selects between which group of variable we are going to choose from
    //The two inner ternary operator use the input sel0 to assign a specific input to our mux output
    assign out = sel1 ? (sel0 ? d : c) : (sel0 ? b : a);

endmodule