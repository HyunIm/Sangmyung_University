investment(savings):-savings_account(inadequate).
investment(stocks):- savings_account(adequate), income(adequate).
investment(combination):- savings_account(adequate), income(inadequate).
savings_account(adequate):- amount_saved(X), dependents(Y), X > 5000*Y.
savings_account(inadequate):- amount_saved(X),dependents(Y),X=<5000*Y.
income(adequate):-earnings(X, steady), dependents(Y), X > 15000+4000*Y.
income(inadequate):- earnings(X, steady), dependents(Y),  X =< 15000+ 4000*Y.
income(inadequate):- earnings(X, unsteady).
amount_saved(30000).
earnings(35000, steady).
dependents(3).