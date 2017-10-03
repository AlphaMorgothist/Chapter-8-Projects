#pragma once
#include "stdafx.h"
#include <iostream>
#include <string>
#include <ctime>
#include <Windows.h>
#include <vector>
#include <algorithm>
#include <conio.h>
using namespace std;

void printSlow(string &string) {
	for (int i = 0; i < string.size(); i++)
	{
		Sleep(100);
		cout << string[i];
	}
}
class Enemy {
public:
	Enemy(string &name);
	void DisplayTactics();
	void debug();
	int m_Num = 0;
};
Enemy::Enemy(string &name)
{
	int id1 = rand() % 10000;
	cout << "\nAn enemy ship has entered the sector:" << endl;
	cout << "The ship's name is " << name << id1 << endl;
}
void Enemy::DisplayTactics()
{
	cout << "\nScans indicate there are " << m_Num << " ships in this sector\n";
	if (m_Num < 5) {
		cout << "Enemy ships set to DEFENSE" << endl;
	}
	else {
		cout << "Enemy ships set to AGGRESSIVE" << endl;
	}
}
void Enemy::debug()
{
	cout << "\nDebug: " << m_Num << endl;
}
void spawnEnemy5() {
	srand(time(NULL));
	string name = "Eb";
	for (int i = 0; i < 5; i++)
	{
		Enemy en4(name);
		en4.m_Num += 5;
		if (i == 4) { en4.DisplayTactics(); }
	}
	Sleep(4000);
	system("CLS");
}
void spawnEnemy() {
	srand(time(NULL));
	string name = "En";
	Enemy en1(name);
	Enemy en2(name);
	en2.m_Num += 2;
	en2.DisplayTactics();
	Sleep(4000);
	system("CLS");
}
int getInput() {
	cout << "\nPlease enter an option." << endl;
	cout << "Choice: ";
	int choice;
	cin >> choice;
	system("CLS");
	return choice;
}
void chapterOptions() {
	cout << "\n\t\tChapter 7 Projects" << endl;
	cout << "\n1: [Project 7.1] Two Ship-Class Spawn" << endl;
	cout << "2: [Project 7.1] Five Ship-Class Spawn" << endl;
	cout << "3: [Project 7.2] Critter Farm" << endl;
	cout << "4: [Project 7.3] Alien Blaster" << endl;
	cout << "5: [Project 7.4] OOP NIM!" << endl;
	cout << "6: [Project 7.5] Rock-Paper-Scissors" << endl;
	cout << "0: Quit" << endl;
}