#include <iostream>
#include <string>
#include "Application.h"
#include "Account.h"
#include "User.h"
#include "Player.h"
#include "Admin.h"
#include "DataParser.h"
#include "Utils.h"
#include "MainMenu.h"
#include "List.h"

void main()
{
    Application app;
    app.load();

    Menu::MainMenu menuSystem("Main", &app);

    app.save();
}
