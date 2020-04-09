#include "Game.h"

Game::Game(const std::string& name, const std::string& desc, int cost, int rating)
    : name(name), description(desc), cost(cost), ageRating(rating)
{
}

Game::~Game()
{
}

const std::string& Game::GetName() const
{
    return name;
}

const std::string& Game::GetDescription() const
{
    return description;
}

double Game::GetCost() const
{
    return cost/100;
}

int Game::GetAgeRating() const
{
    return ageRating;
}
