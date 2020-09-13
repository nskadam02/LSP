#include<stdio.h>
#include<fcntl.h>
#include<string.h> //conatins syetm calls and macros for modes
#include<unistd.h> //for close
int main(int argc,char *argv[])
{
 if(argc!=2)
  {
    printf("Invalid Arguments\n");
    printf("Help: programFilename File_name_to_open \n");
    return -1;
  }  
 int ret=0;
 int fd=open(argv[1],O_RDONLY);
 if(fd==-1)
 {
  printf("Error:Unable to open File\n");
  return -1;
 }
 else
 {
  printf("\nFile Opened Successfully with descripter %d\n",fd);
 }
 char buffer[512];
 while((ret=read(fd,buffer,sizeof(buffer)))!=0)
 {
   write(1,buffer,ret);
  
   //here (stdout,from which,how many);
 }

 close(fd);
 return 0;
}
