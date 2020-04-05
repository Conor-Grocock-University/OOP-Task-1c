#pragma once

#include <memory>
#include <string>

class Game
{
public:
    Game(const int& id, const std::string&, const std::string&, int, int);
    ~Game();

    const std::string& GetName() const;
    const std::string& GetDescription() const;
    int GetCost() const;
    int GetAgeRating() const;
    int getId();

private:
    std::string name;
    std::string description;
    int cost;
    int ageRating;
    int id;
};
