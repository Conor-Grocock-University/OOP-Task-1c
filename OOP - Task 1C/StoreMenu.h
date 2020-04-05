#pragma once

#include "Menu.h"
#include "Store.h"
#include <string>
#include <vector>

namespace Menu {
    class StoreMenu : public Menu
    {
    public:
        StoreMenu(const std::string& title, Application* app);
        void OutputOptions() final;
        bool HandleChoice(char choice) final;
    private:
        List<Game*> searchedGames = nullptr;
    };
};