#pragma once

#include "Menu.h"
#include "StoreMenu.h"

namespace Menu {
    class MainMenu : public Menu
    {
    public:
        MainMenu(const std::string& title, Application* app);
        void OutputOptions() final;
        bool HandleChoice(char choice) final;
    };
};