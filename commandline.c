//command line argument
#include<stdio.h>
int main(int argc,char *argv[])
{
  if(argc!=2)
  {
    printf("Invalid Arguments\n");
    printf("Help: Filename name\n");
    return 0;
  }
  printf("%s",argv[1]);
  return 0;
}
