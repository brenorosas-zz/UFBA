quadradoMenor(_, [], []) :- !.
quadradoMenor(X, [Y|R], W) :- Y*Y >= X, quadradoMenor(X,R,W), !.
quadradoMenor(X, [Y|R], [Y|W]) :- quadradoMenor(X,R,W).

quadradoMenor2(X,[Y|_],Y) :- Y*Y < X.
quadradoMenor2(X,[_|R],W) :- quadradoMenor2(X,R,W).

exist(X,[X|_]) :- !.
exist(X,[Y|R]) :- Y\==X, exist(X,R).

interseccao([],_,[]) :- !.
interseccao([X|R], L, [X|W]) :- exist(X,L), interseccao(R,L,W), !.
interseccao([_|R], L, W) :- interseccao(R,L,W).

oculte(_,[],[]) :- !.
oculte(X,[X|R], [xxxx|W]) :- oculte(X,R,W), !.
oculte(X,[Y|R], [Y|W]) :- oculte(X,R,W).

oculteConj(_,[],[]) :- !.
oculteConj(X, [Y|R], [xxxx|W]) :- exist(Y,X), oculteConj(X,R,W), !.
oculteConj(X,[Y|R],[Y|W]) :- oculteConj(X,R,W).

intercala1(_, _, Y, N, []) :- Y =:= N, !.
intercala1(X,Y,K, N, [X|W]) :- K mod 2 =:= 0, A is K+1, intercala1(X, Y, A, N,W), !.
intercala1(X,Y,K, N, [Y|W]) :- A is K+1, intercala1(X,Y,A,N,W).

intercala(X,Y,N,L) :- intercala1(X,Y,0,N,L).
