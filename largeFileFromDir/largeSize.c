
// It Takes the directory name as the command line argumnet and return the 
// filename having largest size

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
    int size=0;
    int maxsize=0;
    //const char* file;
    //char* largefile;
    char* name;
    char* n=(char*)malloc(256);
    struct stat ptr;
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
                 if(maxsize<ptr.st_size)
                 {
                     name=de->d_name;
                     size=ptr.st_size;
                 }

             }

         }
    
    }
    printf("Largest File Size is %d and File Name %s",size,name);  
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
