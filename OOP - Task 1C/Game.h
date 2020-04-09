#pragma once

#include <string>

class Game
{
public:
    Game(const int& id, const std::string&, const std::string&, int, int);
    ~Game();

    const std::string& GetName() const;
    const std::string& GetDescription() const;
    double GetCost() const;
    int GetAgeRating() const;
    int GetId() const;

private:
    int id;
    std::string name;
    std::string description;
    double cost;
    int ageRating;
};
