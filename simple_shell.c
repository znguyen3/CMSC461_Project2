/*
Name: Zachary Nguyen
Section: 02
Professor: Tompkins
Email: znguyen3@umbc.edu

*/

//#include "utils.c"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc,char* argv[]) {

        /*
        int i = 10;

        //test unescape
        for (int j = 0; j < i; j++) {
                char *str = unescape(argv[j], stderr);
                strcpy(argv[j], str);
                free(str);
        }
        */


        //testing other function in ulits.c
        char *str = ("Hellot  there jon\n");
        int size = first_unquoted_space(str);
        printf("size = %d\n", size);

        size_t help;
        help = count_spaces(str);
        printf("size_t = %ld\n", help);

        //if loop

        //testing wait() in fork() and pid_t
        pid_t pid = fork();
        if (pid == -1)
                exit(-1);
        else if(pid == 0) {
                printf("Child: %d\n", pid);
                exit(0);
                }
        else if(wait(pid > 0))
                printf("Parent: %d\n", pid);

        // ask to exit

        printf("\nA sample C program\n\n");

        if (argc > 1) {
                fprintf(stderr, "Shell does not accept any command line arguments \n");
                exit(1);
        }

        /* KEEP

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
        printf("Entered string: %s\n", s);
        free(s);


        */


return 0;
