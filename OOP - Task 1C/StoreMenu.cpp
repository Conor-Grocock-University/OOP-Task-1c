#include "StoreMenu.h"
#include "GameDetails.h"
namespace Menu {

    StoreMenu::StoreMenu(const std::string& title, Application* app) : Menu(title, app)
    {
        Paint(); // required in constructor
    }

    void StoreMenu::OutputOptions()
    {
        if (searchedGames == nullptr) // if there are no searched games
        {
            for (int i = 0; i < app->GetStore().games.length(); i++)
            {
                // adding 1 so the display is nicer for the user
                Option(i + 1, Utils::toUpperString(app->GetStore().games[i]->GetName()));
            }

            Line();
            Option('N', "Search By Name");
            Option('P', "Search By Price");
        }
        else
        {
            for (int i = 0; i < searchedGames.length(); i++)
            {
                // adding 1 so the display is nicer for the user
                Option(i + 1, Utils::toUpperString(searchedGames[i]->GetName()));
            }

        }
    }


    bool StoreMenu::HandleChoice(char choice)
    {
        // since we are using numbers here we shift the char down by '1'
        // this puts '1' as 0, '2' as 1, '3' as 2, '4' as 3, etc.
        // this reverses the + 1 above and lets us do the range check below
        const int index = choice - '1';
        if (index >= 0 && index < app->GetStore().games.length())
        {
            // go to game detail page

            if (searchedGames == nullptr)
                GameDetails(app->GetStore().games[index]->GetName(), app->GetStore().games[index], app);
            else
                GameDetails(searchedGames[index]->GetName(), searchedGames[index], app);
        }
        
        switch (choice)
        {
            case 'N':
                searchedGames = app->GetStore().SearchByName(Question("Enter Game Title")); // populating the store menus list of games with the searched games
                OutputOptions();
                break;
            case 'P':
                searchedGames = app->GetStore().SearchByPriceRange(Utils::toInt(Question("Enter Minimum value")), Utils::toInt(Question("Enter Maximum value")));
                OutputOptions();
                break;
        }
        return false;
    }
};