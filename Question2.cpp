//Max Shen 1123534 11/27/2024
#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

struct Task 
{
    string num;  // Task name
    int priority; // Task priority

    // max-heap comparator
    bool operator<(const Task& other) const 
    {
        return priority < other.priority; 
    }
};

int main()
{
    int n;
    cout << "Enter the number of operations: ";
    cin >> n;

    // Create a max heap to store tasks
    priority_queue<Task> maxHeap;

    // Processing each operation
    for (int i = 0; i < n; ++i)
    {
        string operation;
        cin >> operation;

        if (operation == "ADD") 
        {
            string taskNum;
            int priority;
            cin >> taskNum >> priority;
            maxHeap.push({ taskNum, priority });
        }
        else if (operation == "GET") 
        {
            if (!maxHeap.empty())
            {
                Task highestPriorityTask = maxHeap.top();
                maxHeap.pop(); // Remove task from the heap
                cout << highestPriorityTask.num << endl;
            }
            else 
            {
                cout << "No tasks available" << endl;
            }
        }
    }

    // Output
    cout << "Remaining tasks: [";
    vector<Task> remainingTasks;
    while (!maxHeap.empty()) {
        remainingTasks.push_back(maxHeap.top());
        maxHeap.pop();
    }

    // Order Reverse
    for (size_t i = 0; i < remainingTasks.size(); ++i) 
    {
        if (i > 0) cout << ", ";
        cout << "(" << remainingTasks[i].num << ", " << remainingTasks[i].priority << ")";
    }
    cout << "]" << endl;

    return 0;
}
