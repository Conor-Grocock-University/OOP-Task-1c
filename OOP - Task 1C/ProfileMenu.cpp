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
		Player* player;
		Guest* guest;
		if (app->IsUserAdmin(app->GetCurrentUser()) == true)
		{
			Option('C', "Create New Player");
			Option('D', "Delete Player");
		}

		User* userType = (User*)app->GetCurrentUser();
		if (dynamic_cast<Player*>(userType))
		{
			player = (Player*)userType;
			Line();
			std::cout << "Credit: " << char(156);
			printf("%.2f", (double)player->GetCredit());
			Line();
			Option('T', "Deposit 10 Pounds");
			Option('F', "Deposit 50 Pounds");
			Option('O', "Deposit 100 Pounds");
			Line();
			Line("Owned Games: ");

			if (player->library.empty() == false) // if the player has owned games
			{
				Line();

				for (int i = 0; i <= player->library.size() - 1; i++)
				{
					Option(i + 1, player->library[i]->GetGameName() + " - Purchased - " + player->library[i]->GetDateOfPurchase().ToFormattedString());
				}

				Line();
				Option('N', "Sort By Name");
				Option('P', "Sort By Date of Purchase");
			}

		}
		else if (dynamic_cast<Guest*>(userType))
		{
			guest = (Guest*)userType;

			Line("Owned Games: ");

			if (guest->GetLibrary().empty() == false) // if the player has owned games
			{
				Line();

				for (int i = 0; i <= guest->GetLibrary().size() - 1; i++)
				{
					Option(i + 1, guest->GetLibrary()[i]->GetGameName());
				}

				Line();
				Option('N', "Sort By Name");
			}
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
				BlockingMessage("Player " + username + " created!");

			}
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

		case 'N':
			sort(player->library.begin(), player->library.end(), Utils::SortByName); // sorting by name in ascending order, points to static utils function

			break;

		case 'P':
			sort(player->library.begin(), player->library.end(), Utils::SortByDate);
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
