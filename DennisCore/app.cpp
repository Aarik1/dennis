// ==================[Copyright Aarik R. 2023]==================
// Purpose : Basic application class
//
//
// =============================================================

#include "app.h"

void DENNISAPP::Start() {
	dennisInstance = new CDennis();
	dennisInstance->Startup();
}	