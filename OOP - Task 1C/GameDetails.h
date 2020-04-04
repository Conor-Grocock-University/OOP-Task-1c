#pragma once
#include "Menu.h"
namespace Menu{
    class GameDetails : public Menu
    {
    public:
        GameDetails(const std::string& title, Application* app, static int i);
        void OutputOptions() final;
        bool HandleChoice(char choice) final;
        int index;
    };
}

