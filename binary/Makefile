# Top-level Makefile for `binary/`.
# Recurses into each glibc-version directory and forwards the requested
# target to its Makefile.

# glibc versions to recurse into.
VERSIONS := 2.23 2.27 2.31 2.35 2.39

.PHONY: all clean rebuild help

# Forward the requested target to `<version>/`.
all clean rebuild help:
	@for v in $(VERSIONS); do \
	  echo "==> $$v"; \
	  $(MAKE) -C $$v $@ || exit $$?; \
	done
