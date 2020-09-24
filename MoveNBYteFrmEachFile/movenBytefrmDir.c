// It Takes the directory name as the command line argumnet and then copy 10 byte from each regular file into
//newly created demo file


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
    char *buffer=NULL;
    struct stat ptr;
    char* n=(char*)malloc(256);
    int fd=creat("demo.txt",0777);
    int fd2=open("demo.txt",O_RDWR||O_APPEND);
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
    while((de=readdir(dr))!=NULL)
    {
         if(de->d_type==8)   //consider only files not directories
         {
            
             sprintf(n,"%s/%s",args[1],de->d_name); //concat to get relative Path
             if(stat(n,&ptr)==0)
             {
               if(ptr.st_size!=0)
               {
                 buffer=(char*) malloc(10*sizeof(char));
                 int fd1=open(n,O_RDONLY);
                 int nread=read(fd1,buffer,10);
                if(write(fd2,buffer,10)!=0)
               {
                 printf("Sucessfull write of file %s\n",n);
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