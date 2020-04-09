#pragma once
#include "Menu.h"
#include <algorithm>

#include<vector>

namespace Menu {
    class ProfileMenu : public Menu
    {
    public:
        ProfileMenu(const std::string username, Application* app);

        void OutputOptions() final;
        bool HandleChoice(char choice) final;
        void UserPlayGame(Player* player);

        void UserPlayGame(int& gameChoice, Player* player);
    	
        void CreateNewPlayer(Player* player);
        bool DeleteUser(Player* player);
        void AddGameToGuest(Player* player);
    };
};

