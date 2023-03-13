#include <iostream>
#include "AbilityCard.hpp"
using namespace std;

AbilityCard::AbilityCard()
{
    availability = true;
}
AbilityCard::AbilityCard(bool avail)
{
    availability = avail;
}

bool AbilityCard::isAvailable()
{
    return availability;
}

void AbilityCard::setNotAvailable()
{
    availability = false;
}

string AbilityCard::getType()
{
    return type;
}