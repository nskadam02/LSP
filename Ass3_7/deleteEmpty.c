// It Take The directory name from user delete the file havng size 0 means empty files 
// from that directory

#include<stdio.h>
#include<dirent.h> //directory structure
#include<stdlib.h>//dynamic memory allocation
#include<sys/stat.h>// for stat
#include<unistd.h> //for unlink lseek

int main(int argv,char *args[])
{
    if(argv!=2)
    {
        printf("Invalid Arguments\n");
        printf("Run: Exename directoery_name");
        return -1;
    }
    struct stat ptr;
    int flag=0;
    struct dirent *de; //Pointer for directoery Entry
     char* n=(char*)malloc(256);
    DIR *dr=opendir(args[1]); ///it returns pointer
    if(dr==NULL)
    {
       printf("Unable to Open Directory");
       return -1;
    }
    while((de=readdir(dr))!=NULL)
    {
         if(de->d_type==8)  //to consider only files not directories
         {
           
             sprintf(n,"%s/%s",args[1],de->d_name);  //concatenation to get the relative Path
             if(stat(n,&ptr)==0)
             {
                if(ptr.st_size==0)
                {
                    flag=1;
                    if(unlink(n)==0)   //system call to delete the file
                    {
                        printf("File Name %s deleted Successfully having Size %ld\n",n,ptr.st_size);
                    }
                }

             }

         }
    }
    if(flag==0)  // If none of the File is empty
    {
        printf("No file Having Size 0");
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