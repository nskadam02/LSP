
  // This Program Takes the directory and 
//display all the files in directory and type of the file

#include<stdio.h>
#include<dirent.h>
char* checktype(int);
int main(int argv,char *args[])
{
    if(argv!=2)
    {
        printf("Invalid Arguments\n");
        printf("Run: Exename directoery_name");
        return -1;
    }
    struct dirent *de; //Pointer for directoery Entry structure
    DIR *dr=opendir(args[1]); ///it returns pointer
    if(dr==NULL)
    {
       printf("Unable to Open Directory");
       return -1;
    }
    while((de=readdir(dr))!=NULL)
    {
        printf("Name:%s Type:%s\n",de->d_name,checktype(de->d_type));
    }
    closedir(dr);

    return 0;
}


//Thgis function take the d_type which is integer and gave the proper file type in string
char* checktype(int d)
{
    char* type;
    switch(d)
    {
        case 0:
          type="Unknown";
          break;
        case 1:
        type="FIFO";
          break;
        case 2:
        type="Character";
          break;  
        case 4:
        type="Directory File";
          break;
        case 6:
        type="Block";
          break;  
        case 8:
        type="Regular File";
          break;  
        case 10:
        type="Link";
          break;  
        case 12:
        type="Socket";
          break;  
        case 14:
        type="WHT";
          break; 
        default:
         printf("Inavlid");        
    }
    return type;
}

/*
struct dirent{
 unsigned lond d_ino  //inode number;
 char d_name[256]; //directroy name
 long d_off //
 unsigned short d_rclean;//
 unsigned char d_type; //
}*/
