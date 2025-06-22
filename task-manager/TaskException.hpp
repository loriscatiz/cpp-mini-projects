#include <iostream>

class TaskException : public std::runtime_error {
   public:
    TaskException(const std::string& message) : std::runtime_error(message) {};
};
