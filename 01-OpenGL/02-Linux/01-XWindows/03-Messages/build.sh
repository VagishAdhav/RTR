rm -f XWindow
rm -f XWindow.o
gcc -c -o XWindow.o XWindow.c
gcc -o XWindow XWindow.o -lX11
./XWindow