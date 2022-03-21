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
