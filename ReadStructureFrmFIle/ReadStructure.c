//this File Demonstarte that how the structure is written into the File EmployeeDetail

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
struct Employee  //declare Structure
{
    int Emp_id;
    char name[50];
    char Add[50];
};
int main(int argv,char *args[])
{
  if(argv!=2)
  {
      printf("Invalid Arguments");
      printf("Use:Exe FileContainEmployeeDetail");
      return -1;
  }
  int fd=open(args[1],O_RDONLY);  //Open File 
  if(fd==-1)
  {
      printf("Error in creating file");
      return -1;
  }
  int ret;
  struct Employee e;
  while((ret=read(fd,&(e),sizeof(struct Employee)))!=0)   //read till ret not equal to 0
  {
      printf("ID:%d NAME:%s ADDRESS:%s\n",e.Emp_id,e.name,e.Add);
  }
  
  close(fd); //close file
  
  return 0;
}