#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main(int argc,char *argv[])
{
  if(argc!=3)
  {
    printf("Invalid Arguments\n");
    printf("Help: programFilename File_name_to_open MODE\n");
    return -1;
  }
  int check;
  if(argv[2]=="O_RDONLY")
  {
    int check=access(argv[1],R_OK);
  }else if(argv[2]=="O_WRONLY")
  {
    int check=access(argv[1],W_OK);
  }
  else
  {
    int check=access(argv[1],(R_OK && W_OK));
  }
  if(check==0)
  {
    printf("file is accessible in %s mode\n",argv[2]);
  }
  else
  {
    printf("File is not accessible");
  }
  return 0;
}
