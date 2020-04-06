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

		Line();
		std::cout << "Credit: " << char(156);
		printf("%.2f", (double)player->GetCredit());
		Line();
		Option('T', "Deposit 10 Pounds");
		Option('F', "Deposit 50 Pounds");
		Option('O', "Deposit 100 Pounds");
		Line();

		if (player->library.size() != 0) // if the player has owned games
		{
			Line("Owned Games: ");
			Line();

			for (int i =0; i <= player->library.size() -1 ; i++)
				Option(i + 1, player->library[i]->GetGame()->GetName() + " - Purchased - " + player->library[i]->GetPurchaseDate().ToFormattedString());

			Line();
			Option('N', "Sort By Name");
			Option('P', "Sort By Date of Purchase");
		}
	}


	bool ProfileMenu::HandleChoice(char choice)
	{
		Player* player = (Player*)app->GetCurrentUser();
		std::string answer;
		std::string username;
		std::string password;

		switch (choice)
		{
		case 'C': {
			username = Question("Enter username for new Player");
			password = Question("Enter password for Player " + username);
			answer = Question("Is " + username + " an Admin? Y/N");
			if (answer == "Y" || answer == "y")
			{
				app->GetCurrentAccount()->AddAdmin(username, password); // creating new admin
				BlockingMessage("Player " + username + " created!");
			}
			else
				app->GetCurrentAccount()->AddPlayer(username, password); // creating new player
			break;
		}
		case 'D': {
			username = Question("Enter username of Player you wish to delete");
			User* user = app->GetCurrentAccount()->GetUser(username);
			if (user != nullptr)
			{
				answer = Question("Delete Player " + user->GetUsername() + " Y/N");
				if (answer == "Y" || answer == "y")
					app->GetCurrentAccount()->DeletePlayer(user);
			}
			else
				OutputOptions();
			break;
		}
		case 'T': {
			player->AddCredit(10);
			break;
		}
		case 'F': {
			player->AddCredit(50);
			break;
		}
		case 'O': {
			player->AddCredit(100);
			break;
		}
		case 'N': {
			std::sort(player->library.begin(), player->library.end(), Utils::SortByName); // sorting by name in ascending order, points to static utils function
			break;
		}
		case 'P': {
			std::sort(player->library.begin(), player->library.end(), Utils::SortByDate);
			break;
		}
		default: {
			BlockingMessage("Undefined case");
			break;
		}
		}
		return false;
	}
	
	
};
