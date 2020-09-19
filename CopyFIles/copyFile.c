#include<stdio.h>
#include<fcntl.h>
#include<string.h> //conatins syetm calls and macros for modes
#include<unistd.h> //for close
int main(int argc,char *argv[])
{
 if(argc!=3)
  {
    printf("Invalid Arguments\n");
    printf("Help: programFilename Source_file Destination_File \n");
    return -1;
  }  
 int ret=0;
 int fd=open(argv[1],O_RDONLY);
 int fd1=open(argv[2],O_WRONLY|O_APPEND);
 if(fd==-1 || fd1==-1)
 {
  printf("Error:Unable to open File\n");
  return -1;
 }
 char buffer[512];
 while((ret=read(fd,buffer,sizeof(buffer)))!=0)
 {
   write(fd1,buffer,ret);
  
   //here (stdout,from which,how many);
 }

 close(fd);
 close(fd1);
 return 0;
}
