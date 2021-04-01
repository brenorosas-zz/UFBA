quadradoMenor(_, [], []) :- !.
quadradoMenor(X, [Y|R], W) :- Y*Y >= X, quadradoMenor(X,R,W), !.
quadradoMenor(X, [Y|R], [Y|W]) :- quadradoMenor(X,R,W).

quadradoMenor2(X,[Y|_],Y) :- Y*Y < X.
quadradoMenor2(X,[_|R],W) :- quadradoMenor2(X,R,W).

