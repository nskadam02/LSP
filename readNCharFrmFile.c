#include<stdio.h>
#include<fcntl.h>
#include<string.h> //conatins syetm calls and macros for modes
#include<unistd.h>
#include<stdlib.h> //for close
int main()
{
 char file[100];
 char *buffer=NULL;
 int ret=0;
 printf("Enter Filename:\n");
 scanf("%s",file);
 int fd=open(file,O_RDONLY);
 if(fd==-1)
 {
  printf("Error:Unable to open File\n");
  return -1;
 }
 else
 {
   printf("File Opened Successfully with descripter %d\n",fd);
 }
 
 buffer=(char*) malloc(5*sizeof(char));
 if(buffer==NULL)
 {
  printf("Erropr in buffer");
  return -1;
 }
 ret=read(fd,buffer,5);
 if(ret==-1)
 {
   printf("Error in reading");
   return -1;
 }
 printf("%s",buffer);
 free(buffer);
 close(fd);
 return 0;
}
