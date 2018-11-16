# 3rd Party Static Libraries Folder.

-- WXWIDGETS : 
To build goto https://wxwidgets.org/downloads/
Download Source Code. 

Compile using CMAKE with options:
CMAKE_BUILD_TYPE = static

If there is an error in file private.h line 149, change code
static_cast to reinterpret_cast.

After build is complete, move .a libraries into ./lib folder and rename those who do not have
'lib' in the beginning of the filename. 

Next look for file setup.h in the build directory where .a libraries were built. 
Move that file to "\SCF\include\wx" if necessary. Right now this file exists already. 

If there are any problems, contact me.

-- WXWIDGETS