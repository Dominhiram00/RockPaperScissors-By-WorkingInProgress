#pragma once
/*
The Killer Strategy
Created by Hiram Dominguez

A strategy that goes the opposite direction of rock, paper, scissors!
*/
#ifndef ALGORITHM_A_H
#define ALGORITHM_A_H
#include <iostream>
#include <time.h>
using namespace std;

class Group_Strategy {
public:
    Group_Strategy();
    string killerStrategy(string move);
};

#endif