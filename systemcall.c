PROGRAM:
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/wait.h>
int fd;
int forkExecCall()
{
    pid_t pid;
    int ret = 1;
    int status;
    pid = fork();
    if (pid == -1)
    {
        printf("can't fork, error occured\n");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        printf("child process, pid = %u\n", getpid());
        printf("parent of child process, pid = %u\n", getppid());
        char *argv_list[] = {"ls", "-lart", "/home", NULL};
        execv("ls", argv_list);
    }
    else
    {

        printf("Parent Of parent process, pid = %u\n", getppid());
        printf("parent process, pid = %u\n", getpid());

        if (waitpid(pid, &status, 0) > 0)
        {

            if (WIFEXITED(status) && !WEXITSTATUS(status))
                printf("---program execution successful---\n");

            else if (WIFEXITED(status) && WEXITSTATUS(status))
            {
                if (WEXITSTATUS(status) == 127)
                {

                    printf("execv failed\n");
                }
                else
                    printf("program terminated normally but returned a non-zero status\n");
            }
            else
                printf("program didn't terminate normally\n");
        }
        else
        {
            printf("waitpid() failed\n");
        }
    }
    return 0;
}
int forkWaitCall()
{
    pid_t cpid;
    if (fork() == 0)
        exit(0);
    else
        cpid = wait(NULL);
    printf("Parent pid = %d\n", getpid());
    printf("Child pid = %d\n", cpid);
    return 0;
}
int createaFile()
{
    fd = open("file1.txt", O_CREAT, 0777);
    closeFile();
}
void readFile()
{
    char *ch = (char *)calloc(100, sizeof(char));
    fd = open("file1.txt", O_RDONLY);
    read(fd, ch, 100);
    printf("Contents of  file1.txt is : \n%s\n\n", ch);
    closeFile();
}

void writeFile()
{
    char ch[100];
    fd = open("file1.txt", O_WRONLY);
    printf("Enter text to write in the file file1.txt :\n");
    int n = read(0, ch, 100);
    write(fd, ch, n);
    printf("Written Successfully\n\n");
    closeFile();
}

void closeFile()
{
    close(fd);
}

int main()
{

    int choice;
    printf("\nPROGRAM:---SYSTEM CALLS---\n");
    while (1)
    {
        printf("Enter your choice\n1.Fork and Exec\n2.Fork and wait \n3.Create file\n4.Write\n5.Read\n6.Close file\n0.Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            forkExecCall();
            break;
        case 2:
            forkWaitCall();
            break;
        case 3:
            createaFile();
            printf("file1.txt created\n\n");
            break;
        case 4:
            writeFile();
            break;
        case 5:
            readFile();
            break;
        case 6:
            closeFile();
            printf("closed file1.txt \n\n");
            break;
        case 0:
            exit(0);
        }
    }
    return 0;
}

