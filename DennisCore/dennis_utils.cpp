// ==================[Copyright Aarik R. 2023]==================
// Purpose : Dennis utilities
//
//
// =============================================================

#include "dennis_utils.h"
#include <random>

bool dennis_Chance(int roof, int chance) {

	if (rand() % roof < chance) {
		return true;
	}
	else {
		return false;
	}

}

float clip(float n, float lower, float upper) {
	return std::max(lower, std::min(n, upper));
}