#include <map>
#include <tuple>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

enum class TaskStatus {
    NEW,          // нова€
    IN_PROGRESS,  // в разработке
    TESTING,      // на тестировании
    DONE          // завершена
};

using TasksInfo = map<TaskStatus, int>;

class TeamTasks {
public:
    const TasksInfo& GetPersonTasksInfo(const string& person) const {
        return persons_with_tasks.at(person);
    }
    void AddNewTask(const string& person) {
        ++persons_with_tasks[person][TaskStatus::NEW];
    }
    TasksInfo ClearMap(TasksInfo& map) {
        vector<TaskStatus> tmp;
        for (auto item : map) {
            if (item.second == 0) {
                tmp.push_back(item.first);
            }
        }
        for (auto item : tmp) {
            map.erase(item);
        }
        return map;
    }    
    tuple<TasksInfo, TasksInfo> PerformPersonTasks(const string& person, int task_count) {
        TasksInfo updated_tasks, untouched_tasks;
        if (persons_with_tasks[person].empty()) {
            return tie(updated_tasks, untouched_tasks);
        }
        auto New = persons_with_tasks[person][TaskStatus::NEW],
             In_progress = persons_with_tasks[person][TaskStatus::IN_PROGRESS],
             Testing = persons_with_tasks[person][TaskStatus::TESTING],
             Done = persons_with_tasks[person][TaskStatus::DONE];        
        auto summ = (New + In_progress + Testing);
        if (task_count > summ) {
            task_count = summ;
        }
        if (New < task_count) {
            updated_tasks[TaskStatus::IN_PROGRESS] = New;
            task_count -= New;
            if (In_progress < task_count) { 
                updated_tasks[TaskStatus::TESTING] = In_progress;
                task_count -= In_progress;
                Testing -= task_count;
                untouched_tasks[TaskStatus::TESTING] = Testing;
                Testing += In_progress;
                In_progress = 0;
                In_progress += New;
                New = 0;
                updated_tasks[TaskStatus::DONE] = task_count;
                Done += task_count;
            }
            else { 
                In_progress -= task_count;
                updated_tasks[TaskStatus::TESTING] = task_count;
                untouched_tasks[TaskStatus::IN_PROGRESS] = In_progress;
                untouched_tasks[TaskStatus::TESTING] = Testing;    
                In_progress += New;
                New = 0;
                Testing += task_count;                
            }
        }
        else {
            New -= task_count;
            updated_tasks[TaskStatus::IN_PROGRESS] = task_count;
            untouched_tasks[TaskStatus::NEW] = New;
            untouched_tasks[TaskStatus::IN_PROGRESS] = In_progress;
            untouched_tasks[TaskStatus::TESTING] = Testing;
            In_progress += task_count;
        }
        persons_with_tasks[person] = { {TaskStatus::NEW, New} , {TaskStatus::IN_PROGRESS, In_progress},
                                       {TaskStatus::TESTING, Testing}, {TaskStatus::DONE, Done} };       
        ClearMap(persons_with_tasks[person]);
        ClearMap(updated_tasks);
        ClearMap(untouched_tasks);
        return tie(updated_tasks, untouched_tasks);
    }
private:
    map<string, TasksInfo> persons_with_tasks;
};

//void PrintTasksInfo(TasksInfo tasks_info) {
//    cout << tasks_info[TaskStatus::NEW] << " "
//         << tasks_info[TaskStatus::IN_PROGRESS] << " "
//         << tasks_info[TaskStatus::TESTING] << " "
//         << tasks_info[TaskStatus::DONE] << endl;
//}
//
//int main() {
//    TeamTasks tasks;
//    TasksInfo updated_tasks, untouched_tasks;
//    for (int i = 0; i < 5; ++i) {
//        tasks.AddNewTask("Test");
//    }
//    // 1 этап
//    cout << "1st 5 0 0 0: ";
//    PrintTasksInfo(tasks.GetPersonTasksInfo("Test"));    
//    
//    tie(updated_tasks, untouched_tasks) =
//    tasks.PerformPersonTasks("Test", 3); 
//   
//    // 2 этап    
//    cout << "2nd 2 3 0 0: ";
//    PrintTasksInfo(tasks.GetPersonTasksInfo("Test"));
//
//    cout << "Old 2 0 0 0: ";
//    PrintTasksInfo(untouched_tasks);
//    
//    cout << "New 0 3 0 0: ";
//    PrintTasksInfo(updated_tasks);  
//    cout << endl;
//    
//    tie(updated_tasks, untouched_tasks) =
//    tasks.PerformPersonTasks("Test", 4);
//
//    // 3 этап 
//    cout << "3rd 0 3 2 0: ";
//    PrintTasksInfo(tasks.GetPersonTasksInfo("Test"));
//    
//    cout << "Old 0 1 0 0: ";
//    PrintTasksInfo(untouched_tasks);
//
//    cout << "New 0 2 2 0: ";
//    PrintTasksInfo(updated_tasks);  
//    cout << endl;
//    
//    tie(updated_tasks, untouched_tasks) =
//    tasks.PerformPersonTasks("Test", 2);
//
//    // 4 этап
//    cout << "4th 0 1 4 0: ";
//    PrintTasksInfo(tasks.GetPersonTasksInfo("Test"));
//
//    cout << "Old 0 1 2 0: ";
//    PrintTasksInfo(untouched_tasks);
//
//    cout << "New 0 0 2 0: ";
//    PrintTasksInfo(updated_tasks);
//    cout << endl;
//
//    tie(updated_tasks, untouched_tasks) =
//    tasks.PerformPersonTasks("Test", 3);
//
//    // 5 этап
//    cout << "5th 0 0 3 2: ";
//    PrintTasksInfo(tasks.GetPersonTasksInfo("Test"));
//
//    cout << "Old 0 0 2 0: ";
//    PrintTasksInfo(untouched_tasks);
//
//    cout << "New 0 0 1 0: ";
//    PrintTasksInfo(updated_tasks);
//    cout << endl;
//
//    return 0;
//}

