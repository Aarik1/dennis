// ==================[Copyright Aarik R. 2023]==================
// Purpose : Basic application class
//
//
// =============================================================

#ifndef APP_H
#define APP_H

#include "dennis.h"

class DENNISAPP {
public:
	void Start();
	void Stop();
	CDennis* dennisInstance;
};

#endif // APP_H