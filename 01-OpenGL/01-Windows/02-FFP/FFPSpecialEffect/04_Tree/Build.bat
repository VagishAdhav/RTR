DEL *.exe
DEL *.obj
cl.exe /c /EHsc OGL.c  LSystemTree.c
rc.exe Window.rc
link.exe OGL.obj LSystemTree.obj Window.res User32.lib Kernel32.lib GDI32.lib /SUBSYSTEM:WINDOWS