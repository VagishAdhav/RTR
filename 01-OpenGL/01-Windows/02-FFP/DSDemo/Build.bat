DEL *.exe *.obj
cl.exe /c /EHsc OGL.cpp ShapeLib.cpp LSystemTree.cpp Camera.cpp
rc.exe OGL.rc
link.exe OGL.obj ShapeLib.obj LSystemTree.obj Camera.obj OGL.res User32.lib Kernel32.lib GDI32.lib /SUBSYSTEM:WINDOWS