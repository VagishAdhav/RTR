DEL *.exe
DEL *.obj
cl.exe /c /EHsc OGL.c  LSystemTree.c
rc.exe OGL.rc
link.exe OGL.obj LSystemTree.obj OGL.res User32.lib Kernel32.lib GDI32.lib /SUBSYSTEM:WINDOWS