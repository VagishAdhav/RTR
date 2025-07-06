DEL *.exe
DEL *.obj
cl.exe /c /EHsc /I C:\glew-2.1.0\include OGL.c
rc.exe OGL.rc
link.exe OGL.obj OGL.res /LIBPATH:C:\glew-2.1.0\lib\Release\x64\ User32.lib Kernel32.lib GDI32.lib glew32.lib /SUBSYSTEM:WINDOWS