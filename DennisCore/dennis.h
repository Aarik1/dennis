// ==================[Copyright Aarik R. 2023]==================
// Purpose : The main Dennis class.
//
//
// =============================================================

#ifndef DENNIS_H
#define DENNIS_H
#include "interface.h"
#include <string>
#include <algorithm>

// Dennis class, controls dennis' behaviour as a "desktop pet"
class CDennis {
public:

	CDennis();

	void Startup();
	void Shutdown();

	// Tells dectalk to speak a message
	void Speak(std::string message);

	// Ticks dennis' state
	void Tick();

};

#endif // DENNIS_H