// It Takes the directory name as the command line argumnet and then copy content  from each regular file into
//newly created AllCombine file


#include<stdio.h>
#include<dirent.h>
#include<fcntl.h>
#include<unistd.h>//for lseek
#include<string.h>
#include<sys/stat.h> //for stat function
#include<stdlib.h>  //dynamic memory allocation
int main(int argv,char *args[])
{
    if(argv!=2)
    {
        printf("Invalid Arguments\n");
        printf("Run: Exename directoery_name");
        return -1;
    }
    
    //const char* file;
    //char* largefile;
   // char *buffer=NULL;
    struct stat ptr;
    char* n=(char*)malloc(256);
    int fd=creat("AllCombine.txt",0777);
    int fd2=open("AllCombine.txt",O_RDWR||O_APPEND);
    if(fd2==-1)
    {
        printf("File cannot create successfully");
        return -1;
    }
    
    struct dirent *de; //Pointer for directoery Entry
    DIR *dr=opendir(args[1]); ///it returns pointer
    if(dr==NULL)
    {
       printf("Unable to Open Directory");
       return -1;
    }
    char buffer[512];
    int nread;
    while((de=readdir(dr))!=NULL)
    {
         if(de->d_type==8)   //consider only files not directories
         {
            
             sprintf(n,"%s/%s",args[1],de->d_name); //concat to get relative Path
             if(stat(n,&ptr)==0)
             {
               if(ptr.st_size!=0)
               {
                 int fd1=open(n,O_RDONLY);
                 while((nread=read(fd1,buffer,sizeof(buffer)))!=0)
                 {
                     write(fd2,buffer,nread);
                 }
                 close(fd1);
               } 
            
             }
             else
             {
               printf("EROOR\n");
             }
             
             
         }
    
    }
  
    closedir(dr);  //it close the directory

    return 0;
}
/*
struct dirent{
 unsigned lond d_ino  //inode number;
 char d_name[256]; //directroy name
 long d_off //
 unsigned short d_rclean;//
 unsigned char d_type; //
}*/