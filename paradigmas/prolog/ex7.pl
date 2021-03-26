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