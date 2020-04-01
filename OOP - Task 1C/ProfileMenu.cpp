#include "ProfileMenu.h"
#include "LoginUserMenu.h"

Menu::ProfileMenu::ProfileMenu(const std::string username, Application* app) :Menu(username, app)
{
    Paint(); // required in constructor
}

void Menu::ProfileMenu::OutputOptions()
{
    Option('A', "Add credit");




}

bool Menu::ProfileMenu::HandleChoice(char choice)
{
    switch (choice)
    {


       case 'A':
          // app->accounts.
           return true;
           break;
        default:
        {
            BlockingMessage("Undefined case");
            break;
        }

    }
}

