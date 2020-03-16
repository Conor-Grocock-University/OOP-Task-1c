#pragma once
#include <string>
#include "Application.h"

class Menu
{
public:
    const std::string title;
protected:
    Application app;

public:
    Menu(const std::string title, Application app);
    Paint();

    OutputOptions();
    HandleChoice();

protected:
    Line();
    Line(const std::string title);

    Option(char id, std::string string);
    Option(int id, std::string string);

    std::string Question(std::string question);
    BlockingQuestion(std::string question);

private:
    Header();
    Footer();
};

