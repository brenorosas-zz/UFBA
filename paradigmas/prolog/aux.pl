rem1(E, [E|R], R) :- !.
rem1(E, [X|R], [X|W]) :-
    rem1(E, R, W), !.