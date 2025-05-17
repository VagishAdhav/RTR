cl.exe /c /EHsc PaintHomework.c
rc.exe Window.rc
link.exe PaintHomework.obj Window.res User32.lib Kernel32.lib GDI32.lib /SUBSYSTEM:WINDOWS