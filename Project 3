/*Marja Centina
COMP 222
Section 16788 (3:30 PM - 4:45 PM)*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char **argv) //arguments for the UNIX commands
{
    //holds reference to file
    FILE *fp = stdin;

    //initialized variables
    int lineCount = 0, wordCount = 0, charCount = 0;
    bool setChar = false, setWord = false, setLine = false;

    //stores filename
    char *fileName, c;

    //arguments for UNIX
   while(argv++, --argc)
   {
       if(strcmp(*argv, "-c") == 0)
            setChar = true;
       else if(strcmp(*argv, "-l") == 0)
            setLine = true;
       else if(strcmp(*argv, "-w") == 0)
            setWord = true;

        //if unable to open the file
        else if(!(fp = fopen((fileName = *argv), "r")))
        {
            printf("\n");
            exit(1);
        }
   }//end while

   //opens file and reads it
   fp = fopen(fileName, "r");

   //checks for the file is empty
    int size = 0;
    if(fp != NULL)
    {
        fseek(fp, 0, SEEK_END);
        size = ftell(fp);
        rewind(fp);
    }

    //default for empty file
    if(size == 0)
    {
        printf("%zu", lineCount);
        printf("%zu ", wordCount);
        printf("%zu ", charCount);
        printf(" %s\n", fileName);
        exit(1);
    }

    //default for wc command without specific command
    if(setChar == false && setLine == false && setWord== false && fp != NULL)
        setChar = setLine = setWord = true;

    c = fgetc(fp);
    while(c != EOF)
    {
        charCount++;

        //checks for newline
        if(c == '\n' || c == '\0')
            lineCount++;

        //checks for whitespaces
        if(c == ' ' || c == '\t' || c == '\n' || c =='\0' || c == '\r')
            wordCount++;

        c = fgetc(fp);
    }//end while

    if(setLine) printf("%zu ", lineCount);
    if(setWord) printf("%zu ", wordCount);
    if(setChar) printf("%zu ", charCount);
    printf("%s\n", fileName);

    //closes file
    fclose(fp);
    return 0;
}
