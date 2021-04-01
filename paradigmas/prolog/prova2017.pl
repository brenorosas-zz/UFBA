exist(X,[X|_]) :- !.
exist(X,[_|R]) :- exist(X,R).

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

cont(_, [], 0) :- !.
cont(X, [X|R], Y) :- Z is 1, cont(X,R,W), Y is Z+W, !.
cont(X, [_|R], Y) :- Z is 0, cont(X,R,W), Y is Z+W.

sumarizex(_,[],[],[]) :- !.
sumarizex(LA,[X|R],L1,L2) :- exist(X,LA), sumarizex(LA,R,L1,L2), !.
sumarizex(LA,[X|R],[X|W],[Y|W2]) :- cont(X,[X|R],Y), sumarizex([X|LA], R, W, W2).

sumarize(L,L1,L2) :- sumarizex([],L,L1,L2).

make(V,[X],[X],[]) :- V=:=X, !.
make(_,[X],[],[X]) :- !.
make(V,[X|R],[X|W],L) :- V=:=X, make(V,R,W,L), !.
make(_, L, [], L).

empacote([],[]) :- !.
empacote([X|R], [L|W]) :- make(X,[X|R],L,L2), empacote(L2,W).
