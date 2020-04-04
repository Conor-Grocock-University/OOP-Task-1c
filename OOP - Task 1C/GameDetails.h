#pragma once
#include "Menu.h"
namespace Menu{
    class GameDetails : public Menu
    {
    public:
        //GameDetails(const std::string& title, Application* app);
        GameDetails(const std::string& title,const Game* game, Application* app);
        void OutputOptions() final;
        bool HandleChoice(char choice) final;
        const Game* game;
    };
}

