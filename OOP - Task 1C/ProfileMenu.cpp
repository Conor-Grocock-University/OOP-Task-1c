#include "Application.h"
#include "ProfileMenu.h"
#include "LoginUserMenu.h"

namespace Menu {
	ProfileMenu::ProfileMenu(const std::string username, Application* app) :Menu(username, app)
	{
		Paint(); // required in constructor

	}



	void ProfileMenu::OutputOptions()
	{
		if (app->IsUserAdmin(app->GetCurrentUser()) == true)
		{
			Option('C', "Create New Player");
			Option('D', "Delete Player");
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
		std::string answer;
		std::string username;
		std::string password;
		switch (choice)
		{
			if (app->IsUserAdmin(player))
			{

		case 'C':
			///
			username = Question("Enter username for new Player");
			password = Question("Enter password for Player " + username);
			answer = Question("Is " + username + " an Admin? Y/N");
			if (answer == "Y" || answer == "y")
			{
				app->GetCurrentAccount()->AddAdmin(username, password); // creating new admin
			}
			///TODO: Admin controls
			else
			{
				app->GetCurrentAccount()->AddPlayer(username, password); // creating new player
			}

			///
			break;
		case 'D':
			username = Question("Enter username of Player you wish to delete");
			User* user = app->GetCurrentAccount()->GetUser(username);
			if (user != nullptr)
			{
				answer = Question("Delete Player " + user->GetUsername() + " Y/N");
				if (answer == "Y" || answer == "y")
				{
					app->GetCurrentAccount()->DeletePlayer(user);
				}
			}
			else
			{
				OutputOptions();
			}


			
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
