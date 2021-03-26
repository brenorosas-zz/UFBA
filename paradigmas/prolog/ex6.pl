merge([],L,L) :- !.
merge(L,[],L) :- !.
merge([X|RX],[Y|RY],[X|W]) :- X =< Y, merge(RX,[Y|RY],W), !.
merge(X,[Y|RY],[Y|W]) :- merge(X,RY,W).