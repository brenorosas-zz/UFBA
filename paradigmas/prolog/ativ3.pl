media(A,B,C) :- C is (A+B)/2.

fatorial(0,1) :- !.  %cut
fatorial(N,X) :- N>0,
                M is N-1,
                fatorial(M,F),
                X is N*F.

fat_aux2(0,A,A) :- !.
fat_aux2(N,A,X) :- N>0,
                    NA is A*N,
                    M is N-1,
                    fat_aux2(M,NA,X).

fatorial2(N,X) :- fat_aux2(N,1,X).

fatorial3(0,1) :- !.
fatorial3(N, N*Z) :- N>0,
                    U is N-1,
                    fatorial3(U,Z).