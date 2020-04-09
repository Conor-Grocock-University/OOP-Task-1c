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
		//Guest* guest;
		if (Utils::isUserAdmin(app->GetCurrentUser()))
		{
			Option('C', "Create New Player");
			Option('D', "Delete Player");
			Option('A', "Add Game To Guest Profile");
		}

		if (Utils::isUserPlayer(app->GetCurrentUser()))
		{
			player = (Player*)app->GetCurrentUser();
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
		else if (Utils::isUserGuest(app->GetCurrentUser()))
		{
			//guest = (Guest*)app->GetCurrentUser();

			Line("Owned Games: ");


			Line();

			for (int i = 0; i <= app->GetCurrentAccount()->GetAdmin()->guestLibrary.size() - 1; i++)
			{
				Option(i + 1, app->GetCurrentAccount()->GetAdmin()->guestLibrary[i]->GetGameName());
			}

			Line();
			Option('N', "Sort By Name");

		}
	}


	bool ProfileMenu::HandleChoice(char choice)
	{

		Player* player = (Player*)app->GetCurrentUser();
		User* user;
		std::string answer;
		std::string username;
		std::string password;

		switch (choice)
		{


		case 'C':
			///
			if (Utils::isUserAdmin(player))
			{
				username = Question("Enter username for new Player");
				password = Question("Enter password for Player " + username);
				answer = Question("Is " + username + " an Admin? Y/N");
				if (answer == "Y" || answer == "y")
				{
					app->GetCurrentAccount()->AddAdmin(username, password); // creating new admin
					BlockingMessage("Player " + username + " created!");

				}
				else  app->GetCurrentAccount()->AddPlayer(username, password); // creating new player
			}
			///
			break;
		case 'D':
			if (Utils::isUserAdmin(player))
			{

				username = Question("Enter username of Player you wish to delete");
				user = app->GetCurrentAccount()->GetUser(username);
				if (user != nullptr)
				{
					answer = Question("Delete Player " + user->GetUsername() + " Y/N");
					if (answer == "Y" || answer == "y")
					{
						app->GetCurrentAccount()->DeletePlayer(user);
					}

				}
				break;

		case 'A':
			if (Utils::isUserAdmin(player))
			{
				Line("Enter game to add to Guests games by entering corresponding number: ");
				const int index = Utils::getCharFromUser() - '1';
				if (index <= player->library.size() - 1)
				{
					app->GetCurrentAccount()->GetAdmin()->AddGuestGame(player->library[index]);
					BlockingMessage(player->library[index]->GetGameName() + "  added to Guests Games!");
				}
				else BlockingMessage("Enter corresponding number to game you wish to add");

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
			if (Utils::isUserGuest(app->GetCurrentUser()))
			{
				sort(app->GetCurrentAccount()->GetAdmin()->guestLibrary.begin(), app->GetCurrentAccount()->GetAdmin()->guestLibrary.end(), Utils::SortByName);
			}
			else
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
