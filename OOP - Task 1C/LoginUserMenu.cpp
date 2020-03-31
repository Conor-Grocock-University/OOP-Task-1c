#include "LoginUserMenu.h"

LoginUserMenu::LoginUserMenu(const std::string& title, Application* app) : Menu(title, app)
{
    Paint();
}

void LoginUserMenu::OutputOptions()
{
    if (app->IsAccountLoggedIn())
    {
        for (int i = 0; i < 3; i++)
        {
            // adding 1 so the display is nicer for the user
            Option(i + 1, app->GetCurrentAccount()->users[i]->GetUsername());
        }
    }
}

bool LoginUserMenu::HandleChoice(char choice)
{
    const int selected = choice - '1';

    const std::string* username = &app->GetCurrentAccount()->users[selected]->GetUsername();
    const std::string password = Question("Password");

    const bool success = app->LoginUser(*username, password);
    if (!success) BlockingMessage("Incorrect password");
    return success;
}
