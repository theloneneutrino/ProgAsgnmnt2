# Makefile for compiling C++ source files

# Compiler and flags
CXX = gcc
CXXFLAGS = -std=c2x -Wall -Werror -Wextra -g -O0 -DDEBUG

# Directories
SRCDIR = src
INCDIR = headers
BINDIR = .

# Source files and object files
SOURCES = $(wildcard $(SRCDIR)/*.c)
HEADERS = $(wildcard $(INCDIR)/*.h)
OBJECTS = $(SOURCES:$(SRCDIR)/%.c=$(BINDIR)/%.o)

# Output executable
TARGET = prog2
EXPORT = prog2.c

# Rules for building the executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Compile source files into object files
$(BINDIR)/%.o: $(SRCDIR)/%.c $(INCDIR)/%.h
	$(CXX) $(CXXFLAGS) -I$(INCDIR) -c $< -o $@

$(EXPORT): $(SOURCES) $(HEADERS)
	cpp-merge $< -o $@

# Clean rule
clean:
	rm -f $(OBJECTS) $(TARGET)

# Phony target to prevent conflicts with filenames
.PHONY: all clean export

# Default target
all: $(TARGET)

export: $(EXPORT)

# Usage: make         (to compile the program)
#        make clean   (to clean up object files and the executable)

