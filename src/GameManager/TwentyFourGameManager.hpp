#ifndef TWENTY_FOUR_GAME_MANAGER_HPP
#define TWENTY_FOUR_GAME_MANAGER_HPP

#include "GameManager.hpp"
#include "../Rules/FindValue.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class TwentyFourGameManager: public GameManager, public FindValue{
    private:
        ArrOfPlayer<CandyGamePlayer>* player;
        vector<string> solutions;
        CardCollection<DeckCard> playCards;
        string operationText;
    public:
        TwentyFourGameManager();
        void findTwentyFour();
        bool parseCommand(string);
        double value(double a, int op, double b);
        string concateOperationsstring(string a, int op, string b);
        string concatestringOp(string a, int op, double b);
        string concateOpstring(double a, int op, string b);
        string makestringFromOp(double a, int op, double b);
        void found();
        string getSolution(int);
        int getNumSolution();
};

#endif