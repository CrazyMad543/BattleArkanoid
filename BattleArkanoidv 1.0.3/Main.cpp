#include <iostream>
#include <conio.h>
#include "MainFunctionsLib.h"
#include <random>
#include <time.h>

using namespace std;

int main() {
	bool GameOverFinish;
	bool WinFinish;
	bool Continue = true;
	setlocale(LC_ALL, "Russian");
	while (Continue == true) {
		InitLocationAll();
		do {
			Init();
			Run();
			GameOverFinish = GameOver();
			WinFinish = Win();
		} while (!(GameOverFinish == true) && !(WinFinish == true));
		Continue = ChoiceContinue(WinFinish, GameOverFinish);
	}
	return 0;
}