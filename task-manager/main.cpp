#include <iostream>

#include "TaskException.hpp"
#include "TaskManager.hpp"

void printChoices();
void readMode(const TaskManager& app);
void writeMode(TaskManager& app);
void addingTaskMode(TaskManager& app);
void deleteMode(TaskManager& app);
void completeMode(TaskManager& app);
void detailsMode(const TaskManager& app);
size_t safeReadSizeT();
size_t getValidTaskId(const TaskManager& app);

int main(int argc, char const* argv[]) {
    TaskManager app;
    bool isRunning = true;
    int choice;

    while (isRunning) {
        try {
            printChoices();
            choice = safeReadSizeT();

            switch (choice) {
                case 0:
                    isRunning = false;
                    break;
                case 1:
                    readMode(app);
                    break;
                case 2:
                    writeMode(app);
                    break;

                default:
                    break;
            }
        } catch (const TaskException& e) {
            std::cout << "Something went wrong: " << e.what() << '\n';
        }
    }

    return 0;
}

void printChoices() {
    std::cout << "=== TASK MANAGER APP ===\n\n"
              << "0: Quit the program\n"
              << "1: Enter reading mode\n"
              << "2: Enter writing mode\n";
}

void readMode(const TaskManager& app) {
    bool isRunning = true;
    int choice;

    while (isRunning) {
        std::cout << "=== READING MODE ===\n\n"
                  << "0: Go back\n"
                  << "1: See all your tasks\n"
                  << "2: See your uncompleted tasks\n"
                  << "3: See your completed tasks\n"
                  << "4: See the details about a particular task\n";
        choice = safeReadSizeT();

        switch (choice) {
            case 0:
                isRunning = false;
                break;
            case 1:
                app.printAllTasks();
                break;
            case 2:
                app.printUncompletedTasks();
                break;
            case 3:
                app.printCompletedTasks();
                break;
            case 4:
                detailsMode(app);
                break;

            default:
                break;
        }
    }
}

void writeMode(TaskManager& app) {
    bool isRunning = true;
    int choice;

    while (isRunning) {
        std::cout << "=== WRITING MODE ===\n\n"
                  << "0: Go back\n"
                  << "1: Add a new task\n"
                  << "2: Mark a task as completed\n"
                  << "3: Permanently delete a task\n";
        choice = safeReadSizeT();

        switch (choice) {
            case 0:
                isRunning = false;
                break;
            case 1:
                addingTaskMode(app);
                break;
            case 2:
                completeMode(app);
                break;
            case 3:
                deleteMode(app);
                break;
            default:
                break;
        }
    }
}

void detailsMode(const TaskManager& app) {
    std::cout << "Enter the id of the task you want to see details about: ";
    app.printDetailedTask(getValidTaskId(app));
}

void completeMode(TaskManager& app) {
    std::cout << "Enter the id of the task you want to mark as complete: ";
    app.completeTask(getValidTaskId(app));
}

void deleteMode(TaskManager& app) {
    std::cout << "Enter the id of the task you want to permanently delete: ";
    app.deleteTask(getValidTaskId(app));
}

size_t safeReadSizeT() {
    size_t value;
    std::cin >> value;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        throw TaskException("Failed to cast to positive integer");
    }
    return value;
}

void addingTaskMode(TaskManager& app) {
    size_t priorityChoice = 4;
    while (priorityChoice > 3 || priorityChoice < 1) {
        std::cout << "=== Priority ===\n\n1: Low\n2: Medium\n3: High\n";
        priorityChoice = safeReadSizeT();
    }
    Priority priority = priorityChoice == 1   ? Priority::LOW
                        : priorityChoice == 2 ? Priority::MEDIUM
                                              : Priority::HIGH;

    std::cout << "=== Title ===\n\nEnter the title for the task and press enter:\n";
    std::cin.ignore();
    std::string title;
    std::getline(std::cin, title);

    app.addNewTask(title, priority);
}

size_t getValidTaskId(const TaskManager& app) {
    size_t id = safeReadSizeT();

    if (!app.taskExists(id)) {
        throw TaskException("Id not found");
    }

    return id;
}
