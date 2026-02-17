#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#define MAX_INPUT 1024

/**
 * type_prompt
 * Prints a prompt message to the user on the console.
 * This function displays a welcome message and the shell prompt.
 * It does not take any parameters and does not return a value.
 */
void type_prompt();void type_prompt();

/**
 * read_command
 *
 * Reads a line of input from the user and splits it into command and parameters.
 *
 * command: store the raw user input.
 * parameters: Array to store pointers to each word of the command.
*/

void read_command(char *command, char * parameters []);

