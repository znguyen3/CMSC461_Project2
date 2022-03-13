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

        printf("\nA sample C program\n\n");

        // ask to exit if enter another argument in the beginning
        if (argc > 1) {
                fprintf(stderr, "Shell does not accept any command line arguments \n");
                exit(1);
        }

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

                        // get the first agruement
                        args[0] = strtok(s, " ");

                        int x = 0;

                        // checks and counts for each string in the user input
                        while (args[x] != NULL) {
                                args[++x] = strtok(NULL, " ");
                                index++;
                        }

                        printf("PRINT SPACES INDEXS: %d\n", index);

                        // exit statment
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
                                        }

                                        // set is_exit to true if 2nd input is a number
                                        else if (!strcmp(args[1], "0")) {
                                                num = 0;
                                                exit_flag = true;
                                        }

                                        else {
                                                printf("That is not a exit\n");
                                        }
                                }
                        }
                        
                        // echo statment
                        else if ((!strcmp(args[0], "echo")) || (!strcmp(args[0], "/bin/echo"))) {

                                int child_status;
                                pid_t child_pid = fork();
                                //failed fork()
                                if (child_pid == -1) {
                                        printf("Failed\n");
                                        exit(-1);
                                }
                                //child fork()
                                else if(child_pid == 0) {
                                        printf("Child: %d\n", child_pid);

                                        char *words[41];

                                        for (int x = 0; x <= index-1; x++) {
                                                words[x] = unescape(args[x], stderr);
                                        }

                                        words[index] = NULL;
                                        execvp(words[0], words);
                                }

                                // parent fork()
                                else {
                                        printf("Parent: %d\n", child_pid);
                                        while (wait(&child_status) != child_pid);
                                }
                        }

                        // other statments
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

                        // free the user input
                        free(s);
                }
                
                //string is empty
                else {
                        // free empty string
                        free(s);
                }
        }

        //exit with user input
        exit(num);

        return 0;
}
