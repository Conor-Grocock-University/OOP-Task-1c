#include <iostream>
#include <string>
#include "Application.h"
#include "Account.h"
#include "User.h"
#include "Player.h"
#include "Admin.h"
#include "Utils.h"
#include "MainMenu.h"
#include "List.h"

// TODO: Remove from global scope once menu system is integrated
Application app;

void createHardcodedTestData()
{
	// Setup store with some games
	app.GetStore().games.addAtEnd(new Game("The Witness", "Explore a nice island and solve puzzles.", 2999, 5));
	app.GetStore().games.addAtEnd(new Game("Braid", "A time twisting puzzle game.", 499, 15));
	app.GetStore().games.addAtEnd(new Game("Factorio", "Build a complicated factory in space.", 1599, 12));
	app.GetStore().games.addAtEnd(new Game("LIMBO", "Watch out for that spider.", 299, 12));
	app.GetStore().games.addAtEnd(new Game("INSIDE", "What are those scientists even doing?!", 1299, 15));
	app.GetStore().games.addAtEnd(new Game("Portal 2", "Play around with physics. Shoot the moon.", 1999, 15));
	app.GetStore().games.addAtEnd(new Game("Half Life 3", "It's never coming out.", 5999, 18));
	app.GetStore().games.addAtEnd(new Game("NUVAVULT", "A game where 2D and 3D collide.", 299, 18));
	app.GetStore().games.addAtEnd(new Game("Brothers", "Split your brain into two thumbs.", 799, 15));

	// Create some users
	Player* u1 = new Admin("Alice", "password", Date("16-09-2018"));
	Player* u2 = new Player("Bob", "password", Date("13-09-2018"));
	Player* u3 = new Player("Charlie", "password", Date("24-09-2018"));

	// With some games in their library
	u1->library.push_back(new LibraryItem(Date("17-09-2019"), app.GetStore().games[7]));
	u1->library.push_back(new LibraryItem(Date("18-06-2018"), app.GetStore().games[1]));

	u2->library.push_back(new LibraryItem(Date("19-09-2018"), app.GetStore().games[2]));
	u2->library.push_back(new LibraryItem(Date("19-09-2018"), app.GetStore().games[3]));

	u3->library.push_back(new LibraryItem(Date("24-09-2018"), app.GetStore().games[3]));
	u3->library.push_back(new LibraryItem(Date("30-09-2018"), app.GetStore().games[6]));

	// Make an account and attach the users
	app.accounts.addAtEnd(new Account("alice@shu.com", "password", Date("16-06-2018")));
	app.accounts[0]->users.addAtEnd(u1);
	app.accounts[0]->users.addAtEnd(u2);
	app.accounts[0]->users.addAtEnd(u3);
	
	app.accounts.addAtEnd(new Account("chris@shu.com", "ballsack", "13-09-2020"));
	app.accounts[1]->users.addAtEnd(u3);
	app.accounts[1]->users.addAtEnd(u1);
	app.accounts[1]->users.addAtEnd(u2);
}

void main()
{
    // TODO: Remove call to dummy data, instead use Load and Save
    createHardcodedTestData();

    // TODO: app.Load();

    Menu::MainMenu("Main", &app); // TODO: replace with proper menu system

    // TODO: app.Save();
}
