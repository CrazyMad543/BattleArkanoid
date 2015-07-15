#include "Random.h"

int Random::getInt(int min, int max) {
	return uniform_int_distribution<int>(min, max)(_rd);
}

Random::Random() {

}


Random::~Random() {

}