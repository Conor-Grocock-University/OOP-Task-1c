#include "StoreMenu.h"
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
                Option(i + 1, app->GetStore().games[i]->GetName());
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
                Option(i + 1, searchedGames[i]->GetName());
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
            BlockingMessage("Not implemented, press return to continue");
            // go to game detail page
        }

        switch (choice)
        {
            case 'N':
                searchedGames = app->GetStore().SearchByName(Question("Enter Game Title")); // populating the store menus list of games with the searched games
                OutputOptions();
                break;
            case 'P':
                // storing question outputs in local variable as can't pass through 2 calls to the question 
                int min;
                int max;

                searchedGames = app->GetStore().SearchByPriceRange(Utils::toInt(Question("Enter Minimum Value")), Utils::toInt(Question("Enter Maximum Value")));
                OutputOptions();
                break;
        }
        return false;
    }
};