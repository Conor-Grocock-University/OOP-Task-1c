#include "GameDetails.h"
#include "Utils.h"
#include "LoginUserMenu.h"
#include "MainMenu.h"

using namespace Menu;
    GameDetails::GameDetails(const std::string& title,Application* app,int i):index(i), Menu(title,app)
    {
        Paint();
    }

    void GameDetails::OutputOptions()
    {
    //displaying the game price
       int price = app->GetStore().games[index]->GetCost();
       std::cout << "Price: " << char(156);
       printf("%.2f",(double)price);
       std::cout << "\n\n";
       std::cout << "Description: " <<app->GetStore().games[index]->GetDescription();
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
           if(app->IsUserLoggedIn()){
            const std::string answer = Question("Are you sure? Y/N");
            if (answer == "y" || answer == "Y")
            {

                if (player->BuyGame(app->GetStore().games[index]))
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
    