// ѕример от разработчиков

//int main() {
//    TeamTasks tasks;
//    tasks.AddNewTask("Ilia");
//    for (int i = 0; i < 3; ++i) {
//        tasks.AddNewTask("Ivan");
//    }
//    cout << "Ilia's tasks: ";
//    PrintTasksInfo(tasks.GetPersonTasksInfo("Ilia"));
//    cout << "Ivan's tasks: ";
//    PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));
//
//    TasksInfo updated_tasks, untouched_tasks;
//
//    tie(updated_tasks, untouched_tasks) =
//        tasks.PerformPersonTasks("Ivan", 2);
//    cout << "Updated Ivan's tasks: ";
//    PrintTasksInfo(updated_tasks);
//    cout << "Untouched Ivan's tasks: ";
//    PrintTasksInfo(untouched_tasks);
//
//    tie(updated_tasks, untouched_tasks) =
//        tasks.PerformPersonTasks("Ivan", 2);
//    cout << "Updated Ivan's tasks: ";
//    PrintTasksInfo(updated_tasks);
//    cout << "Untouched Ivan's tasks: ";
//    PrintTasksInfo(untouched_tasks);
//
//    return 0;
//}

//“есты от форума
void PrintTasksInfo(const TasksInfo& tasks_info) {
    if (tasks_info.count(TaskStatus::NEW)) {
        std::cout << "NEW: " << tasks_info.at(TaskStatus::NEW) << " ";
    }
    if (tasks_info.count(TaskStatus::IN_PROGRESS)) {
        std::cout << "IN_PROGRESS: " << tasks_info.at(TaskStatus::IN_PROGRESS) << " ";
    }
    if (tasks_info.count(TaskStatus::TESTING)) {
        std::cout << "TESTING: " << tasks_info.at(TaskStatus::TESTING) << " ";
    }
    if (tasks_info.count(TaskStatus::DONE)) {
        std::cout << "DONE: " << tasks_info.at(TaskStatus::DONE) << " ";
    }
}

void PrintTasksInfo(const TasksInfo& updated_tasks, const TasksInfo& untouched_tasks) {
    std::cout << "Updated: [";
    PrintTasksInfo(updated_tasks);
    std::cout << "] ";

    std::cout << "Untouched: [";
    PrintTasksInfo(untouched_tasks);
    std::cout << "] ";

    std::cout << std::endl;
}

