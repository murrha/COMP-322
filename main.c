/*Marja Centina
COMP 222
Section 16788 (3:30 PM - 4:45 PM)*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <pwd.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <grp.h>

int main(int argc, char *argv[])
{
  struct stat buf;
  struct passwd *password;
  struct group *gp;

  char *file, *home;
  uid_t uid;
  gid_t gid;

  int size = 0;
  int errors = 0;

  uid = getuid();
  gid = getgid();

  for (int k = 1; k < argc; k++)
    {
        //absolute path
        if(argv[k][0] == '/') {
        file = malloc(sizeof(argv[k]));
        file = strdup(argv[k]);
    }
    else //relative path
    {
        home = password->pw_dir;
        file = malloc(sizeof(home) + 1 + sizeof(argv[k]));
        strcat(file, home);
        strcat(file, "/");
        strcat(file, argv[k]);
    }

    //statement if unable to open file
    if (stat(file, &buf) == (-1)) {
      fprintf(stderr, "%s: cannot access %s\n",
                       argv[0], argv[k]);
      exit(1);
    }

    //gets the size of the file
    stat(file, &buf);
    size = buf.st_size;

    //print file permissions
    if(getgid() == buf.st_uid)
    {
        printf((S_ISDIR(buf.st_mode)) ? "d" : "-");

        //user permissions
        if(buf.st_mode & 0400)
        {
            printf("r");
        }
        else
        {
            printf("-");
        }
        if(buf.st_mode & 0200)
        {
            printf("w");
        }
        else
        {
            printf("-");
        }
        if(buf.st_mode & 0100)
        {
            printf("x");
        }
        else
        {
            printf("-");
        }
    }

    //find owner and group
    password = getpwuid(buf.st_uid);
    printf(" %s ", password->pw_name);

    gp = getgrgid(buf.st_gid);
    printf("%s ", gp->gr_name);

    //prints size of file
	printf("%d ", size);

	//prints time
	printf("%s ", ctime(&buf.st_mtime));

	//prints file name
	printf("%s\n", argv[k]);
  }

  if(errors)
    return(1);
  else
  free(file);
  exit(0);
}
