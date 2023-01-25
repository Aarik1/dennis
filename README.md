# Dennis

## What is Dennis?

Dennis is a desktop pet that is unintrusive and will never get in your way. All he ever will do is say Dennis every few minutes.

## How do I compile him?

You will need CMake.

First create the standard build folder and run this command within it

cmake -A Win32 ..

Then open the solution and compile DennisCore.

After that run updateInstallFiles.bat

This will convert the built files into headers. 
They are included in DennisInstaller so they can be dropped during install.

Congrats you have successfully compiled Dennis!

## Credits

Dectalk

https://github.com/AntumDeluge/bin2header