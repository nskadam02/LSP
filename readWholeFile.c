#include<stdio.h>
#include<fcntl.h>
#include<string.h> //conatins syetm calls and macros for modes
#include<unistd.h> //for close
int main()
{
 char file[100];
 int ret=0;
 printf("Enter Filename:\n");
 scanf("%s",file);
 int fd=open(file,O_RDONLY);
 if(fd==-1)
 {
  printf("Error:Unable to open File\n");
  return -1;
 }
 //else
 //{
  // printf("File Opened Successfully with descripter %d",fd);
 //}
 char buffer[512];
 while((ret=read(fd,buffer,sizeof(buffer)))!=0)
 {
   write(1,buffer,ret);
   //here (stdout,from which,how many);
 }

 close(fd);
 return 0;
}
