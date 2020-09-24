//This program take the filename and position from user and 
//read 20 byte from that position
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
 int icnt=atoi(argv[2]);  //atoi convert the string to integer ASCII to integer
 int fd=open(argv[1],O_RDONLY);  //open file
 if(fd==-1)
 {
  printf("Error:Unable to open File\n");
  return -1;
 }
 else
 {
   printf("File Opened Successfully with descripter %d\n",fd);
 }
 
 buffer=(char*)malloc(20*sizeof(char));  //set buffer size
 if(buffer==NULL)
 {
  printf("Error in buffer");
  return -1;
 }
 lseek(fd,icnt,SEEK_SET);        //set the pointer to icnt th position from starting
 ret=read(fd,buffer,20);  
     //read 20 byte from given position
 if(ret==-1)
 {
   printf("Error in reading");
   return -1;
 }
 printf("%s",buffer);   //print the bytes
 free(buffer);         //free the buffer which is allocated
 close(fd);
 return 0;
}
