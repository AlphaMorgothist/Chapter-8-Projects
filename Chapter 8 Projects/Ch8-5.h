#pragma once
#include "Ch8-4.h"

class RPSplayer {
public:
	RPSplayer(string &name);
	const vector<string> hand = { "void", "Rock", "Paper", "Scissors", "void" };
	string curhand;
	string name;
	int wins = 0;
	int GetInput();
};
class RPS {
public:
	RPS(RPSplayer &p1, RPSplayer &p2);
	void Options();
	bool won = false;
};
RPSplayer::RPSplayer(string & name) :
	name(name) {}
int RPSplayer::GetInput()
{
	int hand[1];
	cout << "\n" << name << "'s selection: ";
	for (int i = 0; i < 1; i++)
	{
		hand[0] = _getch() - '0';

		cout << "*";
	}
	if (hand[0] <= 4 && hand[0] != 0) {
		return hand[0];
	}
	else { return 4; }
}
RPS::RPS(RPSplayer &p1, RPSplayer &p2) {
	while (won != true) {
		if (p1.wins >= 5) {
			cout << "\n" << p1.name << " has won the game!" << endl;
			Sleep(2000);
			won = true;
			break;
		}
		if (p2.wins >= 5) {
			cout << "\n" << p2.name << " has won the game!" << endl;
			Sleep(2000);
			won = true;
			break;
		}
		Options();
		p1.curhand = p1.hand[p1.GetInput()];
		p2.curhand = p2.hand[p2.GetInput()];
		system("CLS");
		if (p1.curhand == "void") {
			srand(time(NULL));
			int num = rand() % 2 + 1;
			p1.curhand = p1.hand[num];
		}
		if (p2.curhand == "void") {
			srand(time(NULL));
			int num = rand() % 2 + 1;
			p2.curhand = p2.hand[num];
		}
		cout << p1.name << "'s hand: " << p1.curhand << endl;
		cout << p2.name << "'s hand: " << p2.curhand << endl;
		cout << "\nThe winner of this round is...";
		if (p1.curhand == "Rock") {
			if (p2.curhand == "Paper") {
				cout << p2.name << "!" << endl; \
					p2.wins++;
			}
			else if (p2.curhand == "Rock") {
				cout << "\nTie Game!\n" << endl;
			}
			else if (p2.curhand == "Scissors") {
				cout << p1.name << "!" << endl;
				p1.wins++;
			}
		}
		if (p1.curhand == "Paper") {
			if (p2.curhand == "Scissors") {
				cout << p2.name << "!" << endl; \
					p2.wins++;
			}
			else if (p2.curhand == "Paper") {
				cout << "\nTie Game!\n" << endl;
			}
			else if (p2.curhand == "Rock") {
				cout << p1.name << "!" << endl;
				p1.wins++;
			}
		}
		if (p1.curhand == "Scissors") {
			if (p2.curhand == "Rock") {
				cout << p2.name << "!" << endl; \
					p2.wins++;
			}
			else if (p2.curhand == "Scissors") {
				cout << "\nTie Game!\n" << endl;
			}
			else if (p2.curhand == "Paper") {
				cout << p1.name << "!" << endl;
				p1.wins++;
			}
		}
	}
}
void RPS::Options() {
	cout << "\n\tChoose your hand!\n\tOr input '4' for a random one!" << endl;
	cout << "\n1: Rock\n2: Paper\n3: Scissors" << endl;
}
void playRPS() {
	string intro = "\n\t\tWelcome to Rock Paper Scissors!\nTo start, please enter two player names.\n";
	printSlow(intro);
	cin.ignore();
	string name1 = getName();
	string name2 = getName();
	RPSplayer player1(name1);
	RPSplayer player2(name2);
	string getready = "Thank you. Now loading the game.";
	printSlow(getready);
	Sleep(3000);
	system("CLS");
	RPS game(player1, player2);
}