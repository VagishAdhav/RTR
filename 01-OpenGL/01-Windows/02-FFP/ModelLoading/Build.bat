DEL *.exe
cl.exe /c /EHsc OGL.c
rc.exe OGL.rc
link.exe OGL.obj OGL.res User32.lib Kernel32.lib GDI32.lib /SUBSYSTEM:WINDOWS