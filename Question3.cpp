// Max Shen 1123534 11/27/2024
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Element 
{
    int value;     
    int arrayIndex; 
    int elementIndex; 

    // priority queue comparator
    bool operator>(const Element& other) const 
    {
        return value > other.value; 
    }
};

vector<int> MergeArrays(const vector<vector<int>>& arrays) 
{
    priority_queue<Element, vector<Element>, greater<Element>> minHeap;

    // Insert the first element of each array
    for (int i = 0; i < arrays.size(); ++i) 
    {
        if (!arrays[i].empty()) {
            minHeap.push({ arrays[i][0], i, 0 });
        }
    }

    vector<int> mergedArray;

    // Process the min-heap until all elements are merged
    while (!minHeap.empty())
    {
        Element current = minHeap.top();
        minHeap.pop();

        mergedArray.push_back(current.value);

        // Insert the next element from the same array 
        if (current.elementIndex + 1 < arrays[current.arrayIndex].size()) 
        {
            minHeap.push({ arrays[current.arrayIndex][current.elementIndex + 1], current.arrayIndex, current.elementIndex + 1 });
        }
    }

    return mergedArray;
}

int main() 
{
    // Input 
    cout << "Enter the number ofarrays: ";
    int k;
    cin >> k;

    vector<vector<int>> arrays(k);
    cout << "Enter each sorted array on a new line:" << endl;

    for (int i = 0; i < k; ++i) {
        int size;
        cout << "Enter the size of array " << i + 1 << ": ";
        cin >> size;

        arrays[i].resize(size);
        cout << "Enter elements of array " << i + 1 << ": ";
        for (int j = 0; j < size; ++j) {
            cin >> arrays[i][j];
        }
    }

    // Merge the arrays
    vector<int> mergedArray = MergeArrays(arrays);

    // Output
    cout << "Merged Array: [";
    for (size_t i = 0; i < mergedArray.size(); ++i) 
    {
        cout << mergedArray[i];
        if (i != mergedArray.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
