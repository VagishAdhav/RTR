rm -f OGL
rm -f OGL.o
gcc -c -o OGL.o OGL.c
gcc -o OGL OGL.o -lX11 -lGL
./OGL