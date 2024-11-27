// Max Shen 112534 11/27/2024
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Task 
{
    int profit;
    int deadline;
};

//  sorting tasks by profit in descending order
bool compareTasks(const Task& t1, const Task& t2) 
{
    return t1.profit > t2.profit;
}

int scheduleTasks(vector<Task>& tasks)
{
    sort(tasks.begin(), tasks.end(), compareTasks);
    int maxDeadline = 0;
    for (const auto& task : tasks) 
    {
        maxDeadline = max(maxDeadline, task.deadline);
    }

    vector<int> slots(maxDeadline + 1, -1); 
    int totalProfit = 0;

    // Schedule tasks
    for (const auto& task : tasks) 
    {
        for (int slot = task.deadline; slot > 0; --slot) 
        {
            if (slots[slot] == -1) 
            { 
                slots[slot] = task.profit;
                totalProfit += task.profit; 
                break;
            }
        }
    }

    cout << "Scheduled Tasks: [";
    bool first = true;
    for (int i = 1; i <= maxDeadline; ++i) 
    {
        if (slots[i] != -1) {
            if (!first) cout << ", ";
            cout << slots[i];
            first = false;
        }
    }
    cout << "]" << endl;

    return totalProfit;
}

int main()
{
    // Input 
    cout << "Enter the number of tasks: ";
    int n;
    cin >> n;

    vector<Task> tasks(n);
    cout << "Enter the profit and deadline for each task:" << endl;
    for (int i = 0; i < n; ++i) 
    {
        cin >> tasks[i].profit >> tasks[i].deadline;
    }
    int maxProfit = scheduleTasks(tasks);

    // Output 
    cout << "Maximum Profit: " << maxProfit << endl;
    return 0;
}
