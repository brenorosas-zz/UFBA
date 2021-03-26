homem(manoel).
homem(renato).
homem(jerry).
% homem(ted).
mulher(sue).
mulher(carol).
mulher(alice).

pai(john, jerry).
pai(john, carol).
pai(jerry, ted).
pai(jim, bob).

mae(alice, jerry).
mae(alice, carol).
mae(sue, ted).
mae(carol, bob).

progenitor(X,Y) :- pai(X,Y).
progenitor(X,Y) :- mae(X,Y).
irmaos(X,Y) :- progenitor(Z,X), progenitor(Z,Y), X\==Y.
filha(Y,X) :- progenitor(X, Y), mulher(Y).
filho(X,Y) :- progenitor(Y,X), homem(X).