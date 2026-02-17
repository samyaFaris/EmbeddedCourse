#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include "shellHeader.h"

#define MAX_INPUT 1024

// void type_prompt()
// {
//     printf("Welcome to our shell, please add your command");
//     printf("shellUser:$");
// }

// void read_command(char *command, char * parameters [])
// {

//     if (fgets(command, MAX_INPUT, stdin) != NULL)
//     {
//         command[strcspn(command, "\n")] = '\0'; 
//     }
//     int i=0;
//     char * token = strtok(command, " ");
//     while(token != NULL)
//     {
//        parameters[i]= token;
//        token = strtok(NULL, " ");
//        ++i;

//     }
//     parameters[i]=NULL;
// }

int main()
{

    int statusShell = 1;
    char command[MAX_INPUT];
    char*  parameters[MAX_INPUT];
    int status;
    while (statusShell)
    {

        type_prompt();
        read_command(command, parameters);
        if (strcmp(parameters[0], "exit") == 0)
        {

            statusShell = 0;
            break;
        }

        if (fork() != 0)
        {

            wait(&status);
        }
        else
        {
            execvp(command,parameters);
        }
    }
}
