%1
rem1(X, [X|R], R) :- !.
rem1(X, [C|R], [C|T]) :-
    rem1(X, R, T).

%2
uniao([], B, B) :- !.
uniao([A|R1], B, L) :-
    exist(A, B),
    uniao(R1, B, L), !.
uniao([A|R1], B, [A|L]) :-
    uniao(R1, B, L).


uniaoll([], []) :- !.
uniaoll([X|R], L) :-
    uniaoll(R, L2),
    uniao(X, L2, L).

%3
xor([], B, B) :- !.
xor([A|R], B, W) :-
    rem1(A, B, L),
    xor(R, L, W), !.
xor([A|R], B, [A|W]) :-
    xor(R, B, W).

%4
filtra(_, [], []) :- !.
filtra(PF, [A|R], [A|W]) :-
    call(PF, A),
    filtra(PF, R, W), !.
filtra(PF, [_|R], W) :-
    filtra(PF, R, W).

%5
remove(_, [], []) :- !.
remove(X, [X|R], W) :-
    remove(X, R, W), !.
remove(X, [Y|R], [Y|W]) :-
    remove(X, R, W).

exist(X, [X|_]) :- !.
exist(X, [_|R]) :-
    exist(X, R).

resolve([], []) :- !.
resolve([A|L], W) :-
    exist(A, L),
    remove(A, L, X),
    resolve(X, W), !.

resolve([A|L], [A|W]) :-
    resolve(L, W).

concatenar([], L2, L2) :- !.
concatenar([X|R], L2, [X|W]) :-
    concatenar(R, L2, W).

unirtudo([], []).
unirtudo([A|R], L) :-
    unirtudo(R, W),
    concatenar(A, W, L).

xorll([], []) :- !.
xorll(LL, L) :-
    unirtudo(LL, X),
    resolve(X, L).