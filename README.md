# mastermind
Mastermind Game

Author : Anant Shah
Email : anantshah200@gmail.com
Date : 10-5-2018

Language : C

Compiler : gcc

This program is written to play the game Mastermind. The secret code can be any combination of 6 colours : Red(R), White(W), Yellow(Y),Green(G),Bk(Black) and Bu(Blue). The maximum number of guesses allowed to a user are 10. The scoring is such that if a colour is in the right position, it gets a Black score. If it is not in the right position but present in the code, it gets a white score. 

Written below is a test case :

Secret Code : RGYBu

Guess 1 : YRBkW
Scoring : WW
Guess 2 : RBuYG
Scoring : BkBkWW
Guess 3 : RGYBu
Scoring : BkBkBkBk
