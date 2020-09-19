#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[])
{
   if (argc!=3)
   {
      printf("USAGE: programname source destination\n");
      return 1;
   }

   DIR *srcPtr;
   
   if (mkdir(argv[2],0777)<0)
   {
      printf("Unable to create directory %s (probably it already exists)\n",argv[2]);
   }
   srcPtr=opendir(argv[1]);
   if (srcPtr==NULL)
   {
      printf("BAD OPENDIR %s\n",argv[1]);
      return 1;
   }
   
   struct dirent *dirPtr;
   struct stat statbuff;
   int fdSrc,fdDest;
   char *path_copia;
   unsigned int len_path_copia;
   unsigned char c;

   chdir(argv[1]);
   while ((dirPtr=readdir(srcPtr))!=NULL)
   {
      if (lstat(dirPtr->d_name,&statbuff)<0)
      {
         printf("BAD LSTAT\n");
         return 1;
      }
      if (S_ISREG(statbuff.st_mode) &&
         (statbuff.st_mode & S_IXUSR )) //IT's A REGULAR FILE WITH EXECUTION rights for the owner
      {
         //COPY----
         len_path_copia=strlen(argv[2]);
         len_path_copia+=1+strlen(dirPtr->d_name);
         path_copia=(char *)malloc(len_path_copia*sizeof(char));
         
         strcpy(path_copia,argv[2]);
         strcat(path_copia,dirPtr->d_name);
         printf("Copying %s in %s\n",dirPtr->d_name,path_copia);
         if ( (fdDest=open(path_copia,O_CREAT|O_TRUNC|O_WRONLY,(statbuff.st_mode &S_IRWXU)|(statbuff.st_mode &S_IRWXG)|(statbuff.st_mode &S_IRWXO) ) ) <0 )
         {
            printf("BAD OPEN %s\n",path_copia);
            return 1;
         }
         if ( (fdSrc=open(dirPtr->d_name,O_RDONLY))<0 )
         {
            printf("BAD OPEN %s\n",dirPtr->d_name);
            return 1;
         }
         while (read(fdSrc,&c,1)==1)
         {
            write(fdDest,&c,1);
         }
         close(fdSrc);
         close(fdDest);
         free(path_copia);
      }
      
   }
   chdir("..");
   closedir (srcPtr);
   return 0;
}