membro(X,[X|_]) :- !.
membro(X,[_|R]) :- membro(X,R).

cabeca(X,[X|_]).
cauda(R,[_|R]).

%dá todas as opções bem sucedidas de remoção de um elemento X da lista
remova(X, [X|R], R).
remova(X, [Y|R], [Y|W]) :- remova(X,R,W).

%remove o primeiro elemento X
remova2(_, [], []) :- !.
remova2(X, [X|R],R) :- !.
remova2(X, [Y|R], [Y|W]) :- X \== Y, remova2(X,R,W).

%remove todos os X's
remova3(_, [], []) :- !.
remova3(X,[X|R],W) :- remova3(X,R,W), !.
remova3(X,[Y|R],[Y|W]) :- X\==Y, remova3(X,R,W).

quadradoMenor(_, [], []) :- !.
quadradoMenor(X, [Y|R], W) :- Y*Y >= X, quadradoMenor(X,R,W), !.
quadradoMenor(X, [Y|R], [Y|W]) :- quadradoMenor(X,R,[Y|W]).

