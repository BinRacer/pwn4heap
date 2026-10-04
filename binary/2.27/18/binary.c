// base https://ltfa1l.top/ and 0CTF 2016 - Zerostorage
#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

struct chunk {
  uint64_t size;
  uint64_t *addr;
};

struct profile_t {
  char author_name[0x20];
  uint64_t magic;
  char introduction[0x1000];
};
struct profile_t profile;
struct chunk chunks[0x20];

int64_t read_content(char *buf, uint64_t size) { return read(0, buf, size); }

int64_t write_content(char *buf) { return write(1, buf, strlen(buf)); }

uint64_t read_uint64() {
  char nums[24];
  read_content(nums, 24 - 1);
  return strtoull(nums, 0, 0);
}

void menu() {
  puts("Here are the Items to choose:");
  puts("1. Malloc");
  puts("2. Calloc");
  puts("3. Realloc");
  puts("4. Show");
  puts("5. Free");
  puts("6. Edit");
  puts("7. Change Profile");
  puts("8. Exit");
  write_content("> ");
}

void add_malloc() {
  write_content("Please input the chunk index: ");
  uint64_t index = read_uint64();
  write_content("Please input the size: ");
  uint64_t size = read_uint64();
  chunks[index].size = size;
  chunks[index].addr = malloc(size);
  write_content("Please input the content: ");
  read(0, chunks[index].addr, size);
  puts("\nDone.");
}

void add_calloc() {
  write_content("Please input the chunk index: ");
  uint64_t index = read_uint64();
  write_content("Please input the size: ");
  uint64_t size = read_uint64();
  chunks[index].size = size;
  chunks[index].addr = calloc(1, size);
  write_content("Please input the content: ");
  read(0, chunks[index].addr, size);
  puts("\nDone.");
}

void add_realloc() {
  write_content("Please input the chunk index: ");
  uint64_t index = read_uint64();
  write_content("Please input the size: ");
  uint64_t size = read_uint64();
  chunks[index].size = size;
  chunks[index].addr = realloc(chunks[index].addr, size);
  write_content("Please input the content: ");
  read(0, chunks[index].addr, size);
  puts("\nDone.");
}

void show() {
  printf("Author: %s\nIntroduction: %s\n", profile.author_name,
         profile.introduction);
  printf("------------------------------\n");
  printf("Please input the chunk index: ");
  uint64_t index = read_uint64();
  printf("Content: %s\n", (char *)chunks[index].addr);
  printf("------------------------------\n");
  printf("Done.\n");
}

void delete() {
  write_content("Please input the chunk index: ");
  uint64_t index = read_uint64();
  free(chunks[index].addr);
  puts("Done.");
}

void edit() {
  write_content("Please input the chunk index: ");
  uint64_t index = read_uint64();
  write_content("Please input the size: ");
  uint64_t size = read_uint64();
  chunks[index].size = size;
  write_content("Please input the content: ");
  read(0, chunks[index].addr, size);
  puts("\nDone.");
}

void change_profile() {
  write_content("Enter author name: ");
  read_content(profile.author_name, 0x20 - 1);
  write_content("Enter introduction: ");
  read_content(profile.introduction, 0x1000 - 1);
  puts("\nDone.");
}

void init() {
  setbuf(stdin, 0);
  setbuf(stdout, 0);
  setbuf(stderr, 0);
  FILE *fp = NULL;
  bool success = false;
  do {
    fp = fopen("/dev/urandom", "rb");
    if (!fp) {
      puts("Error opening /dev/urandom\n");
      break;
    }
    if (fread(&profile.magic, sizeof(profile.magic), 1, fp) != 1) {
      puts("Error reading from /dev/urandom.\n");
      break;
    }
    success = true;
  } while (false);
  if (fp) {
    fclose(fp);
  }
  if (!success) {
    exit(-1);
  }
}

int main() {
  init();
  puts("Welcome to the pwn4heap!");
  write_content("Enter author name: ");
  read_content(profile.author_name, 0x20 - 1);
  write_content("Enter introduction: ");
  read_content(profile.introduction, 0x1000 - 1);
  uint64_t flag = 1;
  while (flag) {
    menu();
    uint64_t choice = read_uint64();
    switch (choice) {
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
      change_profile();
      break;
    case 8:
      puts("OK, you said exit. See you!");
      exit(0);
    // case MAGIC:
    case 0x4d41474943:
      if (read_uint64() == profile.magic) {
        system("/bin/sh");
      } else {
        printf("magic addr: %p\n", &profile.magic);
      }
      break;
    default:
      puts("Wrong option");
      break;
    }
  }

  return 0;
}
