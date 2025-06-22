#include <string>

#pragma once

enum class Priority { LOW, MEDIUM, HIGH };

class Task {
   private:
    size_t id;
    std::string title;
    Priority priority;
    bool completed;

   public:
    Task(size_t id, std::string title, Priority priority = Priority::MEDIUM);
    ~Task() = default;
    void printDetails() const;
    void printBasic() const;
    bool isCompleted() const;
    void isCompleted(bool status);
};
