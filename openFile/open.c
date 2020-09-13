#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main(int argc,char *argv[])
{
  if(argc!=2)
  {
    printf("Invalid Arguments\n");
    printf("Help: Filename name\n");
    return -1;
  }
  int fd=open(argv[1],O_RDONLY);
  if(fd==-1)
  {
      printf("Error:Unable to open File\n");
      return -1;
  }
  else
  {
      printf("File opened successfully with descriptor %d\n",fd);
  }
  close(fd);
  return 0;
}
