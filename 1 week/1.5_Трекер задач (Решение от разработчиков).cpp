#include <algorithm>
#include <map>
#include <string>
#include <tuple>
#include <vector>
#include <iostream>

using namespace std;

enum class TaskStatus {
    NEW,          // �����
    IN_PROGRESS,  // � ����������
    TESTING,      // �� ������������
    DONE          // ���������
};

// ������� � ��������� ������� ��������� ���������� �� ���������� ���� ������
// ������� �������� ���������� �� ������� ��������: �� �� ������ ���� ����� DONE
// ��� ���� task_status ���� �� ������������ � DONE, ��� ���������
// ������� ��� ������� ����������� �����������
TaskStatus Next(TaskStatus task_status) {
    return static_cast<TaskStatus>(static_cast<int>(task_status) + 1);
}

// ��������� ���-������� ��� map<TaskStatus, int>,
// ������������ ������� ���������� ����� ������� �������
using TasksInfo = map<TaskStatus, int>;

class TeamTasks {
public:
    // �������� ���������� �� �������� ����� ����������� ������������
    const TasksInfo& GetPersonTasksInfo(const string& person) const;

    // �������� ����� ������ (� ������� NEW) ��� ����������� ������������
    void AddNewTask(const string& person);

    // �������� ������� �� ������� ���������� ����� ����������� ������������
    tuple<TasksInfo, TasksInfo> PerformPersonTasks(
        const string& person, int task_count);

private:
    map<string, TasksInfo> person_tasks_;
};

const TasksInfo& TeamTasks::GetPersonTasksInfo(const string& person) const {
    return person_tasks_.at(person);
}

void TeamTasks::AddNewTask(const string& person) {
    ++person_tasks_[person][TaskStatus::NEW];
}

// ������� ��� �������� ����� �� �������
void RemoveZeros(TasksInfo& tasks_info) {
    // ������ �� �������, ������� ����� ������ �� �������
    vector<TaskStatus> statuses_to_remove;
    for (const auto& task_item : tasks_info) {
        if (task_item.second == 0) {
            statuses_to_remove.push_back(task_item.first);
        }
    }
    for (const TaskStatus status : statuses_to_remove) {
        tasks_info.erase(status);
    }
}


tuple<TasksInfo, TasksInfo> TeamTasks::PerformPersonTasks(
    const string& person, int task_count) {
    TasksInfo updated_tasks, untouched_tasks;

    // ����� � ����� �� ����� ������������ ��� ������, ��� � std::map �������� [] 
    // � ������ ���������� ����� �������������� �������� �� ���������,
    // ���� ��� ��������.
    // std::map::operator[] ->
    // http://ru.cppreference.com/w/cpp/container/map/operator_at
    TasksInfo& tasks = person_tasks_[person];

    // ���������, ������� ����� ������� �� �������� ����� ��������, 
    // ��������� ��� ������, ��� �� ��������� enum class ������������� ��������
    // �� ���� �� �����������.
    // enum class -> http://ru.cppreference.com/w/cpp/language/enum
    for (TaskStatus status = TaskStatus::NEW; status != TaskStatus::DONE; status = Next(status)) {
        // ������� ����������
        updated_tasks[Next(status)] = min(task_count, tasks[status]);
        // �������, ������� �������� ��������
        task_count -= updated_tasks[Next(status)];
    }

    // ��������� ������ ������� ����� � ������������ � ����������� �� ���������� 
    // � ������� ���������� ����������
    for (TaskStatus status = TaskStatus::NEW; status != TaskStatus::DONE; status = Next(status)) {
        untouched_tasks[status] = tasks[status] - updated_tasks[Next(status)];
        tasks[status] += updated_tasks[status] - updated_tasks[Next(status)];
    }
    // �� �������, DONE ������ �� ����� ���������� � �� ���������� �������
    tasks[TaskStatus::DONE] += updated_tasks[TaskStatus::DONE];

    // �� ������� � �������� �� ������ ���� �����
    RemoveZeros(updated_tasks);
    RemoveZeros(untouched_tasks);
    RemoveZeros(person_tasks_.at(person));

    return { updated_tasks, untouched_tasks };
}

void PrintTasksInfo(TasksInfo tasks_info) {
    cout << tasks_info[TaskStatus::NEW] << " "
         << tasks_info[TaskStatus::IN_PROGRESS] << " "
         << tasks_info[TaskStatus::TESTING] << " "
         << tasks_info[TaskStatus::DONE] << endl;
}

int main() {
    TeamTasks tasks;
    TasksInfo updated_tasks, untouched_tasks;
    for (int i = 0; i < 5; ++i) {
        tasks.AddNewTask("Test");
    }
    // 1 ����
    cout << "1st 5 0 0 0: ";
    PrintTasksInfo(tasks.GetPersonTasksInfo("Test"));    
    
    tie(updated_tasks, untouched_tasks) =
    tasks.PerformPersonTasks("Test", 3); 
   
    // 2 ����    
    cout << "2nd 2 3 0 0: ";
    PrintTasksInfo(tasks.GetPersonTasksInfo("Test"));

    cout << "Old 2 0 0 0: ";
    PrintTasksInfo(untouched_tasks);
    
    cout << "New 0 3 0 0: ";
    PrintTasksInfo(updated_tasks);  
    cout << endl;
    
    tie(updated_tasks, untouched_tasks) =
    tasks.PerformPersonTasks("Test", 4);

    // 3 ���� 
    cout << "3rd 0 3 2 0: ";
    PrintTasksInfo(tasks.GetPersonTasksInfo("Test"));
    
    cout << "Old 0 1 0 0: ";
    PrintTasksInfo(untouched_tasks);

    cout << "New 0 2 2 0: ";
    PrintTasksInfo(updated_tasks);  
    cout << endl;
    
    tie(updated_tasks, untouched_tasks) =
    tasks.PerformPersonTasks("Test", 2);

    // 4 ����
    cout << "4th 0 1 4 0: ";
    PrintTasksInfo(tasks.GetPersonTasksInfo("Test"));

    cout << "Old 0 1 2 0: ";
    PrintTasksInfo(untouched_tasks);

    cout << "New 0 0 2 0: ";
    PrintTasksInfo(updated_tasks);
    cout << endl;

    tie(updated_tasks, untouched_tasks) =
    tasks.PerformPersonTasks("Test", 3);

    // 5 ����
    cout << "5th 0 0 3 2: ";
    PrintTasksInfo(tasks.GetPersonTasksInfo("Test"));

    cout << "Old 0 0 2 0: ";
    PrintTasksInfo(untouched_tasks);

    cout << "New 0 0 1 0: ";
    PrintTasksInfo(updated_tasks);
    cout << endl;

    return 0;
}