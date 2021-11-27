#include <stdio.h>
/*
#include <unistd.h>

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
*/

int main(int argc, char ** argv)
{
    if(argc != 2)
    {
        fprintf(stderr, "Usage: %s {FILE}\n", argv[0]);
        return 1;
    }

    FILE * fp = fopen(argv[1],"r");

    if(fp == NULL)
    {
        fprintf(stderr, "Unable to fopen() file at: %s\n", argv[1]);
        return 2;
    }

    int file_size = 0;

    fseek(fp, 0, SEEK_END);
    file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    if(file_size == 0)
    {
        fprintf(stderr, "File at %s is empty", argv[1]);
        return 3;
    }

    fprintf(stdout, "unsigned char foo[%d] = { ", file_size);
    unsigned char c = 0;

    fread(&c, sizeof(unsigned char), 1, fp);
    fprintf(stdout, "0x%x", c);

    while(fread(&c, sizeof(unsigned char), 1, fp))
    {
        fprintf(stdout, ", 0x%x", c);
    }   
    fprintf(stdout, " };");

    fclose(fp);
}
