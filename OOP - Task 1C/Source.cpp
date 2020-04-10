#include "Application.h"
#include "MainMenu.h"

void main()
{
    Application app;
    app.load();
    Menu::MainMenu menuSystem("Main", &app);
    app.save();
}
