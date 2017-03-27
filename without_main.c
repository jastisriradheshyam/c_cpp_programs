#include<stdio.h>

extern void _exit(register int code);

_start(){

printf("Hello World\n");
_exit(0);
}
/*
Compile the code with:
gcc -o no_main no_main.c -nostartfiles
The -nostartfiles will not include the default startup file. You point to the main entry file with the _start .
main is nothing but a predefined entrypoint for the user code. Therefore you can name it whatever, but at the end of the day you do need an entry point.
*/
