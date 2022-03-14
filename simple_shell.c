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
#include <string.h>

#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc,char* argv[]) {

        // ask to exit if enter another argument in the beginning
        if (argc > 1) {
                fprintf(stderr, "Shell does not accept any command line arguments \n");
                exit(1);
        }

        // false flag until user input exit, then check if its exit 0, if not then false
        bool exit_flag = false;

        int num = 0;
        int index = 1;
        int n1 = getpid();

        while (exit_flag == false) {
                index = 0;

                char *s = malloc(1);
                int c;
                int i = 0;

                char value;
                FILE *fp;


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

                        // proc statement
                        else if ((!strcmp(args[0], "proc"))) {

                                int n1 = getpid();
                                char pid_proc[] = "/proc/";
                                char status_proc[100];
                                char environ_proc[100];
                                char sched_proc[100];
                                char source[] = "/status";
                                char source2[] = "/environ";
                                char source3[] = "/sched";

                                // makes pid into char
                                sprintf(status_proc, "%d", n1);
                                sprintf(environ_proc, "%d", n1);
                                sprintf(sched_proc, "%d", n1);

                                //gets the live pid from user with pid/status
                                strcat(status_proc, source);
                                //gets the live pid from user with pid/enivron
                                strcat(environ_proc, source2);
                                //gets the live pid from user with pid/sched
                                strcat(sched_proc, source3);

                                // 2nd user input is cpuinfo
                                if ((!strcmp(args[1], "cpuinfo"))) {
                                        fp = fopen("/proc/cpuinfo", "r");

                                        // check if file has nothing in it
                                        if (fp == NULL) {
                                                fprintf(stderr, "Error opening file\n");
                                        }

                                        // Opens the file
                                        else {
                                                // prints every line from file until end of line
                                                while ((value = fgetc(fp)) != EOF) {
                                                        printf("%c", value);
                                                }

                                                //close the file
                                                fclose(fp);
                                        }
                                }

                                // 2nd user input is loadavg
                                else if ((!strcmp(args[1], "loadavg"))) {
                                        fp = fopen("/proc/loadavg", "r");

                                        // check if file has nothing in it
                                        if (fp == NULL) {
                                                fprintf(stderr, "Error opening file\n");
                                        }

                                        // Opens the file
                                        else {
                                                // prints every line from file until end of line
                                                while ((value = fgetc(fp)) != EOF) {
                                                        printf("%c", value);
                                                }

                                                //close the file
                                                fclose(fp);
                                        }
                                }

                                // 2nd user input is filesystems
                                else if ((!strcmp(args[1], "filesystems"))) {
                                        fp = fopen("/proc/filesystems", "r");

                                        // check if file has nothing in it
                                        if (fp == NULL) {
                                                fprintf(stderr, "Error opening file\n");
                                        }

                                        // Opens the file
                                        else {
                                                // prints every line from file until end of line
                                                while ((value = fgetc(fp)) != EOF) {
                                                        printf("%c", value);
                                                }

                                                //close the file
                                                fclose(fp);
                                        }
                                }

                                // 2nd user input is mounts
                                else if ((!strcmp(args[1], "mounts"))) {
                                        fp = fopen("/proc/mounts", "r");

                                        // check if file has nothing in it
                                        if (fp == NULL) {
                                                fprintf(stderr, "Error opening file\n");
                                        }

                                        // Opens the file
                                        else {
                                                // prints every line from file until end of line
                                                while ((value = fgetc(fp)) != EOF) {
                                                        printf("%c", value);
                                                }

                                                //close the file
                                                fclose(fp);
                                        }
                                }


                                // 2nd user input is pid/status
                                else if ((!strcmp(args[1], status_proc))) {

                                        //adds the pid from user to string
                                        strcat(pid_proc, status_proc);

                                        fp = fopen(pid_proc, "r");

                                        // check if file has nothing in it
                                        if (fp == NULL) {
                                                fprintf(stderr, "Error opening file\n");
                                        }

                                        // Opens the file
                                        else {
                                                // prints every line from file until end of line
                                                while ((value = fgetc(fp)) != EOF) {
                                                        printf("%c", value);
                                                }

                                                printf("\n\n");
                                                //close the file
                                                fclose(fp);
                                        }
                                }

                                // 2nd user input is pid/environ
                                else if ((!strcmp(args[1], environ_proc))) {

                                        //adds the pid from user to string
                                        strcat(pid_proc, environ_proc);

                                        fp = fopen(pid_proc, "r");

                                        // check if file has nothing in it
                                        if (fp == NULL) {
                                                fprintf(stderr, "Error opening file\n");
                                        }

                                        // Opens the file
                                        else {
                                                // prints every line from file until end of line
                                                while ((value = fgetc(fp)) != EOF) {
                                                        printf("%c", value);
                                                }

                                                //close the file
                                                fclose(fp);
                                        }
                                }

                                // 2nd user input is pid/sched
                                else if ((!strcmp(args[1], sched_proc))) {

                                        //adds the pid from user to string
                                        strcat(pid_proc, sched_proc);

                                        fp = fopen(pid_proc, "r");

                                        // check if file has nothing in it
                                        if (fp == NULL) {
                                                fprintf(stderr, "Error opening file\n");
                                        }

                                        // Opens the file
                                        else {
                                                // prints every line from file until end of line
                                                while ((value = fgetc(fp)) != EOF) {
                                                        printf("%c", value);
                                                }

                                                //close the file
                                                fclose(fp);
                                        }
                                }
                        }

                        // echo statement
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
                                        char *words[41];

                                        for (int x = 0; x <= index-1; x++) {
                                                words[x] = unescape(args[x], stderr);
                                        }

                                        //add NULL after the last char
                                        words[index] = NULL;

                                        execvp(words[0], words);
                                }

                                // parent fork()
                                else {
                                        while (wait(&child_status) != child_pid);
                                }
                        }

                        // other statments
                        else {
                                int status;
                                //testing wait() in fork() and pid_t
                                pid_t pid = fork();

                                // error
                                if (pid == -1)
                                        exit(-1);
                                // child process
                                else if(pid == 0) {
                                        execvp(args[0], args);
                                }
                                // parent process
                                else {
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
