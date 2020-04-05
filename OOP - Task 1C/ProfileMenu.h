#pragma once
#include "Menu.h"
#include <algorithm>
namespace Menu {
    class ProfileMenu : public Menu
    {
    public:
        ProfileMenu(const std::string username, Application* app);

        void OutputOptions() final;
        bool HandleChoice(char choice) final;

        
    };
};

