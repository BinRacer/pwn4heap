#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

// Linked list node structure
struct chunk_t {
  struct chunk_t *next;
  uint64_t data_size;
  char data[];
} __attribute__((aligned(16)));

// Global variables
static struct chunk_t *head = NULL;
static struct chunk_t *tail = NULL;
static uint64_t total_chunks = 0;

// Constant definitions
#define MAX_DATA_SIZE 0x1000
#define ALIGNMENT 16
#define MAX_INDEX_DIGITS 24

// ==================== Utility Functions ====================

/**
 * Safely read content into buffer
 */
int64_t read_content(char *buf, uint64_t size) {
  if (buf == NULL || size == 0)
    return -1;

  char *cur = buf;
  uint64_t cnt = 0;
  ssize_t ret;

  while (cnt < size) {
    ret = read(0, cur, 1);
    if (ret == -1)
      return -1;
    else if (ret == 0)
      break;

    if (*cur == '\n')
      break;
    cur++;
    cnt++;
  }

  if (cnt < size)
    *cur = '\0';
  return cnt;
}

/**
 * Safely write content
 */
int64_t write_content(const char *buf) {
  if (buf == NULL)
    return -1;
  return write(1, buf, strlen(buf));
}

/**
 * Read unsigned 64-bit integer
 */
uint64_t read_uint64() {
  char nums[MAX_INDEX_DIGITS];
  if (read_content(nums, MAX_INDEX_DIGITS - 1) <= 0)
    return 0;
  return strtoull(nums, NULL, 0);
}

/**
 * Calculate aligned total size
 */
uint64_t calculate_total_size(uint64_t data_size) {
  uint64_t total_size = sizeof(struct chunk_t) + data_size;
  return (total_size + ALIGNMENT - 1) & ~(ALIGNMENT - 1);
}

/**
 * Validate if data size is valid
 */
bool is_valid_data_size(uint64_t data_size) {
  return data_size > 0 && data_size <= MAX_DATA_SIZE;
}

/**
 * Validate if index is valid
 */
bool is_valid_index(uint64_t index) { return index < total_chunks; }

// ==================== Custom Calloc Wrapper ====================

/**
 * Custom calloc implementation to match malloc interface
 */
static void *my_calloc(size_t size) { return calloc(1, size); }

// ==================== Linked List Operations ====================

/**
 * Get chunk node by index
 */
struct chunk_t *get_chunk_by_index(uint64_t index) {
  if (!is_valid_index(index) || head == NULL)
    return NULL;

  struct chunk_t *current = head;
  for (uint64_t i = 0; i < index && current != NULL; i++) {
    current = current->next;
  }
  return current;
}

/**
 * Create new chunk node
 */
struct chunk_t *create_chunk(uint64_t data_size, const char *data,
                             void *(*alloc_func)(size_t),
                             const char *alloc_name) {
  if (!is_valid_data_size(data_size)) {
    printf("Invalid data size: %lu\n", data_size);
    return NULL;
  }

  uint64_t total_size = calculate_total_size(data_size);
  struct chunk_t *chunk = (struct chunk_t *)alloc_func(total_size);

  if (chunk == NULL) {
    printf("%s failed for size %lu\n", alloc_name, total_size);
    return NULL;
  }

  // Initialize chunk
  // memset(chunk, 0, total_size);
  chunk->data_size = data_size;
  chunk->next = NULL;

  // Copy data
  if (data != NULL && data_size > 0) {
    memcpy(chunk->data, data, data_size);
  }

  return chunk;
}

/**
 * Add chunk to the end of linked list
 */
void add_chunk_to_list(struct chunk_t *chunk) {
  if (chunk == NULL)
    return;

  if (head == NULL) {
    head = tail = chunk;
  } else {
    tail->next = chunk;
    tail = chunk;
  }
  total_chunks++;
}

/**
 * Remove chunk node from linked list
 */
void remove_chunk_from_list(struct chunk_t *chunk, struct chunk_t *prev) {
  if (chunk == NULL)
    return;

  if (prev == NULL) { // Delete head node
    head = chunk->next;
    if (tail == chunk)
      tail = NULL;
  } else {
    prev->next = chunk->next;
    if (tail == chunk)
      tail = prev;
  }
  total_chunks--; // Fix: Update chunk count when removing
}

/**
 * Replace chunk node in linked list
 */
void replace_chunk_in_list(struct chunk_t *old_chunk,
                           struct chunk_t *new_chunk) {
  if (old_chunk == NULL || new_chunk == NULL)
    return;

  // Set new chunk's next pointer
  new_chunk->next = old_chunk->next;

  // Update linked list pointers
  if (old_chunk == head) {
    head = new_chunk;
  } else {
    struct chunk_t *prev = head;
    while (prev != NULL && prev->next != old_chunk) {
      prev = prev->next;
    }
    if (prev != NULL)
      prev->next = new_chunk;
  }

  if (old_chunk == tail) {
    tail = new_chunk;
  }
}

// ==================== Data Operations ====================

/**
 * Read data into chunk
 */
bool read_data_into_chunk(struct chunk_t *chunk) {
  if (chunk == NULL)
    return false;

  write_content("Please input the data: ");
  if (read_content(chunk->data, chunk->data_size) < 0) {
    puts("Read data failed!");
    return false;
  }
  return true;
}

// ==================== Core Functions ====================

