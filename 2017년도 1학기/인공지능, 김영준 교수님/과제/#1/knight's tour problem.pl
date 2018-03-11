move(s(X,Y),s(W,Z)):- W is X+2, Z is Y-1, X+2<6, Y-1>0.
move(s(X,Y),s(W,Z)):- W is X+1, Z is Y-2, X+1<6, Y-2>0.
move(s(X,Y),s(W,Z)):- W is X-1, Z is Y-2, X-1>0, Y-2>0.
move(s(X,Y),s(W,Z)):- W is X-2, Z is Y-1, X-2>0, Y-1>0.
move(s(X,Y),s(W,Z)):- W is X-2, Z is Y+1, X-2>0, Y+1<6.
move(s(X,Y),s(W,Z)):- W is X-1, Z is Y+2, X-1>0, Y+2<6.
move(s(X,Y),s(W,Z)):- W is X+1, Z is Y+2, X+1<6, Y+2<6.
move(s(X,Y),s(W,Z)):- W is X+2, Z is Y+1, X+2<6, Y+1<6.

member(X,[X|T]).
member(X,[Y|T]):- member(X,T).

reverse_writelist([]).
reverse_writelist([H|T]):- reverse_writelist(T), write(H), nl.

path(s(X,Y),s(X,Y),L):- reverse_writelist(L).
path(s(X,Y),s(G,H),L):- move(s(X,Y),s(W,Z)), not(member(s(W,Z),L)), path(s(W,Z),s(G,H),[s(W,Z)|L]).