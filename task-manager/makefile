# Executable name
TARGET = task-manager.app

# Source files
SRC = main.cpp Task.cpp TaskManager.cpp

# Compiler
CXX = g++

# Default rule
$(TARGET): $(SRC)
	$(CXX) $(SRC) -o $(TARGET)

# Clean rule
clean:
	rm -f $(TARGET)