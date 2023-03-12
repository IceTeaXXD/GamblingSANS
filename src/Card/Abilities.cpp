#include "Abilities.hpp"
REROLL::REROLL(){ this-> type = "reroll"; }

Quadruple::Quadruple(){ this-> type = "quadruple"; }

Quarter::Quarter(){this-> type = "quarter";}

ReverseDirection::ReverseDirection(){ type = "reverse"; }

SwapCard::SwapCard(){type = "swap";}

Switch::Switch(){type = "switch";}

Abilityless::Abilityless(){type = "abilityless"; }

void AbilityCard::printInfo()
{
    cout<<"ABILITY CARD"<<endl;
}

void REROLL::printInfo()
{
    cout<<"REROLL"<<endl;
}

void Quadruple::printInfo()
{
    cout<<"QUADRUPLE"<<endl;
}

void Quarter::printInfo()
{
    cout<<"QUARTER"<<endl;
}

void ReverseDirection::printInfo()
{
    cout<<"REVERSE DIRECTION"<<endl;
}

void SwapCard::printInfo()
{
    cout<<"SWAP CARD"<<endl;
}

void Switch::printInfo()
{
    cout<<"SWITCH"<<endl;
}

void Abilityless::printInfo()
{
    cout<<"ABILITYLESS"<<endl;
}