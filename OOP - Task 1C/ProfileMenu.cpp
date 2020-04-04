#include "Application.h"
#include "ProfileMenu.h"
#include "LoginUserMenu.h"

namespace Menu{
    ProfileMenu::ProfileMenu(const std::string username, Application* app) :Menu(username, app)
    {
        Paint(); // required in constructor

    }

    
    
    void ProfileMenu::OutputOptions()
    {
        if (app->IsUserAdmin(app->GetCurrentUser()) == true)
        {
            Option('A', "Create New Player");
            Option('B', "Delete Player");
        }


        Player* player = (Player*)app->GetCurrentUser();
        
        std::cout << "Credit: " << char(156);
        printf("%.2f", (double)player->GetCredit());
        std::cout << "\n";
        Option('T', "Deposit 10 Pounds");
        Option('F', "Deposit 50 Pounds");
        Option('O', "Deposit 100 Pounds");
    }

    bool ProfileMenu::HandleChoice(char choice)
    {
        Player* player = (Player*)app->GetCurrentUser();
        switch (choice)
        {
            if (app->IsUserAdmin(player))
            {

        case 'A':
            ///
            ///TODO: Admin controls
            ///
            LoginUserMenu::presentUsers();
            break;
        case 'B':

            break;
            }
        case 'T':
            player->AddCredit(10);
            break;
        case 'F':
            player->AddCredit(50);
            break;
        case 'O':
            player->AddCredit(100);
            break;
        default:
        {
            BlockingMessage("Undefined case");
            break;
        }

        }
        return false;
    }
    
};
