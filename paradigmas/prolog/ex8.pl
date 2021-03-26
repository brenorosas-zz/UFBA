append([],L,L) :- !.
append([X|R],L,[X|W]) :- append(R,L,W).

divide_p([],_,[],[]) :- !.
divide_p([X|R],P,[X|L1],L2) :- X =< P, divide_p(R,P,L1,L2), !.
divide_p([X|R],P,L1,[X|L2]) :- divide_p(R,P,L1,L2).

quicksort([],[]) :- !.
quicksort([X],[X]) :- !.
quicksort([X|R], LO) :- divide_p(R,X,L1,L2), quicksort(L1,LO1), quicksort(L2,LO2), append(LO1,[X|LO2], LO).