#include "TaskManager.hpp"

#include <iostream>

#include "Task.hpp"

bool TaskManager::addNewTask(const Task& task) {
    tasks.insert({idCounter, task});

    writeTaskToFile(task);
    return true;
}

void TaskManager::writeTaskToFile(const Task& task) {}

TaskManager::TaskManager() {}

void TaskManager::printAllTasks() const {
    std::cout << "=== PRINTING ALL TASKS ===\n\n";

    for (const auto [id, task] : tasks) {
        task.printBasic();
    }
}

void TaskManager::printUncompletedTasks() const {
    std::cout << "=== PRINTING UNCOMPLETED TASKS ===\n\n";

    for (const auto [id, task] : tasks) {
        if (!task.isCompleted()) task.printBasic();
    }
}

void TaskManager::printCompletedTasks() const {
    std::cout << "=== PRINTING COMPLETED TASKS ===\n\n";

    for (const auto [id, task] : tasks) {
        if (task.isCompleted()) task.printBasic();
    }
}

void TaskManager::printDetailedTask(size_t id) const {
    Task t = tasks.at(id);
    t.printDetails();
}

bool TaskManager::completeTask(size_t id) {
    tasks.at(id).isCompleted(true);
    return true;
}

void TaskManager::addNewTask(std::string title) {
    Task task = Task(++idCounter, title);
    addNewTask(task);
}

void TaskManager::addNewTask(std::string title, Priority priority) {
    Task task = Task(++idCounter, title, priority);

    addNewTask(task);
}

bool TaskManager::deleteTask(size_t id) {
    tasks.erase(id);
    return true;
}
