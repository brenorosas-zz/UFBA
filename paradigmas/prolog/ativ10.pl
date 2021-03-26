exist(X,[X|_]) :- !.
exist(X,[Y|R]) :- Y\==X, exist(X,R).

uniao2([],C,C).
uniao2([E|R],C,W) :- exist(E,C), uniao2(R,C,W), !.
uniao2([E|R],C,[E|W]) :- uniao2(R,C,W).

uniaoLL([],[]) :- !.
uniaoLL([L|RLL], U) :- uniaoLL(RLL, CR), uniao2(L,CR,U).

interseccao([],_,[]) :- !.
interseccao([X|R], L, [X|W]) :- exist(X,L), interseccao(R,L,W), !.
interseccao([_|R], L, W) :- interseccao(R,L,W).

interseccaoLL([],[]) :- !.
interseccaoLL([X],X) :- !.
interseccaoLL([L1|RLL], I) :- interseccaoLL(RLL, CR), interseccao(L1, CR, I).

inserir(X,[],[X]) :- !.
inserir(X,[Y|R], [X,Y|R]) :- X =< Y, !.
inserir(X, [Y|R],[Y|W]) :- inserir(X,R,W).

% insertion sort
isort([],[]) :- !.
isort([X],[X]) :- !.
isort([X|R], LO) :- isort(R,LOP), inserir(X,LOP,LO).