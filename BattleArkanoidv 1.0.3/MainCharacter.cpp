#include "MainFunctionsLib.h"
#include "MainCharacter.h"
#include "MobsClass.h"
#include "Random.h"
#include <random>
#include <time.h>

Random RandomIntCharacter;

int MainCharacter::ReturnCharacterX() {
	return CharacterX;
}

int MainCharacter::ReturnCharacterY() {
	return CharacterY;
}

void MainCharacter::InitLocationCharacter() {
	CharacterX = RandomIntCharacter.getInt(0, 19);
	CharacterY = RandomIntCharacter.getInt(0, 2);
}

int MainCharacter::MoveCharacter(char Map[20][30]) {
	int MoveKey = InputKey();
	switch (MoveKey) {
		case 0: if (CharacterY > 0) CharacterY--; else CharacterY = 0; break;
		case 1: if (CharacterY < 29) CharacterY++; else CharacterY = 29; break;
		case 2: if (CharacterX > 0) CharacterX--; else CharacterX = 0; break;
		case 3: if (CharacterX < 19) CharacterX++; else CharacterX = 19; break;
		default: break;
	}
	Map[CharacterX][CharacterY] = MainCharacterIcon;
	return MoveKey;
}

MainCharacter::MainCharacter() {

}

MainCharacter::~MainCharacter() {

}