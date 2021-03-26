vermelho(marcador).
preto(lapis).
preto(sapato).
preto(tv).

cor(P, vermelho) :- vermelho(P),!.
cor(P, preto) :- preto(P), !.
cor(_, desconhecida).

cabeca([X|_], X).
cauda([_|Y], Y).
cons(X,Y,[X|Y]).

membro(X,[X|_]) :- !.
membro(X,[_|R]) :- membro(X,R).