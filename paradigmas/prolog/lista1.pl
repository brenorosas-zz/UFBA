concatenar([],L2,L2) :- !.
concatenar([X|R],L2,[X|W]) :- concatenar(R,L2,W).

concatenarInv(L1,[],L1) :- !.
concatenarInv(L1,[X|R], [X|W]) :- concatenarInv(L1,R,W).

concatenarLL([], []) :- !.
concatenarLL([X|R], L) :- concatenarLL(R,W), concatenar(X,W,L).

adicionarFinal(E,[],[E]) :- !.
adicionarFinal(E,[X|R], [X|W]) :- adicionarFinal(E,R,W).

inverter([], []) :- !.
inverter([X|R], W) :- inverter(R,L), adicionarFinal(X,L,W).

parear(_,[],[]) :- !.
parear(V,[X|R],[[V,X]|W]) :- parear(V,R,W).