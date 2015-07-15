#include <iostream>
#include "MainCharacter.h"
#include "MobsClass.h"
#include "MainFunctionsLib.h"
#include <conio.h>
#include <vector>
#include "Random.h"

using namespace std;

Random MainRandom;
const int N = 20, M = 30;
char MoveButton;
int AmountMobs = MainRandom.getInt(75, 125);
vector<MobsClass> Mobs(AmountMobs);
char Map[N][M];
bool GameOverVar = false;
int AmountClicks = 0;
MainCharacter Character;

int InputKey() {
	if (AmountClicks == 0) {
		MoveButton = 'E';
		AmountClicks++;
	}
	else {
		MoveButton = (char)_getch();
		if (MoveButton == 'A' || MoveButton == 'a')
			return 0;
		if (MoveButton == 'D' || MoveButton == 'd')
			return 1;
		if (MoveButton == 'W' || MoveButton == 'w')
			return 2;
		if (MoveButton == 'S' || MoveButton == 's')
			return 3;
		AmountClicks++;
	}
}

void InitMap() {
	for (int i(0); i < N; i++) {
		for (int j(0); j < M; j++) {
			Map[i][j] = ' ';
		}
	}
}

bool Win() {
	bool CheckWin = false;
	for (int i(0); i < N; i++) {
		if (Map[i][29] != ' ')
			CheckWin = true;
	}
	return CheckWin;
}

void OutputMap() {
	system("cls");
	for (int i(0); i < N; i++) {
		for (int j(0); j < M; j++) {
			cout << Map[i][j];
			if (j == 28) 
				cout << '|';
		}
		cout << '|' << endl;
	}
}

void InitLocationAll() {
	Character.InitLocationCharacter();
	for (int i(0); i < Mobs.size(); i++) {
		Mobs.at(i).InitLocationMobs();
	} 
}

void Run() {
    Character.MoveCharacter(Map);
	for (int i(0); i < Mobs.size(); i++) {
		Mobs.at(i).MoveMobs(Map);
	}
	OutputMap();
}

void Init() {
	InitMap();
}

void CheckValue() {
	cin.clear();
	while (cin.get() != '\n');
	cout << "Неверное значение, введите еще раз: ";
}

bool GameOver() {
	GameOverVar = false;
	for (int i(0); i < AmountMobs; i++) 
		if (Character.ReturnCharacterX() == Mobs.at(i).ReturnMobsX()) {
			int temp = i;
			if (Character.ReturnCharacterY() == Mobs.at(temp).ReturnMobsY())
				GameOverVar = true;
		}
	return GameOverVar;
}

bool ChoiceContinue(bool WinBool, bool GameOverBool) {
	InitMap();
	OutputMap();
	bool Continue;
	if (WinBool == true) {
		cout << "Вы победили! Желаете продолжить? 1 - Да, 0 - Нет ";
		while (!(cin >> Continue)) 
			CheckValue();
		AmountClicks = 0;
		return Continue;
	}
	else if (GameOverBool == true) {
		cout << "Вы проиграли! Желаете продолжить? 1 - Да, 0 - Нет ";
		while (!(cin >> Continue))
			CheckValue();
		AmountClicks = 0;
		return Continue;
	}
}