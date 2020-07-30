# fps-template
A template for creating first-person shooter games and 3D graphics projects in C++.
This creates a chunk-based world that the user can move around, using w,a,s,d to move
and using the mouse to look around.

## Build Instructions
If you are on windows, you need to download freeglut, make the
directory C:/Program Files/Common Files/freeglut/, copy the 
include/ and lib/ folders from freeglut into there, and copy
freeglut.dll from freeglut/bin/ into the cmake-build-debug/ folder.

If you are not on windows, maybe it will just work.
