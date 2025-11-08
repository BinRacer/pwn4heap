// code from https://ltfa1l.top/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

size_t *chunks[0x20];

void menu()
{
    puts("Welcome to the pwn4heap!");
    puts("Here are the Items to choose:");
    puts("1. Malloc");
    puts("2. Calloc");
    puts("3. Realloc");
    puts("4. Show");
    puts("5. Free");
    puts("6. Edit");
    puts("7. Exit");
    write(1, "Please input your choice > ", 28);
}

long read_long()
{
    char nums[8];
    read(0, nums, 8);
    return strtol(nums, 0, 0);
}

long write_content(char *string)
{
    return write(1, string, strlen(string));
}

void add_malloc()
{
    write_content("Please input the chunk index > ");
    long index = read_long();
    write_content("Please input the size > ");
    long size = read_long();
    chunks[index] = malloc(size);
    write_content("Please input the content > ");
    read(0, chunks[index], size);
    puts("\nDone.");
}

void add_calloc()
{
    write_content("Please input the chunk index > ");
    long index = read_long();
    write_content("Please input the size > ");
    long size = read_long();
    chunks[index] = calloc(1, size);
    write_content("Please input the content > ");
    read(0, chunks[index], size);
    puts("\nDone.");
}

void add_realloc()
{
    write_content("Please input the chunk index > ");
    long index = read_long();
    write_content("Please input the size > ");
    long size = read_long();
    chunks[index] = realloc(chunks[index], size);
    write_content("Please input the content > ");
    read(0, chunks[index], size);
    puts("\nDone.");
}

void show()
{
    write_content("Please input the chunk index > ");
    long index = read_long();
    puts((char*)chunks[index]);
    puts("Done.");
}

void delete()
{
    write_content("Please input the chunk index > ");
    long index = read_long();
    free(chunks[index]);
    puts("Done.");
}

void edit()
{
    write_content("Please input the chunk index > ");
    long index = read_long();
    write_content("Please input the size > ");
    long size = read_long();
    write_content("Please input the content > ");
    read(0, chunks[index], size);
    puts("\nDone.");
}

void init(){
    setbuf(stdin, 0);
    setbuf(stdout, 0);
    setbuf(stderr, 0);
}

int main()
{
    init();
    int flag = 1;
    while (flag)
    {
        menu();
        long choice = read_long();
        switch (choice)
        {
        case 1:
            add_malloc();
            break;
        case 2:
            add_calloc();
            break;
        case 3:
            add_realloc();
            break;
        case 4:
            show();
            break;
        case 5:
            delete();
            break;
        case 6:
            edit();
            break;
        case 7:
            puts("OK, you said exit. See you!");
            exit(0);
        default:
            puts("Invalid choice, bye!");
            flag = 0;
            break;
        }
    }

    return 0;
}
