/*
In this Program we take filename and mode in command line argument and open that file in respected mode
1.mode should taken as read/write/readwrite/trucate
*/


#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
int main(int argc,char *argv[])
{
  if(argc!=3)
  {
    printf("Invalid Arguments\n");
    printf("Help: programFilename File_name_to_open MODE\n");
    return -1;
  }
  int mode;
  if(!(stricmp(argv[2],'read')))
  {
    mode=O_RDONLY;
  }
  else if(!(stricmp(argv[2],'write')))
  {
    mode=O_WRONLY;
  }
  else if(!(stricmp(argv[2],'readwrite')))
  {
    mode=O_RDWR;
  }
  else if(!(stricmp(argv[2],'truncate')))
  {
    mode=O_WRONLY|O_TRUNC;
  }
  else
  {
    printf("Invalid Arguments");
    return -1;
  }
  
  int fd=open(argv[1],mode);  ///open file it return filedescriptor in success
  if(fd==-1)
  {
      printf("Error:Unable to open File\n");
      return -1;
  }
  else
  {
      printf("File opened successfully with descriptor %d\n",fd);
  }
  //close the file 
  close(fd);
  return 0;
}
