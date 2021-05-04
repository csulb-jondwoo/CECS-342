% CECS 342
% Logic Puzzle


%define atoms for objects seen and people
object(balloon).
object(clothesline).
object(frisbee).
object(water_tower).
person(mr_klatu).
person(mr_nikto).
person(ms_gort).
person(ms_barrada).

% Solve the puzzle.
solve :-
    
    %define variables for each Object
    object(Obj1), object(Obj2), object(Obj3), object(Obj4),
    %forces result of objects to be unique
    all_different([Obj1, Obj2, Obj3, Obj4]),
    
    %define variables for each person
    person(Person1), person(Person2), person(Person3), person(Person4),
    %forces result of persons to be unique
    all_different([Person1, Person2, Person3, Person4]),

    %define triplets for centered around day and in order of day
    Triples = [ [Person1, Obj1, tuesday],
                [Person2, Obj2, wednesday],
                [Person3, Obj3, thursday],
                [Person4, Obj4, friday] ],

    % 1. Mr.Klatu made his sighting at some point earlier in the week than the one who saw the balloon,
    % but at some point later in the week than the one who spotted the Frisbee (who isn't Ms. Gort).
    \+ member([mr_klatu, balloon, _], Triples), 
    \+ member([mr_klatu, frisbee, _], Triples),
    \+ member([ms_gort, frisbee, _], Triples),
    earlier([mr_klatu, _, _], [_, balloon, _], Triples),
    earlier([_, frisbee, _], [mr_klatu, _, _], Triples),

    % 2. Friday's sighting was made by either Ms. Barrada or the one who saw a clothesline (or both).
    (   member([ms_barrada, _, friday], Triples);
    	member([_, clothesline, friday], Triples)),

    % 3. Mr. Nikto did not make his sighting on Tuesday.
    \+ member([mr_nikto, _, tuesday], Triples),

    % 4. Mr. Klatu isn't the one whose object turned out to be a water tower.
    \+ member([mr_klatu, water_tower, _], Triples), 
    
    %prints results for each day
    tell(Person1, Obj1, tuesday),
    tell(Person2, Obj2, wednesday),
    tell(Person3, Obj3, thursday),
    tell(Person4, Obj4, friday).

% Determines which of the objects given is earlier than the other by order of day in Triplets list
earlier(X, _, [X|_]).
earlier(_, Y, [Y|_]) :- !, fail.
earlier(X, Y, [_|T]) :- earlier(X, Y, T).

% Succeed if all elements of the argument list are bound and different.
% Fail if any elements are unbound or equal to some other element.
all_different([H | T]) :- member(H, T), !, fail.        % (1)
all_different([_ | T]) :- all_different(T).             % (2)
all_different([_]).                                     % (3)

% Write out an English sentence with the solution.
tell(X, Y, Z) :-
    write(X), write(' saw a '), write(Y),
    write(' on '), write(Z), write('.'), nl.
