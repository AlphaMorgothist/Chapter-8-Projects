#pragma once
#include "Ch8-1.h"

class Critter {
public:
	Critter(string name, int hunger, int boredom);
	void Talk();
	void Feed();
	void Play();
	void Passtime();
	void Trick();
private:
	string name;
	int m_Hunger;
	int m_Boredom;
	int GetMood();
};
Critter::Critter(string name, int hunger, int boredom) :
	m_Hunger(hunger), m_Boredom(boredom), name(name) {
	cout << "\nA new critter, named " << name << " is born!" << endl;
}
void Critter::Talk()
{
	int mood = GetMood();
	for (int i = mood; i < mood + 1; i++) {
		if (i > 15) {
			cout << "Your creature, " << name << ", is angry" << endl;
		}
		else if (i > 10) {
			cout << "Your creature, " << name << ", is slightly upset" << endl;
		}
		else if (i > 5) {
			cout << "Your creature, " << name << ", is doing alright" << endl;
		}
		else if (i <= 5) {
			cout << "Your creature, " << name << ", is feeling fine!" << endl;
		}
	}
}
void Critter::Feed()
{
	cout << "Your creature, " << name << ", eats and is fully fed" << endl;
	m_Hunger = 0;
	Passtime();
}
void Critter::Play()
{
	cout << "You spend a good amount of time playing with " << name << endl;
	m_Boredom = 0;
	Passtime();
}
void Critter::Passtime()
{
	m_Hunger++;
	m_Boredom++;
}
void Critter::Trick()
{
	cout << "Your creature " << name << " performs an awesome-ass trick...with it's ass" << endl;
	Passtime();
}
int Critter::GetMood()
{
	int mood = m_Boredom + m_Hunger;

	return mood;
}
void critOption() {
	cout << "\nWhat would you like to do?" << endl;
	cout << "\n1: Talk" << endl;
	cout << "2: Feed" << endl;
	cout << "3: Play" << endl;
	cout << "4: Trick" << endl;
	cout << "5: Quit" << endl;
}
void playCrit() {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << "Welcome to critter farm" << endl;
	Sleep(1000);
	string intro = "\nYour critters will now be spawned... one moment\n";
	for (int i = 0; i < intro.size(); i++)
	{
		cout << intro[i];
		if (intro[i] == '.') {
			Sleep(1000);
		}
		else { Sleep(100); }
	}
	Sleep(1000);
	srand(time(NULL));
	int num1 = rand() % 10 + 1;
	int num2 = rand() % 11;
	Critter crit1("Cretien", 0, 0);
	Sleep(500);
	Critter crit2("Derek", num1, num2);
	Sleep(500);
	Critter crit3("LeeLee", num1, num2);
	Sleep(500);
	Critter crit4("NeeSee", num1, num2);
	Sleep(500);
	Critter crit5("Joe Dirt", num2, num1);
	bool quitcrit = false;
	while (quitcrit != true) {
		critOption();
		int choice = getInput();
		switch (choice) {
		case 1: {
			SetConsoleTextAttribute(h, 0xF0);
			crit1.Talk();
			crit2.Talk();
			crit3.Talk();
			crit4.Talk();
			crit5.Talk();
			SetConsoleTextAttribute(h, 0x0F);
		}break;
		case 2: {
			SetConsoleTextAttribute(h, 0xF0);
			crit1.Feed();
			crit2.Feed();
			crit3.Feed();
			crit4.Feed();
			crit5.Feed();
			SetConsoleTextAttribute(h, 0x0F); }break;
		case 3: {
			SetConsoleTextAttribute(h, 0xF0);
			crit1.Play();
			crit2.Play();
			crit3.Play();
			crit4.Play();
			crit5.Play();
			SetConsoleTextAttribute(h, 0x0F); }break;
		case 4: {
			SetConsoleTextAttribute(h, 0xF0);
			crit1.Trick();
			crit2.Trick();
			crit3.Trick();
			crit4.Trick();
			crit5.Trick();
			SetConsoleTextAttribute(h, 0x0F);
		}break;
		case 5: {quitcrit = true; break; }break;
		}
	}
}