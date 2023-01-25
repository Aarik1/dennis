// ==================[Copyright Aarik R. 2023]==================
// Purpose : The main Dennis class.
//
//
// =============================================================

#include "dennis.h"
#include "dennis_utils.h"
#include <iostream>
#include <filesystem>
#include <cstdlib>
#include <string>
#include <locale>
#include <cmath>
#include <fstream>

#include <Windows.h>
#include <ShObjIdl.h>

// Initialize Dennis' variables
CDennis::CDennis() {
}

void CDennis::Startup() {
	DennisStartup();
	DennisVolume(25);
}

void CDennis::Shutdown() {
	DennisShutdown();
}

void CDennis::Speak(std::string message) {
	DennisSpeak(message.c_str());
}

// Dennis tick
void CDennis::Tick() {
	
	// Bitch
	if (dennis_Chance(100, 10)) {
		DennisSpeak("[:nd]bitch.");
		return;
	}

	if (dennis_Chance(100, 1)) {
		DennisSpeak("[:nd]sliggit.");
	}

	// Dennis
	DennisSpeak("[:nd]dennis.");
	return;

}