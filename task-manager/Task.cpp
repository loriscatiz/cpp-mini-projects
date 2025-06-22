#include "Task.hpp"

#include <iostream>

Task::Task(size_t id, std::string title, Priority priority)
    : id(id), title(title), priority(priority), completed(false) {}

void Task::printDetails() const {
    std::string priorityString;
    switch (priority) {
        case Priority::LOW:
            priorityString = "Low";
            break;
        case Priority::MEDIUM:
            priorityString = "Medium";
            break;
        case Priority::HIGH:
            priorityString = "High";
            break;
        default:
            break;
    }

    std::string completedString;
    completed == true ? completedString = "true" : completedString = "false";

    std::cout << "Id: " << id << " Title: " << title << " Priority: " << priorityString
              << " Completed: " << completedString << '\n';
}

void Task::printBasic() const { std::cout << "Id: " << id << " Title: " << title << '\n'; }

bool Task::isCompleted() const { return completed; }

void Task::isCompleted(bool status) { completed = status; }
