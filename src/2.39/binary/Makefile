# Wrapper Makefile for a glibc-version binary directory.
# Forwards all / clean / rebuild / help to each numbered subdirectory.

# Subdirectories to recurse into: 01 .. 9
SUBDIRS := $(shell seq -w 01 09)

.PHONY: all clean rebuild help

# Forward the requested target to every subdirectory.
all clean rebuild help:
	@for d in $(SUBDIRS); do \
	  echo "==> $$d"; \
	  $(MAKE) -C $$d $@ || exit $$?; \
	done
