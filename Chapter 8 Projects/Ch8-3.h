#pragma once
#include "Ch8-2.h"

class Alien {
public:
	Alien(int health = 5);
	void Takedamage();
	void Regenerate();
private:
	int m_Health;
};
class Player {
public:
	Player(int ammo = 3);
	void Blast(Alien &anAlien);
	void Reload();
private:
	int m_Ammo;
};
Alien::Alien(int health) :
	m_Health(health)
{
	cout << "\nAn alien warrior stands before you!" << endl;
}
void Alien::Takedamage()
{
	if (m_Health > 0) {
		m_Health--;
		if (m_Health <= 0) {
			cout << "The alien takes a direct shot, and falls over dead." << endl;
		}
		cout << "Alien health left: " << m_Health << endl;
	}
	else { cout << "The alien is dead!" << endl; }
}
void Alien::Regenerate()
{
	if (m_Health > 0) {
		m_Health++;
		cout << "The alien has regenerated some health!" << endl;
		cout << "Alien health left: " << m_Health << endl;
	}
	else { cout << "The alien is dead!" << endl; }
}

Player::Player(int ammo) :
	m_Ammo(ammo)
{
}
void Player::Blast(Alien & anAlien)
{
	if (m_Ammo > 0) {
		m_Ammo--;
		cout << "\nYou aim your weapon and fire at the alien menace" << endl;
		Sleep(1000);
		string pew = "Pew pew!\n";
		printSlow(pew);
		srand(time(NULL));
		int chance = rand() % 100;
		if (chance >= 50) {
			cout << "\nYour aim is true, and your shot hits the alien scum" << endl;
			anAlien.Takedamage();
		}
		else {
			cout << "\nYour shot missed!" << endl;
			anAlien.Regenerate();
		}
		cout << "Shots left: " << m_Ammo << endl;
	}
	else {
		cout << "\nYou do not have any ammo to shoot with!" << endl;
	}
}
void Player::Reload()
{
	cout << "\nYou reload your weapon" << endl;
	m_Ammo = 4;
}
void alienOption() {
	cout << "\nWhat would you like to do?" << endl;
	cout << "\n1: Shoot at the alien" << endl;
	cout << "2: Reload" << endl;
	cout << "3: Quit" << endl;
}
void playAlien() {
	bool quit = false;
	Player play;
	cout << "\n\t\tWelcome to";
	string intro = "...\n\t\tALIEN BLASTERRRR!!!!\n";
	printSlow(intro);
	Alien al;
	while (quit != true) {
		alienOption();
		int choice = getInput();
		switch (choice) {
		case 1: {play.Blast(al); }break;
		case 2: {play.Reload(); }break;
		case 3: {quit = true; }break;
		case 10: {al.Takedamage(); }break;
		}
	}
}

