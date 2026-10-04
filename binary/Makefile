# Top-level Makefile for `src/`.
# Recurses into each glibc-version branch and forwards the requested
# target to its `binary/Makefile`.

# glibc branches to recurse into.
VERSIONS := 2.23 2.27 2.31 2.35 2.39

.PHONY: all clean rebuild help

# Forward the requested target to `<version>/binary/`.
all clean rebuild help:
	@for v in $(VERSIONS); do \
	  echo "==> $$v/binary"; \
	  $(MAKE) -C $$v/binary $@ || exit $$?; \
	done
