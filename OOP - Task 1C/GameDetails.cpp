#include "GameDetails.h"
#include "Utils.h"
#include "LoginUserMenu.h"
#include "MainMenu.h"
#include "StoreMenu.h"
#include "Menu.h"

namespace Menu {
 

    GameDetails::GameDetails(const std::string& title,const Game* game, Application* app):game(game),Menu(title,game,app)
    {
        Paint();
    }



    void GameDetails::OutputOptions()
    {
        //displaying the game price
        int price = game->GetCost();
        std::cout << "Price: " << char(156);
        printf("%.2f", (double)price); //Price to two decimal places
        std::cout << "\n\n";
        std::cout << "Description: " << game->GetDescription(); // Game description
        std::cout << "\n\n";

        if (app->IsUserLoggedIn()) {
            std::cout << "Your Credit: " << char(156) << dynamic_cast<Player*>(app->GetCurrentUser())->GetCredit() << "\n";
            Option('A', "Buy Game");
        }
    }

    bool GameDetails::HandleChoice(const char choice)
    {
        Player* player = (Player*)app->GetCurrentUser();
        switch (choice)
        {

        case 'A':
            if (app->IsUserLoggedIn()) {
                const std::string answer = Question("Are you sure? Y/N");
                if (answer == "y" || answer == "Y")
                {

                    if (player->BuyGame(game))
                    {
                        BlockingMessage("Game Purchased");

                    }
                    else
                    {
                        BlockingMessage("Insufficient Funds");

                    }
                }
                break;
            }
        default:
            BlockingMessage("Undefined case");
            break;

        }
        return false;
    }

};
