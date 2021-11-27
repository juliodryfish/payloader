# payloader
A simple C program that turns the contents of a text file into a unsigned char buffer initialized with hex values in C syntax.

A simple example of output:

$./playloader file_name
unsigned char foo = { 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0xa };

In this example, file_name is a file named file_name containing "ABCDEFG1234567AAAAAAA".

You can then copy the output and paste it directly in your C project, so that you can perform payloads to test your applications in an easier way.
This also works with non-text files, it will put all the values in hex and in C syntax so that it's easier to assemble payloads.

The code is really simple, very beginner friendly.

I created this tool to help me assemble payloads for other projects, maybe it will help someone else.
