#include<stdio.h>
#include<fcntl.h>
#include<string.h> //conatins syetm calls and macros for modes
#include<unistd.h>
#include<stdlib.h> //for close
int main(int argc,char *argv[])
{
 if(argc!=3)
  {
    printf("Invalid Arguments\n");
    printf("Help: programFilename File_name_to_open NO_OF_BYTES_TO_READ\n");
    return -1;
  }   
 
 char *buffer=NULL;
 int ret=0;

 int icnt=(long)argv[2];  //no of bytes to read
 int fd=open(argv[1],O_RDONLY);
 if(fd==-1)
 {
  printf("Error:Unable to open File\n");
  return -1;
 }
 else
 {
   printf("File Opened Successfully with descripter %d\n",fd);
 }
 
 buffer=(char*) malloc(icnt*sizeof(char));
 if(buffer==NULL)
 {
  printf("Error in buffer");
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
