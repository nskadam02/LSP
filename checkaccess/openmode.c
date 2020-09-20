/*
We take the mode and file from command line and check wheter it is acessible in given mode or not
#mode should be taken as read/write/readwrite/truncate
*/
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h> //access function
int main(int argc,char *argv[])
{
  if(argc!=3)
  {
    printf("Invalid Arguments\n");
    printf("Help: programFilename File_name_to_open MODE\n");
    return -1;
  }
  int check;
  if(argv[2]=="read")
  {
    int check=access(argv[1],R_OK);
  }else if(argv[2]=="write")
  {
    int check=access(argv[1],W_OK);
  }
  else if(argv[2]=='readwrite')
  {
    int check=access(argv[1],(R_OK && W_OK));
  }
  else if(argv[2]=='execute')
  {
    int check=access(argv[1],X_OK);
  }else
  {
    printf("Invalid Arguments");
    return -1;
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