int main() {
    TeamTasks tasks;
    TasksInfo updated_tasks;
    TasksInfo untouched_tasks;

    /* TEST 1 */
    std::cout << "Alice" << std::endl;

    for (auto i = 0; i < 5; ++i) {
        tasks.AddNewTask("Alice");
    }
    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Alice", 5);
    PrintTasksInfo(updated_tasks, untouched_tasks);  // [{"IN_PROGRESS": 5}, {}]

    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Alice", 5);
    PrintTasksInfo(updated_tasks, untouched_tasks);  // [{"TESTING": 5}, {}]

    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Alice", 1);
    PrintTasksInfo(updated_tasks, untouched_tasks);  // [{"DONE": 1}, {"TESTING": 4}]

    for (auto i = 0; i < 5; ++i) {
        tasks.AddNewTask("Alice");
    }
    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Alice",
        2);  // [{"IN_PROGRESS": 2}, {"NEW": 3, "TESTING": 4}]
    PrintTasksInfo(updated_tasks, untouched_tasks);

    PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));  // {"NEW": 3, "IN_PROGRESS": 2, "TESTING": 4, "DONE": 1}
    std::cout << std::endl;

    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Alice", 4);
    PrintTasksInfo(updated_tasks, untouched_tasks);  // [{"IN_PROGRESS": 3, "TESTING": 1}, {"IN_PROGRESS": 1, "TESTING": 4}]

    PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));  // {"IN_PROGRESS": 4, "TESTING": 5, "DONE": 1}
    std::cout << std::endl;

    /* TEST 2 */
    std::cout << "\nJack" << std::endl;

    tasks.AddNewTask("Jack");

    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Jack", 1);
    PrintTasksInfo(updated_tasks, untouched_tasks);  // [{"IN_PROGRESS": 1}, {}]

    tasks.AddNewTask("Jack");

    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Jack", 2);
    PrintTasksInfo(updated_tasks, untouched_tasks);  // [{"IN_PROGRESS": 1, "TESTING": 1}, {}]

    tasks.AddNewTask("Jack");

    PrintTasksInfo(tasks.GetPersonTasksInfo("Jack"));  // {"NEW": 1, "IN_PROGRESS": 1, "TESTING": 1, "DONE": 0}
    std::cout << std::endl;

    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Jack", 3);
    PrintTasksInfo(updated_tasks, untouched_tasks);  // [{"IN_PROGRESS": 1, "TESTING": 1, "DONE": 1}, {}]

    PrintTasksInfo(tasks.GetPersonTasksInfo("Jack"));  // {"IN_PROGRESS": 1, "TESTING": 1, "DONE": 1}
    std::cout << std::endl;

    /* TEST 3 */
    std::cout << "\nLisa" << std::endl;

    for (auto i = 0; i < 5; ++i) {
        tasks.AddNewTask("Lisa");
    }

    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Lisa", 5);
    PrintTasksInfo(updated_tasks, untouched_tasks);  // [{"IN_PROGRESS": 5}, {}]

    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Lisa", 5);
    PrintTasksInfo(updated_tasks, untouched_tasks);  // [{"TESTING": 5}, {}]

    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Lisa", 1);
    PrintTasksInfo(updated_tasks, untouched_tasks);  // [{"DONE": 1}, {"TESTING": 4}]

    for (auto i = 0; i < 5; ++i) {
        tasks.AddNewTask("Lisa");
    }

    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Lisa", 2);
    PrintTasksInfo(updated_tasks, untouched_tasks);  // [{"IN_PROGRESS": 2}, {"NEW": 3, "TESTING": 4}]

    PrintTasksInfo(tasks.GetPersonTasksInfo("Lisa"));  // {"NEW": 3, "IN_PROGRESS": 2, "TESTING": 4, "DONE": 1}
    std::cout << std::endl;

    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Lisa", 4);
    PrintTasksInfo(updated_tasks, untouched_tasks);  // [{"IN_PROGRESS": 3, "TESTING": 1}, {"IN_PROGRESS": 1, "TESTING": 4}]

    PrintTasksInfo(tasks.GetPersonTasksInfo("Lisa"));  // {"IN_PROGRESS": 4, "TESTING": 5, "DONE": 1}
    std::cout << std::endl;

    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Lisa", 5);
    PrintTasksInfo(updated_tasks, untouched_tasks);  // [{"TESTING": 4, "DONE": 1}, {"TESTING": 4}]

    PrintTasksInfo(tasks.GetPersonTasksInfo("Lisa"));  // {"TESTING": 8, "DONE": 2}
    std::cout << std::endl;

    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Lisa", 10);
    PrintTasksInfo(updated_tasks, untouched_tasks);  // [{"DONE": 8}, {}]

    PrintTasksInfo(tasks.GetPersonTasksInfo("Lisa"));  // {"DONE": 10}
    std::cout << std::endl;

    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Lisa", 10);
    PrintTasksInfo(updated_tasks, untouched_tasks);  // [{}, {}]

    PrintTasksInfo(tasks.GetPersonTasksInfo("Lisa"));  // {"DONE": 10}
    std::cout << std::endl;

    tasks.AddNewTask("Lisa");

    PrintTasksInfo(tasks.GetPersonTasksInfo("Lisa"));  // {"NEW": 1, "DONE": 10}
    std::cout << std::endl;

    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Lisa", 2);
    PrintTasksInfo(updated_tasks, untouched_tasks);  // [{"IN_PROGRESS": 1}, {}]

    PrintTasksInfo(tasks.GetPersonTasksInfo("Lisa"));  // {"IN_PROGRESS": 1, "DONE": 10}
    std::cout << std::endl;

    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Bob", 3);
    PrintTasksInfo(updated_tasks, untouched_tasks);  // [{}, {}]

    return 0;
}