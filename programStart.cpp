#include "programStart.h"
#include "algorithm_A.h"
#include "algorithm_B.h"
#include <iostream>
#include <time.h>
using namespace std;

programStart::programStart() {
	string lonely{ "" };
}

void programStart::programGo() {
    /*
        The program will ask the user for the amount of rounds first, choosing head or tails, then will execute for the player and enemy
        over x amount of rounds; inputting a move after every loop is exhausting.
        All player and enemy victories and losses, ties, and total rounds will be stored in a double array to easily convert
        numbers into percentages.
    */
    Group_Strategy alpha;
    algorithm_B beta;
    string playercoinSelect, coinTossWinner, playerMove, enemyMove;
    string roundStatus;
    string coinToss[] = { "Heads", "Tails" };
    int randomCoin{ 0 }, initialMoveNumber{ 0 }, rounds{ 0 }, display_rate{ 0 };
    srand(time(NULL));
    string initalMoveList[] = { "Rock", "Paper", "Scissors" };
    double resultList[6]{};

    cout << "DEADLY ROCK, PAPER, SCISSORS\n You win You kill loser!\n How many rounds?:" << endl;
    cin >> rounds;
    //cout << "After how many rounds would you like to see results?:\n";
    //cin >> display_rate;
    cout << "Heads or tails?:" << endl;
    cin >> playercoinSelect;
    randomCoin = rand() % 2;
    coinTossWinner = coinToss[randomCoin];

    if (coinTossWinner == "Heads" && playercoinSelect == "Heads" || coinTossWinner == "Tails" && playercoinSelect == "Tails") {
        cout << "Player makes the first move!" << endl;
        for (int i{ 1 }; i <= rounds; i++) {
            for (int j{ 0 }; j <= display_rate; j++) {
                initialMoveNumber = rand() % 3;
                playerMove = initalMoveList[initialMoveNumber];
                roundStatus = alpha.killerStrategy(playerMove);
                if (roundStatus == "PW") {
                    ++resultList[0]; //Player victories increase
                    ++resultList[3]; //Enemy losses increase
                    ++resultList[5]; //Total rounds increase

                }
                else if (roundStatus == "EW") {
                    ++resultList[1]; //Player losses increase
                    ++resultList[2]; //Enemy victories increase
                    ++resultList[5]; //Total rounds increase
                }
                else if (roundStatus == "BT") {
                    ++resultList[4]; //Ties increase
                    ++resultList[5]; //Total rounds increase
                }
            }
        }
    }
    else if (coinTossWinner == "Heads" && playercoinSelect == "Tails" || coinTossWinner == "Tails" && playercoinSelect == "Heads") {
        cout << "The enemy makes the first move!" << endl;
        for (int i{ 1 }; i <= rounds; i++) {
            //for (int j{ 0 }; j <= display_rate; j++) {
            initialMoveNumber = rand() % 3;
            enemyMove = initalMoveList[initialMoveNumber];
            roundStatus = alpha.killerStrategy(enemyMove);
            if (roundStatus == "PW") {
                ++resultList[0]; //Player victories increase
                ++resultList[3]; //Enemy losses increase
                ++resultList[5]; //Total rounds increase

            }
            else if (roundStatus == "EW") {
                ++resultList[1]; //Player losses increase
                ++resultList[2]; //Enemy victories increase
                ++resultList[5]; //Total rounds increase
            }
            else if (roundStatus == "BT") {
                ++resultList[4]; //Ties increase
                ++resultList[5]; //Total rounds increase
            }
            //}
        }
    }
    else {
        cout << "Uh...Start over." << endl;
    }

    cout << "FINISHED!\n THE WINNER IS: " << endl;
    if (resultList[0] < resultList[2]) {
        cout << "The enemy!" << endl;
        cout << "Results:\nWins: " << ((resultList[2] / rounds) * 100) << "%" << endl;
        cout << "Ties: " << ((resultList[4] / rounds) * 100) << "%" << endl;
        cout << "Total Rounds: " << (resultList[5]);
    }
    else if (resultList[2] < resultList[0]) {
        cout << "YOU!" << endl;
        cout << "Results:\nWins: " << ((resultList[0] / rounds) * 100) << "%" << endl;
        cout << "Ties: " << ((resultList[4] / rounds) * 100) << "%" << endl;
        cout << "Total Rounds: " << (resultList[5]);
    }
}