#include <stdio.h>
#include <unistd.h>

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char ** argv)
{
    if(argc != 2)
    {
        fprintf(stderr, "Usage: %s {FILE}\n", argv[0]);
        return 1;
    }

    int fd = open(argv[1], O_RDONLY);

    if(fd == -1)
    {
        fprintf(stderr, "Unable to open() file at: %s\n", argv[1]);
        return 2;
    }

    fprintf(stdout, "unsigned char foo = { ");
    unsigned char c = 0;

    read(fd, &c, sizeof (char));
    fprintf(stdout, "0x%x", c);
    while(read(fd, &c, sizeof(char)))
    {
        fprintf(stdout, ", 0x%x", c);
    }   
    fprintf(stdout, " };");

    close(fd);
}
