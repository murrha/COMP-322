#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>

void lsdir(const char *ch)
{
    DIR *dp;
    struct dirent *dir;
    chdir(ch);

    if((dp = opendir(".")) == NULL)
    {
        fprintf(stderr, "Unable to open directory.\n");
        exit(1);
    }//end if

    while((dir = readdir(dp)) != NULL)
    {
        if(dir->d_ino == 0)
            continue;

        if(dir->d_type == DT_DIR)
        {
            if(!strcmp(dir->d_name,".") || !strcmp(dir->d_name,".."))
                continue;
            printf("%s\n", dir->d_name);
            lsdir(dir->d_name);
            chdir("..");
        }
    }//end while

    closedir(dp);
}

int main(int argc, char *argv[])
{
    if(argc == 1)
        lsdir(".");

    else
        lsdir(argv[1]);
    return 0;
}

