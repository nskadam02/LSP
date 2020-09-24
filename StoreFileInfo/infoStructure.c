//it takes directory name from user and create structure of file info 
// write it in file named FileInfo

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/stat.h>
#include<stdlib.h>
struct FileInfo
{
    char *FileName;
    int Permision;
    int Size;
    int Type;
};
int main(int argv,char *args[])
{
  if(argv!=2)
  {
      printf("Invalid Arguments");
      printf("Use:Exe Directory_Name");
      return -1;
  }
  int fd=creat("FileInfo.txt",0777);
  if(fd==-1)
  {
      printf("Error in creation of file");
      return -1;
  }
 char* n=(char*)malloc(256);
 struct stat ptr;
 struct dirent *de; //Pointer for directoery Entry
 DIR *dr=opendir(args[1]); ///it returns pointer
 if(dr==NULL)
    {
       printf("Unable to Open Directory");
       return -1;
    }
    struct FileInfo f;
    while((de=readdir(dr))!=NULL)
    {
       sprintf(n,"%s/%s",args[1],de->d_name);
       if(stat(n,&ptr)==0)
       {
           f.FileName=de->d_name;
           f.Permision=ptr.st_mode & (S_IRWXU | S_IRWXG | S_IRWXO);
           f.Size=ptr.st_size;
           f.Type=de->d_type;

           //printf("\tperms: %o\n", ptr.st_mode & (S_IRWXU | S_IRWXG | S_IRWXO));
           write(fd,&f,sizeof(struct FileInfo));
       }
    
    }
   close(fd);
   int fd1=open("FileInfo.txt",O_RDONLY);
    int ret;
    while((ret=read(fd1,&f,sizeof(struct FileInfo)))!=0)
    { 
      printf("Name:%s Permission:%o Size:%d Type:%d\n",f.FileName,f.Permision,f.Size,f.Type);
       
       
    }
    close(fd1);
   
    closedir(dr);

  return 0;
}