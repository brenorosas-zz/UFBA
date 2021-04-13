%1
concatenar([],L2,L2) :- !.
concatenar([X|R],L2,[X|W]) :- concatenar(R,L2,W).

%2
concatenarInv(L1,[],L1) :- !.
concatenarInv(L1,[X|R], [X|W]) :- concatenarInv(L1,R,W).

%3
concatenarLL([], []) :- !.
concatenarLL([X|R], L) :- concatenarLL(R,W), concatenar(X,W,L).

%4
juntar([],L,L) :- !.
juntar(L, [], L) :- !.
juntar([X|R1],[Y|R2],[X,Y|W]) :- juntar(R1,R2,W).

%5
adicionarFinal(E,[],[E]) :- !.
adicionarFinal(E,[X|R], [X|W]) :- adicionarFinal(E,R,W).

%6
inverter([], []) :- !.
inverter([X|R], W) :- inverter(R,L), adicionarFinal(X,L,W).

%7
inverterLG([], []) :- !.
inverterLG([X|R], K) :- is_list(X), inverterLG(X,W), inverterLG(R,Z), adicionarFinal(W,Z,K), !.
inverterLG([X|R], K) :- inverterLG(R,W), adicionarFinal(X,W,K).

%8
parear(_,[],[]) :- !.
parear(V,[X|R],[[V,X]|W]) :- parear(V,R,W).

%10
pares([], []) :- !.
pares([X|R], W) :- pares(R, L1), parear(X,R,L2), concatenar(L2,L1,W).

%11
remova(X,[X|T],T).
remova(X,[H|T],[H|NT]):-remova(X,T,NT).

permutar([],[]).
permutar(L,[X|W]) :- remova(X,L,NL), permutar(NL, W).

%12
exist(X,[X|_]) :- !.
exist(X,[_|R]) :- exist(X,R).

conjunto([]).
conjunto([X|R]) :- \+exist(X,R), conjunto(R).

%13
prefixo([],_).
prefixo([X|R], [X|R2]) :- prefixo(R,R2).

%14
subsequencia(L,L2) :- prefixo(L,L2), !.
subsequencia(L,[_|R]) :- subsequencia(L,R).

%15
mescle([],L,L) :- !.
mescle(L,[],L) :- !.
mescle([X|RX],[Y|RY],[X|W]) :- X =< Y, mescle(RX,[Y|RY],W), !.
mescle(X,[Y|RY],[Y|W]) :- mescle(X,RY,W).

%16
merge([],L,L) :- !.
merge(L,[],L) :- !.
merge([X|RX],[Y|RY],[X|W]) :- X =< Y, merge(RX,[Y|RY],W), !.
merge(X,[Y|RY],[Y|W]) :- merge(X,RY,W).

split([], [], []) :- !.
split([X], [X], []) :- !.
split([E1,E2|R], [E1|R1], [E2|R2]) :- split(R,R1,R2).

mergeSort([],[]) :- !.
mergeSort([X],[X]) :- !.
mergeSort(L,LO) :- split(L,A,B), mergeSort(A,L1), mergeSort(B,L2), merge(L1,L2,LO).
