#pragma once
#include "Menu.h"
namespace Menu {
    class LoginUserMenu : public Menu
    {
    public:
        LoginUserMenu(const std::string& title, Application* app);
        void OutputOptions() final;
        bool HandleChoice(char choice) final;
    };
};