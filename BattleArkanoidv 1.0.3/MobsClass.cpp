#include "MobsClass.h"
#include "MainFunctionsLib.h"
#include "MainCharacter.h"
#include "Random.h"
#include <random>
#include <time.h>

Random RandomIntMobs;

void MobsClass::InitLocationMobs() {
	MobsX = RandomIntMobs.getInt(0, 19);
	MobsY = RandomIntMobs.getInt(4, 28);
}

void MobsClass::Direction(int MoveKeyCharacter) {
	if (MoveKeyCharacter >= 0 && MoveKeyCharacter <= 3)
		DirectionMove = RandomIntMobs.getInt(0, 3);
	else DirectionMove = 4;
}

int MobsClass::ReturnMobsX() {
	return MobsX;
}

int MobsClass::ReturnMobsY() {
	return MobsY;
}

void MobsClass::MoveMobs(char Map[20][30]) {
	switch (DirectionMove) {
	case 0: if (MobsY > 0) MobsY--; else MobsY = 0; break;
	case 1: if (MobsY < 28) MobsY++; else MobsY = 28; break;
	case 2: if (MobsX > 0) MobsX--; else MobsX = 0; break;
	case 3: if (MobsX < 19) MobsX++; else MobsX = 19; break;
	default: break;
	}
	Map[MobsX][MobsY] = MobsIcon;
}

MobsClass::MobsClass() {

}


MobsClass::~MobsClass() {

}