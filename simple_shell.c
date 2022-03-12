/*
Name: Zachary Nguyen
Section: 02
Professor: Tompkins
Email: znguyen3@umbc.edu

*/

#include "utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc,char* argv[]) {

/* WORKS UNESCAPE
        char* x;
        char* args = ("\'Hello World\'\a");

        x = unescape(args, stderr);
        printf("Entered string: %s\n", unescape(args, stderr));
*/


/*
        int x = 5;
        char* args = ("hello");
        printf("HERE: %s", args[0]);
*/
/*
        //test unescape
        for (int j = 0; j < x; j++) {
                char *str = unescape(args[j], stderr);

                strcpy(args[j], str);

                free(str);
        }
*/

/*
        char *hello = "Hello\nWorld";
        printf("Entered string: %s\n", unescape(hello,stderr));
        free(hello);
*/

/* OTHER ULTC.c FUNCTIONS
        //testing other function in ulits.c
        char *str = ("Hellot  there jon\n");
        int size = first_unquoted_space(str);
        printf("size = %d\n", size);
        
        size_t help;
        help = count_spaces(str);
        printf("size_t = %ld\n", help);
*/


        //if loop

        //testing wait() in fork() and pid_t
        pid_t pid = fork();
        if (pid == -1)
                exit(-1);
        else if(pid == 0) {
                printf("Child: %d\n", pid);
                exit(0);
                }
        else if(wait(pid > 0)) {
                printf("Parent: %d\n", pid);

                }

        // ask to exit if enter another argument in the beginning

        printf("\nA sample C program\n\n");

        if (argc > 1) {
                fprintf(stderr, "Shell does not accept any command line arguments \n");
                exit(1);
        }


        //NEW STUFF HERE
        char *s = malloc(1);
        int c;
        int i = 0;

        printf("Enter your command: ");

        //NEED TO REWRITE BETTER FORMAT THAN THIS
        // Read characters until found an EOF or newline character.
        while((c = getchar()) != '\n' && c != EOF)
        {
                s[i++] = c;
                s = realloc(s, i+1); // Add space for another character to be read.
        }

        s[i] = '\0';  // Null terminate the string

        
        // WORKS, finds the if the string is empty
        if(strlen(s) == 0)
                printf("string is empty");
                free(s);
                return 0;

        char *args[41]; // Max # of arguments

        // get the first agruement
        args[0] = strtok(s, " ");

        int x = 0;

        while (args[x] != NULL) {
                args[++x] = strtok(NULL, " ");
        }

        printf(" %s\n", args[0]);
        printf(" %s\n", args[1]);

        // test for checking first agruement
        if (!strcmp(args[0], "ls"))
                printf("Huzzah\n");

        execvp(args[0], args);

        /* VIDEO EXAMPLE
        // loop through other token
        while (token != NULL) {
                printf(" %s\n", token);

                token = strtok(NULL, " ");
        }
        */

        // trying to get echo and ls commands
        //s[0] = strtok()

        printf("Entered string: %s\n", s);

        free(s);





return 0;
}
