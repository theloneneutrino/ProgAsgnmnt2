# Makefile for compiling C++ source files

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g

# Directories
SRCDIR = src
INCDIR = headers
BINDIR = .

# Source files and object files
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(SOURCES:$(SRCDIR)/%.cpp=$(BINDIR)/%.o)

# Output executable
TARGET = a.out

# Rules for building the executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Compile source files into object files
$(BINDIR)/%.o: $(SRCDIR)/%.cpp
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

