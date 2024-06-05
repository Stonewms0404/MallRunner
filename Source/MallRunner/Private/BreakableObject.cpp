#include "BreakableObject.h"

void ABreakableObject::CheckWeights(int playerWeight) {
	if (playerWeight > weight + 3) {
		canBreak = true;
		ChangeColor(1);
	}
	else if (playerWeight >= weight) {
		canBreak = rand() % 100 + 1 >= 50;
		ChangeColor(2);
	}
	else {
		canBreak = false;
		ChangeColor(3);
	}
}