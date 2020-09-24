//this File Demonstarte that how the structure is written into the File EmployeeDetail

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
struct Employee
{
    int Emp_id;
    char name[50];
    char Add[50];
};
int main()
{
  int fd=creat("EmpDetail.txt",0777);  //create File
  if(fd==-1)
  {
      printf("Error in creating file");
      return -1;
  }
  struct Employee e={1,"Neha","Pune"};
  struct Employee e1={2,"Priya","Mumbai"}; 
  struct Employee e2={3,"Kiran","Nashik"};
  struct Employee e3={4,"Sonali","Mumbai"};//define structure
  write(fd,&(e),sizeof(struct Employee)); //write into the file
  write(fd,&(e1),sizeof(struct Employee));
  write(fd,&(e2),sizeof(struct Employee)); //write into the file
  write(fd,&(e3),sizeof(struct Employee)); //write into the file
  close(fd);
  
  return 0;
}