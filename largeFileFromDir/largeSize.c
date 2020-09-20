
#include<stdio.h>
#include<dirent.h>
#include<fcntl.h>
#include<unistd.h>//for lseek
#include<string.h>
#include<sys/stat.h> //for stat function
int main(int argv,char *args[])
{
    if(argv!=2)
    {
        printf("Invalid Arguments\n");
        printf("Run: Exename directoery_name");
        return -1;
    }
    int fd;
    int size;
    int maxsize=0;
    const char* file;
    char* largefile;
    struct stat ptr;
    struct dirent *de; //Pointer for directoery Entry
    DIR *dr=opendir(args[1]); ///it returns pointer
    char* filename=args[1]+'/';
    if(dr==NULL)
    {
       printf("Unable to Open Directory");
       return -1;
    }
    while((de=readdir(dr))!=NULL)
    {
        if(de->d_type==8)
        {
       // file=strcat(filename,de->d_name);
       // printf("%s",file);
       char* name=de->d_name;
        if(stat((filename+name),&ptr)==0)
        {
            if(maxsize<ptr.st_size)
            {
                maxsize=ptr.st_size;
                largefile=de->d_name;
            }
        }
        }
        //printf("%ld:%s:%c\n",de->d_ino,de->d_name,de->d_type);
    }
    printf("File Having Lrgest Size %s:%d",largefile,maxsize);
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