void add_malloc() {
  write_content("Please input the data size: ");
  uint64_t data_size = read_uint64();

  struct chunk_t *chunk = create_chunk(data_size, NULL, malloc, "malloc");
  if (chunk == NULL)
    return;

  if (!read_data_into_chunk(chunk)) {
    free(chunk);
    return;
  }

  add_chunk_to_list(chunk);
  puts("Done.");
}

void add_calloc() {
  write_content("Please input the data size: ");
  uint64_t data_size = read_uint64();

  // Use the globally defined my_calloc function instead of nested function
  struct chunk_t *chunk = create_chunk(data_size, NULL, my_calloc, "calloc");
  if (chunk == NULL)
    return;

  if (!read_data_into_chunk(chunk)) {
    free(chunk);
    return;
  }

  add_chunk_to_list(chunk);
  puts("Done.");
}

void add_realloc() {
  if (head == NULL) {
    puts("No chunks available!");
    return;
  }

  write_content("Please input the chunk index: ");
  uint64_t index = read_uint64();
  if (!is_valid_index(index)) {
    printf("Invalid index! Total chunks: %lu\n", total_chunks);
    return;
  }

  write_content("Please input the data size: ");
  uint64_t new_data_size = read_uint64();
  if (!is_valid_data_size(new_data_size)) {
    puts("Invalid size!");
    return;
  }

  struct chunk_t *old_chunk = get_chunk_by_index(index);
  if (old_chunk == NULL) {
    puts("Chunk not found!");
    return;
  }

  uint64_t new_total_size = calculate_total_size(new_data_size);
  struct chunk_t *new_chunk =
      (struct chunk_t *)realloc(old_chunk, new_total_size);

  if (new_chunk == NULL) {
    puts("realloc failed! Original chunk remains unchanged.");
    return; // Keep original chunk intact on failure
  }

  new_chunk->data_size = new_data_size;

  // If address changed, update linked list pointers
  if (new_chunk != old_chunk) {
    replace_chunk_in_list(old_chunk, new_chunk);
  }

  // Read new data
  write_content("Please input the data: ");
  read_content(new_chunk->data, new_data_size);

  puts("Done.");
}

void show_chunk() {
  if (head == NULL) {
    puts("No chunks available!");
    return;
  }
  write_content("Please input the chunk index: ");
  uint64_t index = read_uint64();
  if (!is_valid_index(index)) {
    printf("Invalid index! Total chunks: %lu\n", total_chunks);
    return;
  }

  struct chunk_t *chunk = get_chunk_by_index(index);
  if (chunk == NULL) {
    puts("Chunk not found!");
    return;
  }

  puts("------------------------------");
  printf("Index: %lu, Data Size: %lu\n", index, chunk->data_size);
  write_content("Data: ");
  write_content(chunk->data);
  putchar('\n');
  puts("------------------------------");
  puts("Done.");
}

void delete_chunk() {
  if (head == NULL) {
    puts("No chunks available!");
    return;
  }

  write_content("Please input the chunk index: ");
  uint64_t index = read_uint64();
  if (!is_valid_index(index)) {
    printf("Invalid index! Total chunks: %lu\n", total_chunks);
    return;
  }

  struct chunk_t *current = head;
  struct chunk_t *prev = NULL;
  uint64_t current_index = 0;

  // Find the node to delete and its predecessor
  while (current != NULL && current_index < index) {
    prev = current;
    current = current->next;
    current_index++;
  }

  if (current == NULL) {
    puts("Chunk not found!");
    return;
  }

  remove_chunk_from_list(current, prev);
  free(current);
  puts("Done.");
}

void edit_chunk() {
  if (head == NULL) {
    puts("No chunks available!");
    return;
  }

  write_content("Please input the chunk index: ");
  uint64_t index = read_uint64();
  if (!is_valid_index(index)) {
    printf("Invalid index! Total chunks: %lu\n", total_chunks);
    return;
  }

  struct chunk_t *chunk = get_chunk_by_index(index);
  if (chunk == NULL) {
    puts("Chunk not found!");
    return;
  }

  write_content("Please input the data size: ");
  uint64_t new_data_size = read_uint64();

  write_content("Please input the data: ");
  if (read_content(chunk->data, new_data_size) < 0) {
    puts("Read data failed!");
    return;
  }

  // Update actual data size
  if (new_data_size < chunk->data_size) {
    chunk->data_size = new_data_size;
  }

  puts("Done.");
}

// ==================== System Functions ====================

void cleanup() {
  struct chunk_t *current = head;
  while (current != NULL) {
    struct chunk_t *next = current->next;
    free(current);
    current = next;
  }
  head = tail = NULL;
  total_chunks = 0;
}

void init() {
  setbuf(stdin, NULL);
  setbuf(stdout, NULL);
  setbuf(stderr, NULL);
}

void menu() {
  puts("Here are the Items to choose:");
  puts("1. Malloc");
  puts("2. Calloc");
  puts("3. Realloc");
  puts("4. Show");
  puts("5. Free");
  puts("6. Edit");
  puts("7. Exit");
  write_content("> ");
}

int main() {
  init();
  puts("Welcome to the pwn4heap!");
  while (true) {
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
      show_chunk();
      break;
    case 5:
      delete_chunk();
      break;
    case 6:
      edit_chunk();
      break;
    case 7:
      puts("OK, you said exit. See you!");
      exit(0);
    default:
      puts("Invalid choice!");
      break;
    }
  }

  return 0;
}
