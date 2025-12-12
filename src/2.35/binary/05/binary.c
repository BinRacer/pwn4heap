// base https://ltfa1l.top/ and hitcontraining_lab14
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

uint64_t *chunks[0x20];
uint64_t magic = 0;

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

uint64_t read_uint64()
{
    char nums[24];
    read(0, nums, 23);
    return strtoull(nums, 0, 0);
}

int64_t write_content(char *string)
{
    return write(1, string, strlen(string));
}

void add_malloc()
{
    write_content("Please input the chunk index > ");
    uint64_t index = read_uint64();
    write_content("Please input the size > ");
    uint64_t size = read_uint64();
    chunks[index] = malloc(size);
    write_content("Please input the content > ");
    read(0, chunks[index], size);
    puts("\nDone.");
}

void add_calloc()
{
    write_content("Please input the chunk index > ");
    uint64_t index = read_uint64();
    write_content("Please input the size > ");
    uint64_t size = read_uint64();
    chunks[index] = calloc(1, size);
    write_content("Please input the content > ");
    read(0, chunks[index], size);
    puts("\nDone.");
}

void add_realloc()
{
    write_content("Please input the chunk index > ");
    uint64_t index = read_uint64();
    write_content("Please input the size > ");
    uint64_t size = read_uint64();
    chunks[index] = realloc(chunks[index], size);
    write_content("Please input the content > ");
    read(0, chunks[index], size);
    puts("\nDone.");
}

void show()
{
    write_content("Please input the chunk index > ");
    uint64_t index = read_uint64();
    puts((char*)chunks[index]);
    puts("Done.");
}

void delete()
{
    write_content("Please input the chunk index > ");
    uint64_t index = read_uint64();
    free(chunks[index]);
    puts("Done.");
}

void edit()
{
    write_content("Please input the chunk index > ");
    uint64_t index = read_uint64();
    write_content("Please input the size > ");
    uint64_t size = read_uint64();
    write_content("Please input the content > ");
    read(0, chunks[index], size);
    puts("\nDone.");
}

void init(){
    setbuf(stdin, 0);
    setbuf(stdout, 0);
    setbuf(stderr, 0);
    FILE* fp = NULL;
    bool success = false;
    do {
        fp = fopen("/dev/urandom", "rb");
        if(!fp) {
            puts("Error opening /dev/urandom\n");
            break;
        }
        if (fread(&magic, sizeof(magic), 1, fp) != 1) {
            puts("Error reading from /dev/urandom.\n");
            break;
        }
        success = true;
    } while(false);
    if(fp) {
        fclose(fp);
    }
    if(!success){
         exit(-1);
    }
}

int main()
{
    init();
    uint64_t flag = 1;
    while (flag)
    {
        menu();
        uint64_t choice = read_uint64();
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
        // case MAGIC:
        case 0x4d41474943:
            if (read_uint64() == magic) {
                system("/bin/sh");
            } else {
                puts("Magic is not available at this time.");
            }
            break;
        default:
            puts("Invalid choice, bye!");
            flag = 0;
            break;
        }
    }

    return 0;
}
