p(a).
p(X) :- q(X), r(X).
p(X) :- q(X).
p(X) :- u(X).

q(X) :- s(X).
q(X) :- t(X).
q(X) :- u(X).

r(a).
r(b).

s(a).
s(b).
s(c).

u(z).

t(e).
t(f).
t(b).