// It Take The source and destination directory names from user and then copy all the files and directories 
//from source to destination

#include<stdio.h>
#include<dirent.h> //directory structure
#include<stdlib.h>//dynamic memory allocation
#include<sys/stat.h>// for stat
#include<unistd.h> //for unlink lseek

int main(int argv,char *args[])
{
    if(argv!=3)
    {
        printf("Invalid Arguments\n");
        printf("Run: Exename directoery_name");
        return -1;
    }
    struct stat ptr;
    int flag=0;
    struct dirent *de; //Pointer for directoery Entry
     char* n=(char*)malloc(256);
      char* nwname=(char*)malloc(256);
    DIR *dr=opendir(args[1]); ///it returns pointer
    if(dr==NULL)
    {
       printf("Unable to Open Directory");
       return -1;
    }
    while((de=readdir(dr))!=NULL)
    {
         //if(de->d_type==8)  //to consider only files not directories
         //{
           
             sprintf(n,"%s/%s",args[1],de->d_name);  //concatenation to get the relative Path
             sprintf(nwname,"%s/%s",args[2],de->d_name);
             rename(de->d_name,nwname);

        // }
    }

    closedir(dr);

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
