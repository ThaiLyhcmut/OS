# Compiler
CC=gcc
# Compiler flags
CFLAGS=-I.

# Directories
SRCDIR=src
INCLUDEDIR=include
BUILDDIR=build
BINDIR=bin

# Source files
SRCS=$(wildcard $(SRCDIR)/*.c)
# Object files
OBJS=$(patsubst $(SRCDIR)/%.c,$(BUILDDIR)/%.o,$(SRCS))
# Executable name
TARGET=$(BINDIR)/calc

# Targets
all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(BINDIR)
	$(CC) -o $@ $^ $(CFLAGS)

$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(BUILDDIR)
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -rf $(BUILDDIR) $(BINDIR)
