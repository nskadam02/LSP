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
    printf("Help: programFilename File_name_to_open String_to_write\n");
    return -1;
  }   
 int fd=open(argv[1],O_WRONLY);
 if(fd==-1)
 {
  printf("Error:Unable to open File\n");
  return -1;
 }
 else
 {
   printf("File Opened Successfully with descripter %d\n",fd);
 }
 int ret=write(fd,argv[2],strlen(argv[2]));
 if(ret>0)
 {
  printf("Successfully write in file");
 }
 else
 {
   printf("Error in wirte call");
   return -1;
 }
 close(fd);
 return 0;
}
