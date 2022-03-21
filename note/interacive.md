# An interactive Prompt 

In this chapter we will use the function like the gets/puts ... to build a program with the ability 
to interacte 

```c
#include <stdio.h>
static char input[2048];
int main(int argc, char** argv) {
    puts("halflisp version 0.0.1");
    puts("press ctrl-c to cancel it");
    while(1) {
        fputs("halflisp>",stdout);
        fgets(input,2048,stdin);
        printf("Your input is %s",input);
    }
}
```

It is a simple function that get your input and output of it.

# compile your program

```shell
cc -std=c99 -Wall test.c -o test 
```

The your get a execultable file 

In the ubuntu, you will need to install tools for this function 
```shell
❯ sudo apt install libedit-dev
```
Then you can use the function in the editline and other header
- add_history add the input into the history , then you can use it by up and down 

```c
#include <stdio.h>
#include <stdlib.h>
#include <editline/readline.h>
#include <editline/history.h>

int main(int argc,char **argv) {
   printf("HalfLisp v 0.0.1\n");
   while(1) {
        char *input = readline("orz|");
        add_history(input);
        printf("Dalao's input is %s\n",input);
        free(input);
   }
   return 0;
}
``
```
