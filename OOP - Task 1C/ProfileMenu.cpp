#include "Application.h"
#include "ProfileMenu.h"
#include "LoginUserMenu.h"
#include "Utils.h"
#include <iostream>

namespace Menu {
	ProfileMenu::ProfileMenu(const std::string username, Application* app) :Menu(username, app)
	{
		Paint(); // required in constructor
	}

	void ProfileMenu::OutputOptions()
	{
		//Guest* guest;
		if (Utils::isUserAdmin(app->GetCurrentUser()))
		{
			Option('C', "Create New Player");
			Option('D', "Delete Player");
			Option('A', "Add Game To Guest Profile");
		}

		if (Utils::isUserPlayer(app->GetCurrentUser()))
		{
			Player* player = (Player*)app->GetCurrentUser();
			Line();
			std::cout << "Credit: " << char(156);
			printf("%.2f", (double)player->GetCredit());
			Line();
			Option('T', "Deposit 10 Pounds");
			Option('F', "Deposit 50 Pounds");
			Option('O', "Deposit 100 Pounds");
			Line();
			Line("Owned Games: ");

			if (!player->library.empty()) // if the player has owned games
			{
				Line();

				for (int i = 0; i <= player->library.size() - 1; i++)
				{
					LibraryItem* game = player->library[i];
					Option(i + 1, game->GetGame()->GetName() + " - Purchased - " + game->GetPurchaseDate().ToFormattedString() + " - Play time - " + Utils::formatPlaytime(game->GetPlaytime()));
				}

				Line();
				Option('G', "Play Game");
				Option('N', "Sort By Name");
				Option('P', "Sort By Date of Purchase");
			}

		}
		else if (Utils::isUserGuest(app->GetCurrentUser()))
		{
			if (!app->GetCurrentAccount()->GetAdmin()->guestLibrary.empty())
			{
				Line("Owned Games: ");
				Line();
				for (int i = 0; i <= app->GetCurrentAccount()->GetAdmin()->guestLibrary.size() - 1; i++)
				{
					LibraryItem* game = app->GetCurrentAccount()->GetAdmin()->guestLibrary[i];
					Option(i + 1, game->GetGame()->GetName() + " - Purchased - " + game->GetPurchaseDate().ToFormattedString() + " - Play time - " + Utils::formatPlaytime(game->GetPlaytime()));
				}
				Line();
				Option('G', "Play Game");
				Option('N', "Sort By Name");
			}
			

		}
	}

	void ProfileMenu::CreateNewPlayer(Player* player)
	{

		if (Utils::isUserAdmin(player))
		{
			std::string username = Question("Enter username for new Player");
			std::string password = Question("Enter password for Player " + username);
			app->GetCurrentAccount()->AddPlayer(username, password); // creating new player
			BlockingMessage("Player " + username + " created!");

		}
	}

	bool ProfileMenu::DeleteUser(Player* player)
	{
		if (Utils::isUserAdmin(player))
		{
			const std::string username = Question("Enter username of Player you wish to delete");
			User* user = app->GetCurrentAccount()->GetUser(username);
			if (user != nullptr)
			{
				const std::string answer = Question("Delete Player " + user->GetUsername() + " Y/N");
				if (answer == "Y" || answer == "y")
					app->GetCurrentAccount()->DeletePlayer(user);
			}
			return true;
		}
		return false;
	}

	void ProfileMenu::AddGameToGuest(Player* player)
	{
		if (Utils::isUserAdmin(player))
		{
			Line("Enter game to add to Guests games by entering corresponding number: ");
			const int index = Utils::getCharFromUser() - '1';
			if (index <= player->library.size() - 1)
			{
				app->GetCurrentAccount()->GetAdmin()->AddGuestGame(player->library[index]);
				BlockingMessage(player->library[index]->GetGame()->GetName() + "  added to Guests Games!");
			}
			else BlockingMessage("Enter corresponding number to game you wish to add");
		}
	}

	void ProfileMenu::UserPlayGame(Player* player)
	{
		int gameChoice = Utils::toInt(Question("Which game would you like to play? Enter Number: "));
		
		std::vector<LibraryItem*> library;
		if (Utils::isUserGuest(player))
			library = app->GetCurrentAccount()->GetAdmin()->guestLibrary;
		else
			library = player->library;

		for (int i = 0; i < library.size(); i++)
		{
			if (gameChoice == i + 1)
			{
				library.at(i)->addPlayTime();
				break;
			}
		}
	}

	bool ProfileMenu::HandleChoice(char choice)
	{
		Player* player = (Player*)app->GetCurrentUser();
		
		switch (choice)
		{
			case 'C':
				CreateNewPlayer(player);
				break;
			case 'D':
				if (DeleteUser(player)) break;
			case 'A':
				AddGameToGuest(player);
				break;
			case 'G':
				UserPlayGame(player);
				break;
			case 'T':
				player->AddCredit(10);
				break;
			case 'F': {
				player->AddCredit(50);
				break;
			}
			case 'O': {
				player->AddCredit(100);
				break;
			}
			case 'N': {
				if (Utils::isUserGuest(app->GetCurrentUser()))
				{
					player = app->GetCurrentAccount()->GetAdmin();
					if (!player->guestLibrary.empty())// if there are games in guest library
					{
						sort(player->guestLibrary.begin(), player->guestLibrary.end(), Utils::SortByName);

					}
				}
				else
					sort(player->library.begin(), player->library.end(), Utils::SortByName); // sorting by name in ascending order, points to static utils function
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
