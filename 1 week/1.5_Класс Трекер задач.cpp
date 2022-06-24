#include <map>
#include <tuple>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class TeamTasks {
public:
    const TasksInfo& GetPersonTasksInfo(const string& person) const {
        return persons_with_tasks.at(person);
    }
    void AddNewTask(const string& person) {
        persons_with_tasks[person][TaskStatus::NEW] += 1;
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