#include<stdio.h>
#include<dirent.h>
#include<string.h>
int main(int argv,char *args[])
{
    if(argv!=3)
    {
        printf("Invalid Arguments\n");
        printf("Run: Exename directoery_name file_to_search");
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
       
        if(!(strcmp(args[2],de->d_name)))
        {
            printf("Yes File Exist in Directory");
            closedir(dr);
            return 0;
        }
    }
    printf("File Not Present");
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