#pragma once
#include "Ch8-3.h"

string getName() {
	string name;
	//cin.ignore();
	cout << "\nInput a name for a player: ";
	getline(cin, name);
	if (name != "" && name != " ") {
		return name;
	}
	else { name = "Derpy Mcderp"; return name; }
}
class Stickpile {
public:
	Stickpile(int numsticks);
	void Remove(int sticks);
	void Display();
	int Checkwon();
private:
	int m_Numsticks;
};
class Stickplayer {
public:
	Stickplayer(string &name);
	string name;
	int Getinput();
};
class Stickgame {
public:
	Stickgame(Stickplayer &p1, Stickplayer &p2, Stickpile &sticks);
};
Stickpile::Stickpile(int numsticks) :
	m_Numsticks(numsticks) {}
void Stickpile::Remove(int sticks)
{
	m_Numsticks -= sticks;
}
void Stickpile::Display()
{
	system("CLS");
	cout << "Numer of sticks left: " << m_Numsticks << endl;
}
int Stickpile::Checkwon()
{
	if (m_Numsticks <= 0) { return 1; }
	else { return 0; }
}

Stickplayer::Stickplayer(string &name) :
	name(name) {}
int Stickplayer::Getinput()
{
	while (true) {
		cout << "\n" << name << "'s turn. Please enter a number of sticks between 1-4 to remove from the pile" << endl;
		int choice;
		cout << "Number: ";
		cin >> choice;
		system("CLS");
		if (choice > 4 || choice < 0) {
			cout << "\nPlease enter a valid number" << endl;
		}
		else {
			return choice;
		}
	}
}

Stickgame::Stickgame(Stickplayer &p1, Stickplayer &p2, Stickpile &sticks) {
	string intro = "\n\t\tWelcome to NIM.";
	string instruct = "\nEach player takes a turn removing up to 4 sticks from the pile\nThe player to pick up the last stick wins.\n";
	printSlow(intro);
	Sleep(200);
	printSlow(instruct);
	Sleep(2000);
	bool quit = false;
	while (quit != true) {
		sticks.Display();
		int p1rem = p1.Getinput();
		sticks.Remove(p1rem);
		int ifwon = sticks.Checkwon();
		if (ifwon == 1) {
			cout << "\n" << p1.name << " has won the game of NIM!" << endl;
			Sleep(2000);
			quit = true;
			break;
		}
		sticks.Display();
		int p2rem = p2.Getinput();
		sticks.Remove(p2rem);
		ifwon = sticks.Checkwon();
		if (ifwon == 1) {
			cout << "\n" << p2.name << " has won the game of NIM!" << endl;
			Sleep(2000);
			quit = true;
			break;
		}

	}
}//In progress
void playNIM() {
	cout << "Before we get started, please enter two player names." << endl;
	cin.ignore();
	string name1 = getName();
	string name2 = getName();
	Stickplayer player1(name1);
	Stickplayer player2(name2);
	cout << "\nHow many sticks would you like to play with?\nEnter number 4 or less to get a random pile of sticks." << endl;
	int num = getInput();
	if (num <= 4) {
		num = (rand() % 100 + 10) % 100;
	}
	Stickpile sticks(num);
	string getready = "Thank you. Now loading the game.";
	printSlow(getready);
	Sleep(3000);
	system("CLS");
	Stickgame game(player1, player2, sticks);
}