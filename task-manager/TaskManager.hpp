#include <map>
#include <string>

#include "Task.hpp"

#pragma once

class TaskManager {
   private:
    std::map<size_t, Task> tasks;
    size_t idCounter = 0;

    bool addNewTask(const Task& task);
    void loadTasksFromFile();
    void writeTaskToFile(const Task& task);

   public:
    TaskManager(/* args */);
    ~TaskManager() = default;
    void printAllTasks() const;
    void printUncompletedTasks() const;
    void printCompletedTasks() const;
    void printDetailedTask(size_t id) const;
    bool completeTask(size_t id);
    void addNewTask(std::string title);
    void addNewTask(std::string title, Priority priority);
    bool deleteTask(size_t id);
    bool taskExists(size_t id) const;
};
