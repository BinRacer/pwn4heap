# Compiler and flags
CC = gcc
CFLAGS += -std=c99 -g -O0 -no-pie -Wno-unused-result -Wno-free-nonheap-object
LDLIBS += -ldl
TARGET = binary

# Custom glibc base path
ARCH := amd64
VERSION := 2.35
CUSTOM_GLIBC_BASE := /home/bogon/workSpaces/glibc-all-in-one/glibc

# Default target: build the binary
all: $(TARGET)

# Link the binary
$(TARGET): binary.c
	GLIBC_PATH="$(CUSTOM_GLIBC_BASE)/$(VERSION)/$(ARCH)/lib"; \
	$(CC) $(CFLAGS) -o $(TARGET) binary.c $(LDLIBS) \
	-Xlinker -rpath="$$GLIBC_PATH" \
	-Xlinker --dynamic-linker="$$GLIBC_PATH/ld-linux-x86-64.so.2" \
	"$$GLIBC_PATH/libc.so.6" \
	"$$GLIBC_PATH/libdl.so.2";
	@echo "Build finished: $(TARGET)"

# Clean build artifacts
.PHONY: clean
clean:
	rm -f $(TARGET)
	@echo "Cleanup completed."

# Rebuild: clean and then build
.PHONY: rebuild
rebuild: clean all

# Show help information
.PHONY: help
help:
	@echo "Available targets:"
	@echo "  make all     - Build the program (default target)"
	@echo "  make clean   - Remove the built binary"
	@echo "  make rebuild - Rebuild (clean and build again)"
	@echo "  make help    - Show this help message"
