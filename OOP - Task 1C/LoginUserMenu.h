#pragma once
#include "Menu.h"
namespace Menu {
    class LoginUserMenu : public Menu
    {
    public:
        LoginUserMenu(const std::string& title, Application* app);
        void OutputOptions() final;
        bool HandleChoice(char choice) final;
        bool processUserSelection(char choice);
        bool processAccountSelection(char choice);
        void presentUsers();
        void presentAccounts();
    };
};