#include "LoginUserMenu.h"
namespace Menu {

    LoginUserMenu::LoginUserMenu(const std::string& title, Application* app) : Menu(title, app)
    {
        Paint();
    }

    void LoginUserMenu::OutputOptions()
    {
        if (app->IsAccountLoggedIn())
            presentUsers();
        else
            presentAccounts();
    }

    bool LoginUserMenu::HandleChoice(char choice)
    {

        if (app->IsAccountLoggedIn())
            return processUserSelection(choice);
        
        return processAccountSelection(choice);
    }


    bool LoginUserMenu::processAccountSelection(char choice)
    {
        const int selected = choice - '1';

        const std::string email = app->accounts[selected]->GetLoginCredentials()[0];
        const std::string password = Question("Password");

        const bool success = app->LoginAccount(email, password);
        if (!success) BlockingMessage("Incorrect password");

        LoginUserMenu("Select user", app);
        return success;
    }

    bool LoginUserMenu::processUserSelection(char choice)
    {
        const int selected = choice - '1';

        const std::string* username = &app->GetCurrentAccount()->users[selected]->GetUsername();
        const std::string password = Question("Password");

        const bool success = app->LoginUser(*username, password);
        if (!success) BlockingMessage("Incorrect password");
        return success;
    }

    void LoginUserMenu::presentUsers()
    {
        for (int i = 0; i < app->GetCurrentAccount()->users.length(); i++)
        {
            // adding 1 so the display is nicer for the user
            Option(i + 1, app->GetCurrentAccount()->users[i]->GetUsername());
        }
    }

    void LoginUserMenu::presentAccounts()
    {
        for (int i = 0; i < app->accounts.length(); i++)
        {
            Option(i + 1, app->accounts[i]->GetLoginCredentials()[0]);
        }
    }
};