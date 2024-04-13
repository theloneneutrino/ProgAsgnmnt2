# Makefile for compiling C++ source files

# Compiler and flags
CXX = gcc
CXXFLAGS = -std=c2x -Wall -Wextra -g

# Directories
SRCDIR = src
INCDIR = headers
BINDIR = .

# Source files and object files
SOURCES = $(wildcard $(SRCDIR)/*.c)
OBJECTS = $(SOURCES:$(SRCDIR)/%.c=$(BINDIR)/%.o)

# Output executable
TARGET = prog2

# Rules for building the executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Compile source files into object files
$(BINDIR)/%.o: $(SRCDIR)/%.c
	$(CXX) $(CXXFLAGS) -I$(INCDIR) -c $< -o $@

# Clean rule
clean:
	rm -f $(OBJECTS) $(TARGET)

# Phony target to prevent conflicts with filenames
.PHONY: all clean

# Default target
all: $(TARGET)

# Usage: make         (to compile the program)
#        make clean   (to clean up object files and the executable)

