// ==================[Copyright Aarik R. 2023]==================
// Purpose : Dectalk interface
//
//
// =============================================================

#ifndef INTERFACE_H
#define INTERFACE_H
#ifdef __cplusplus
extern "C"
{
#endif
	void __declspec(dllimport) DennisVolume(int volume);
	void __declspec(dllimport) DennisSpeak(const char* message);
	int __declspec(dllimport) DennisStartup();
	int __declspec(dllimport) DennisShutdown();
	
#ifdef __cplusplus
}
#endif

#endif // INTERFACE_H