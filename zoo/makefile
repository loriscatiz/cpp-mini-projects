# Executable name
TARGET = zoo.app

# Source files
SRC = main.cpp Animal.cpp Dog.cpp Cat.cpp

# Compiler
CXX = g++

# Default rule
$(TARGET): $(SRC)
	$(CXX) $(SRC) -o $(TARGET)

# Clean rule
clean:
	rm -f $(TARGET)