#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>


void printFileProperties(struct stat stats);


int main(int argc,char *argv[])
{
    if(argc!=2)
    {
        printf("Invalid Arguments\n");
        printf("Help:Use Exename Filename");
        return -1;
    }
   
    struct stat stats;


    // stat() returns 0 on successful operation,
    // otherwise returns -1 if unable to get file properties.
    if (stat(argv[1], &stats) == 0)
    {
        printFileProperties(stats);
    }
    else
    {
        printf("Unable to get file properties.\n");
        printf("Please check whether '%s' file exists.\n", argv[1]);
    }

    return 0;
}



/**
 * Function to print file properties.
 */
void printFileProperties(struct stat stats)
{
    struct tm dt;
    // File permissions
    printf("\nFile access: ");
    if (stats.st_mode & R_OK)
    {
        printf("read ");
    }
    if (stats.st_mode & W_OK)
    {
        printf("write ");
    }
    if (stats.st_mode & X_OK)
    {
        printf("execute");
    }

    // File size
    printf("\nFile Actual size: %ld", stats.st_size);
    //File size on Disk
      printf("\nFile size on disk: %ld", stats.st_blksize);
    //Inode number
    printf("\nInode number:%ld",stats.st_ino);
    //number of hard link
    printf("\nNO of Hard Link:%ld",stats.st_nlink);
    //no of blocks
    printf("\nNO of Blocks:%ld",stats.st_blocks);
    //user id of owner
       printf("\nUser id of owner:%d",stats.st_uid);
    //gruoup id
       printf("\nGroup id:%d",stats.st_gid);   
    //Device Id
       printf("\nDevice Id Containg File:%ld",stats.st_dev);
    // Get file creation time in seconds and 
    // convert seconds to date and time format
    dt = *(gmtime(&stats.st_ctime));
    printf("\nCreated on: %d-%d-%d %d:%d:%d", dt.tm_mday, dt.tm_mon, dt.tm_year + 1900, 
                                              dt.tm_hour, dt.tm_min, dt.tm_sec);

    // File modification time
    dt = *(gmtime(&stats.st_mtime));
    printf("\nModified on: %d-%d-%d %d:%d:%d\n", dt.tm_mday, dt.tm_mon, dt.tm_year + 1900, 
                                              dt.tm_hour, dt.tm_min, dt.tm_sec);

}