%Torre de Hanoi
torrehanoi(1,X,_,Y) :- write("mova disco do "),
                        write(X),
                        write(" para "),
                        writeln(Y),
                        !.
torrehanoi(N,X,Z,Y) :- N>1,
                        M is N-1,
                        torrehanoi(M,X,Y,Z),
                        torrehanoi(1,X,_,Y),
                        torrehanoi(M,Z,X,Y).