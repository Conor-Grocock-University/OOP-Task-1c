#include "MainMenu.h"
#include "LoginUserMenu.h"
#include "ProfileMenu.h"
namespace Menu {

    MainMenu::MainMenu(const std::string& title, Application* app) : Menu(title, app)
    {
        Paint(); // required in constructor
    }

    void MainMenu::OutputOptions()
    {
        Option('S', "Browse Store");

        if (app->IsUserLoggedIn())
        {
            Option('P', "View Profile");
            Option('L', "Logout");
        }
        else
        {
            Option('L', "Login");
        }
    }

    bool MainMenu::HandleChoice(const char choice)
    {
        switch (choice)
        {
        case 'S':
        {
            StoreMenu("STORE", app);
            break;
        }
        case 'L':
        {
            if (app->IsUserLoggedIn())
            {
                const std::string answer = Question("Are you sure? Y/N");
                if (answer == "y" || answer == "Y")
                {
                    app->LogoutUser();
                }
            }
            else
            {
                LoginUserMenu("Login", app);
            }
            break;
        }
        case 'P':
        {
            if (app->IsUserLoggedIn())
            {
               /* BlockingMessage("Not implemented, press return to continue");
                // this needs to go to a profile page - similar to StoreMenu
                // notice the if - this only works if somebody is logged in
                */
                   
                ProfileMenu(app->GetCurrentUser()->GetUsername(),app);
             
            }
            break;
        }
        default:
        {
            BlockingMessage("Undefined case");
            break;
        }
        }

        return false;
    }
};