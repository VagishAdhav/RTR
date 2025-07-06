DEL *.exe
cl.exe /c /EHsc OGL.c ShapeLib.c
rc.exe OGL.rc
link.exe OGL.obj ShapeLib.obj OGL.res User32.lib Kernel32.lib GDI32.lib /SUBSYSTEM:WINDOWS