// Max Shen 1123534 11/27/2024
#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
#include <algorithm>

using namespace std;

// Node structure for the binary tree
struct Node 
{
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

Node* BinaTree(const vector<int>& values) 
{
    if (values.empty() || values[0] == -1) return nullptr;

    Node* root = new Node(values[0]);
    queue<Node*> q;
    q.push(root);

    size_t index = 1;

    while (!q.empty() && index < values.size()) 
    {
        Node* current = q.front();
        q.pop();

        if (values[index] != -1) {
            current->left = new Node(values[index]);
            q.push(current->left);
        }
        index++;

        if (index < values.size() && values[index] != -1)
        {
            current->right = new Node(values[index]);
            q.push(current->right);
        }
        index++;
    }

    return root;
}

// function to calculate height and diameter
int calcDiameter(Node* root, int& diameter) 
{
    if (root == nullptr)
    {
        return 0; 
    }

    int leftHeight = calcDiameter(root->left, diameter);
    int rightHeight = calcDiameter(root->right, diameter);

    diameter = max(diameter, leftHeight + rightHeight);

  
    return 1 + max(leftHeight, rightHeight);
}

// Function to get the diameter of the tree
int getDiameter(Node* root)
{
    int diameter = 0;
    calcDiameter(root, diameter);
    return diameter;
}

int main() 
{
    cout << "Enter the level-order traversal of the binary tree:" << endl;
    string input;
    getline(cin, input);

    // input into vector
    vector<int> values;
    stringstream ss(input);
    int val;
    while (ss >> val) {
        values.push_back(val);
    }

    // Build the binary tree
    Node* root = BinaTree(values);

    // diameter of the tree
    int diameter = getDiameter(root);

   
    cout << "The diameter is: " << diameter << endl;

    return 0;
}
