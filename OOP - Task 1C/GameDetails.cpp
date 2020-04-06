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
        std::cout << "  Price: " << char(156);
        printf("%.2f", (double)price); //Price to two decimal places
        Line();
        Line("Description: " + game->GetDescription()); // Game description
        Line();

        if (app->IsUserLoggedIn() && !app->IsUserGuest(app->GetCurrentUser())) { // if user is logged in and user is not a guest
            
                std::cout << "Your Credit: " << char(156) << dynamic_cast<Player*>(app->GetCurrentUser())->GetCredit();
                Line();
                Option('A', "Buy Game");
            
        
        }
    }

    bool GameDetails::HandleChoice(const char choice)
    {
        Player* player = (Player*)app->GetCurrentUser();
        switch (choice)
        {

        case 'A':
            if (app->IsUserLoggedIn() && !app->IsUserGuest(app->GetCurrentUser())) {
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
