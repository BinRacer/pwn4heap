// base Asis CTF 2016 - b00ks
#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

#define MAXBOOKS 0x20

struct book_t {
  uint64_t id;
  char *name;
  char *desc;
  uint64_t desc_size;
};

uint64_t total_books = 0;
char author_name[0x20];
struct book_t *books[MAXBOOKS];

int64_t read_content(char *buf, uint64_t size) {
  if (buf == NULL || size == 0) {
    return -1;
  }
  char *cur = buf;
  uint64_t cnt = 0;
  ssize_t ret;
  while (cnt < size) {
    ret = read(0, cur, 1);
    if (ret == -1) {
      return -1;
    } else if (ret == 0) {
      break;
    }
    if (*cur == '\n') {
      break;
    }
    cur++;
    cnt++;
  }
  *cur = '\0';
  return cnt;
}

int64_t write_content(char *buf) { return write(1, buf, strlen(buf)); }

uint64_t read_uint64() {
  char nums[24];
  read_content(nums, 24 - 1);
  return strtoull(nums, 0, 0);
}

void menu() {
  write_content("1. Create a book\n");
  write_content("2. Delete a book\n");
  write_content("3. Edit a book\n");
  write_content("4. Print book detail\n");
  write_content("5. Change current author name\n");
  write_content("6. Exit\n");
  write_content("> ");
}

void create_book() {
  if (total_books > MAXBOOKS) {
    write_content("Library is full!");
    return;
  }
  write_content("Enter book name (Max 32 chars): ");
  char *name = (char *)malloc(0x20);
  memset(name, 0, 0x20 - 1);
  read_content(name, 0x20 - 1);
  write_content("Enter book description size: ");
  uint64_t size = read_uint64();
  write_content("Enter book description: ");
  char *desc = (char *)malloc(size);
  memset(desc, 0, size);
  read_content(desc, size - 1);
  struct book_t *book = (struct book_t *)malloc(sizeof(struct book_t));
  total_books += 1;
  book->id = total_books;
  book->name = name;
  book->desc = desc;
  book->desc_size = size;
  books[total_books - 1] = book;
}

void delete_book() {
  if (total_books <= 0) {
    write_content("Library is empty!\n");
    return;
  }
  write_content("Enter book id: ");
  uint64_t id = read_uint64();
  if (id <= 0 || id > MAXBOOKS || books[id - 1]->id == 0) {
    write_content("Wrong book id, Cat't find selected book!\n");
    return;
  }
  total_books -= 1;
  id -= 1;
  books[id]->id = 0;
  free(books[id]->name);
  free(books[id]->desc);
  free(books[id]);
  books[id] = NULL;
}

void edit_book() {
  if (total_books <= 0) {
    write_content("Library is empty!\n");
    return;
  }
  write_content("Enter book id: ");
  uint64_t id = read_uint64();
  if (id <= 0 || id > MAXBOOKS || books[id - 1]->id == 0) {
    write_content("Wrong book id, Cat't find selected book!\n");
    return;
  }
  write_content("Enter book description: ");
  read_content(books[id - 1]->desc, books[id - 1]->desc_size - 1);
}

void print_books() {
  write_content("Author: ");
  write_content(author_name);
  for (uint64_t i = 0; i < MAXBOOKS; i++) {
    if (books[i] == NULL || books[i]->id == 0) {
      continue;
    }
    write_content("------------------------------\n");
    fprintf(stdout, "ID: %ld\nName: %s\nDescription: %s\n", books[i]->id,
            books[i]->name, books[i]->desc);
    write_content("------------------------------\n");
  }
  fprintf(stdout, "Total books: %ld\n", total_books);
}

void change_author() {
  write_content("Enter author name: ");
  read_content(author_name, 0x20);
}

void init() {
  setbuf(stdin, 0);
  setbuf(stdout, 0);
  setbuf(stderr, 0);
}

int main() {
  init();
  write_content("Welcome to the pwn4heap book library!\n");
  write_content("Enter author name: ");
  read_content(author_name, 0x20);
  uint64_t flag = 1;
  while (flag) {
    menu();
    uint64_t choice = read_uint64();
    switch (choice) {
    case 1:
      create_book();
      break;
    case 2:
      delete_book();
      break;
    case 3:
      edit_book();
      break;
    case 4:
      print_books();
      break;
    case 5:
      change_author();
      break;
    case 6:
      write_content("Bye!\n");
      write_content("Thanks to use our library software!\n");
      exit(0);
    default:
      write_content("Wrong options\n");
      break;
    }
  }
  return 0;
}
