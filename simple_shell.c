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
#include <ctype.h>

#include <stdbool.h>

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

/*
//TESTING echo
        char* command = "echo";
        char* argument_list[] = {"echo", "hello", NULL};

        int status_s;
        //testing wait() in fork() and pid_t
        pid_t pid_s = fork();
        if (pid_s == -1)
                exit(-1);
        else if(pid_s == 0) {
                printf("Child: %d\n", pid_s);
                execvp(command, argument_list);
        }
        // (wait(pid > 0))
        else {
                printf("Parent: %d\n", pid_s);
                while (wait(&status_s) != pid_s);
        }
*/
                        
        printf("\nA sample C program\n\n");

        // ask to exit if enter another argument in the beginning
        if (argc > 1) {
                fprintf(stderr, "Shell does not accept any command line arguments \n");
                exit(1);
        }

/*WORKS PID_T FORCK()
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
*/

        // false flag until user input exit, then check if its exit 0, if not then false

        bool exit_flag = false;
        int num = 0;
        int index = 1;

        while (exit_flag == false) {
                index = 0;


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



                // checks if string is empty, loop until user inputs
                if(s[0] != '\0') {

                        char *args[41]; // Max # of arguments

                        char *words[41];
                

                        // get the first agruement
                        args[0] = strtok(s, " ");

                        int x = 0;

                        // checks and counts for each string in the user input
                        while (args[x] != NULL) {
                                args[++x] = strtok(NULL, " ");
                                index++;                                                 
                        }

                        
                        //unescape time WORKS NOW
                        //x = unescape(args[0], stderr);
                        words[0] = unescape(args[0], stderr);

                        printf("Entered string UNESCAPE: %s\n", words[0]);
                        free(s);
                        free(*words);
                        return 0;
                        
                        //printf(" %s\n", args[0]);
                        //printf(" %s\n", args[1]);

                        if (!strcmp(args[0], "exit")) {

                                // check if 2nd input is empty, exit 0
                                if(args[1] == '\0') {
                                        num = 0;
                                        exit_flag = true;
                                }

                                //check if 2nd input is a number
                                else {
                                        num = 0;

                                        num = strtol(args[1], NULL, 10);

                                        // set is_exit to true if 2nd input is a number
                                        if (num != 0) {
                                                exit_flag = true;
                                                //free(s);
                                                //free(args);
                                        }

                                        // set is_exit to true if 2nd input is a number
                                        else if (!strcmp(args[1], "0")) {
                                                num = 0;
                                                exit_flag = true;
                                        }

                                        else {
                                                printf("That is not a exit\n");
                                        }
                                        //printf("HERE:  %d\n", num);
                                }
                        }

                        else {
                                int status;
                                //testing wait() in fork() and pid_t
                                pid_t pid = fork();
                                if (pid == -1)
                                        exit(-1);
                                else if(pid == 0) {
                                        printf("Child: %d\n", pid);
                                        execvp(args[0], args);
                                }
                                // (wait(pid > 0))
                                else {
                                        printf("Parent: %d\n", pid);
                                        while (wait(&status) != pid);
                        }
                }



                        // test for checking first agruement
                        if (!strcmp(args[0], "ls"))
                                printf("Huzzah\n");


                        free(s);
                        //free(args);

                }


        /* VIDEO EXAMPLE
        // loop through other token
        while (token != NULL) {
                printf(" %s\n", token);

                token = strtok(NULL, " ");
        }
        */

        // trying to get echo and ls commands
        //s[0] = strtok()

                //string is empty
                else {
                        printf("string is empty\n");


                        printf("Entered string: %s\n", s);

                        // free empty string
                        free(s);
                }

                printf("TESTING\n");

                //exit_flag = true;
        }

        exit(num);

        return 0;
}
