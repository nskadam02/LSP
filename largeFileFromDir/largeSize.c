#include<stdio.h>
#include<dirent.h>
#include<fcntl.h>
#include<unistd.h>//for lseek
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
    char *file;
    struct dirent *de; //Pointer for directoery Entry
    DIR *dr=opendir(args[1]); ///it returns pointer
    if(dr==NULL)
    {
       printf("Unable to Open Directory");
       return -1;
    }
    while((de=readdir(dr))!=NULL)
    {
        fd=open(de->d_name,O_RDONLY);
        size=lseek(fd,0,SEEK_END);
        if(size>maxsize)
        {
            maxsize=size;
            file=de->d_name;
        }
        //printf("%ld:%s:%c\n",de->d_ino,de->d_name,de->d_type);
    }
    printf("File Having Lrgest Size %s:%d",file,maxsize);
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