#include "algorithm_A.h"
#include <iostream>
#include <time.h>
using namespace std;

Group_Strategy::Group_Strategy() {
    string playerMove;
    string enemyMove;
}

string Group_Strategy::killerStrategy(string move) {
    /*
        Using rand() function to determine the first move, then using the strategy mentioned on algorithm_A.h.
        The function returns a string to add to array resultList in programStart.cpp
    */
    string moveList[] = { "Rock", "Paper", "Scissors" };
    string playerMove, enemyMove{ move };
    int RanIndex = rand() % 3;
    playerMove = moveList[RanIndex];

    if (playerMove == enemyMove) {
        return "BT";
    }
    else if (playerMove == "Rock" && enemyMove == "Paper") {
        // "Enemy defeated player (Rock) using PAPER";
        return "EW";
    }
    else if (playerMove == "Paper" && enemyMove == "Rock") {
        // "Player defeated enemy (Rock) using PAPER";
        return "PW";
    }
    else if (playerMove == "Scissors" && enemyMove == "Rock") {
        // "Enemy defeated player (Scissors) using ROCK";
        return "EW";
    }
    else if (playerMove == "Rock" && enemyMove == "Scissors") {
        // "Player defeated enemy (Scissors) using ROCK";
        return "PW";
    }
    else if (playerMove == "Paper" && enemyMove == "Scissors") {
        // "Enemy defeated player (Paper) using Scissors";
        return "EW";
    }
    else if (playerMove == "Scissors" && enemyMove == "Paper") {
        // "Player defeated enemy (Paper) using SCISSORS";
        return "PW";
    }
}