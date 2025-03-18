
DEL *.obj
DEL *.exe

set src=%1
cl.exe /c /EHsc *.c
link.exe /LIBPATH:C:\freeglut\lib\x64 *.obj /OUT:demo.exe

DEL *.obj