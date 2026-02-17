#include "shellHeader.h"

void type_prompt()
{
    printf("Welcome to our shell, please add your command");
    printf("shellUser:$");
}

void read_command(char *command, char * parameters [])
{

    if (fgets(command, MAX_INPUT, stdin) != NULL)
    {
        command[strcspn(command, "\n")] = '\0'; 
    }
    int i=0;
    char * token = strtok(command, " ");
    while(token != NULL)
    {
       parameters[i]= token;
       token = strtok(NULL, " ");
       ++i;

    }
    parameters[i]=NULL;
}