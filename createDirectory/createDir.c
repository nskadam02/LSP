// this prgram take the directory name from user and crete new directory of thet name
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h> ///for mkdir

int main(int argv,char *args[])
{
    if(argv!=2)
    {
        printf("Invalid Argumnets\n");
        printf("Use: Exe Directory_to_create");
        return -1;
    }
    int fd=mkdir(args[1],0777);
    if(fd==-1)
    {
        printf("Unable to create directory");
        return -1;
    }
    else
    {
        printf("Directrory created successfully");
    }
    
    return 0;
}