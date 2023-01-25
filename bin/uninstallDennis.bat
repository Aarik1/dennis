rem Remove registery key for DennisCore
reg delete "HKCU\Software\Microsoft\Windows\CurrentVersion\Run" /v "DennisCore.exe" /f
rem Kill DennisCore.exe
taskkill /IM "DennisCore.exe" /F
rem Remove the executables and dectalk dictionary
del DennisCore.exe
del dtalk_us.dicdel dtspeak.dll