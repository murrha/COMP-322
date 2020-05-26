/*Marja Centina
COMP 222
Section 16788 (3:30 PM - 4:45 PM)*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//read from keyboard
//also implement wc -l on command line

//arguments for the UNIX commands
int main(int argc, char **argv)
{
    //opening a filename
    FILE *fp = stdin; //holds reference to file
    int lineCount = 0; //will count lines for the file
    int findLine = 0;
    int set = 0;
    char *fileName, c;
    bool top = true;

    while(argv++, --argc)
    {
        if(!strcmp(*argv, "-l"))
            set = 1;

        else if(!(fp = fopen((fileName = *argv), "r")))
            {
                printf("\n");
                exit(1);
            }
    }
    //opens file and reads it
    fp = fopen(fileName, "r");

    //checks for the file is empty
    int size = 0;
    if(fp != NULL && set == 1)
    {
        fseek(fp, 0, SEEK_END);
        size = ftell(fp);
        rewind(fp);
    }

    //checks if the file is empty
    if(size == 0)
    {
        lineCount = 0;
        printf("%zu %s\n", lineCount, fileName);
        exit(1);
    }

    //reads the end of files
    while(c != EOF && set == 1)
    {
            if(top)
            printf("%zu ", ++lineCount);
            printf("%c", c);

            top = (c == '\n');
            if(c == '\n')
                findLine++;
            c = fgetc(fp); //prints contents of c
    }

    printf("\n");
    printf("%d\t%s\n", findLine, fileName);

    //closes file
    fclose(fp);
    return 0;
}
