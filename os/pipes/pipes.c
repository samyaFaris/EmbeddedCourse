#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUF_SIZE 200
#define ROUNDS 5

int main()
{
    int p1[2], p2[2];
    pid_t pid;
    char buf[BUF_SIZE];
    char helloChild[] = "Hello Child";
    char helloFather[] = "Hello Father";

    /* create two pipes */
    if (pipe(p1) == -1 || pipe(p2) == -1)
    {
        perror("pipe");
        return 1;
    }

    pid = fork();
    if (pid < 0)
    {
        perror("fork");
        return 1;
    }

    if (pid > 0) /* parent */
    {
      
        for (int i = 0; i < ROUNDS; i++)
        {
            close(p1[0]); /* close unused read end of p1 */
            close(p2[1]); /* close unused write end of p2 */

            /* parent sends message to child */
            write(p1[1], helloChild, sizeof(helloChild));

            /* parent reads response from child */
            read(p2[0], buf, sizeof(buf));
            printf("%s\n", buf);

            wait(NULL);

        }
        
            close(p1[1]);
            close(p2[0]);
    }
    else /* child */
    {
           for (int j = 0; j < ROUNDS; j++)
           {
        close(p1[1]); /* close unused write end of p1 */
        close(p2[0]); /* close unused read end of p2 */

        /* child reads message from parent */
        read(p1[0], buf, sizeof(buf));
        printf("%s\n", buf);

        /* child sends response back */
        write(p2[1], helloFather, sizeof(helloFather));

        close(p1[0]);
        close(p2[1]);}
    }

    return 0;
}