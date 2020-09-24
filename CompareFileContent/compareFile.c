// this prgram take the two file  names from user and check wether the 
//content in the file is same or not
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h> ///for mkdir
#include<string.h>

//this function checks the content
//return value=1 if content are same
//value -1=if not same
int FileCmp(char* file1,char* file2)
{
   int fd1,fd2; //file descriptor for both file
   int rt1,rt2;
   int size1,size2;//for size of both;
   char Arr[512],Brr[512];
   
   //open both the files in read mode
   fd1=open(file1,O_RDONLY);  
   fd2=open(file2,O_RDONLY);
   if(fd1==-1 || fd2==-1)
   {
       printf("Unable to open file");
       return -1;
   }

   //Calculate the size of file
   size1=lseek(fd1,0,SEEK_END);
   size2=lseek(fd2,0,SEEK_END);
   if(size1!=size2)
   {
       printf("Sizes Are Different");
       return -1;
   }

   //Reset offset to 0;
   lseek(fd1,0,SEEK_SET);
   lseek(fd2,0,SEEK_SET);

   //compare
   while(1)
   {
       //take 512 bytres in container to compare
       rt1=read(fd1,Arr,sizeof(Arr));
       rt2=read(fd2,Brr,sizeof(Brr));
       if(memcmp(Arr,Brr,rt1)!=0)  //comapare memory if 0 means same content
       {
           break;
       }
       if(rt1==0 || rt2==0)  //one of the file is finished
       {
           break;
       }
   }
   close(fd1);
   close(fd2);
   if(rt1==0 && rt2==0)  //at last if bothh are 0 means file are at end
   {
       return 1;
   }
   else
   {
       return 0;
   }
   
   }
int main(int argv,char *args[])
{
    if(argv!=3)
    {
        printf("Invalid Argumnets\n");
        printf("Use: File1 File2");
        return -1;
    }
    int fd=FileCmp(args[1],args[2]);
    if(fd==0)
    {
        printf("content in the file Are not same");
    }
    if(fd==1)
    {
        printf("Content in the file is same");
    }
    
    return 0;
}