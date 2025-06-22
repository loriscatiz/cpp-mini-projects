#include <iostream>

class TaskException : std::runtime_error {
   public:
    TaskException(std::string& message) : std::runtime_error(message) {};
};
