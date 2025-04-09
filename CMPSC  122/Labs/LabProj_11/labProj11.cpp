#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
#include <stack>
#include <queue>
#include <random>
#include <ctime>

using namespace std;
// Methods
//  Node type:
struct TreeNode
{
    string studentName;
    float averageGrade;
    int numCourses;
    TreeNode *left;
    TreeNode *right;
};

// Two function's prototype
// 1. The inserted function is similar to the insert function introduced
// in class. However, update the course count and the average grade
// if the string is in the tree or insert the string if it is not there.
void Insert(TreeNode *&root, string studentName, float grade);
// 2. Prints the student names in the tree and their average grade values
// (tree traversal).
void PrintTree(TreeNode *root, ofstream &out);

void Insert(TreeNode *&root, string studentName, float grade)
{
    // If the tree is empty, create a new node and initialize it
    if (root == nullptr)
    {
        root = new TreeNode;
        root->studentName = studentName; // Set the student's name
        root->averageGrade = grade;     // Set the initial grade
        root->numCourses = 1;           // Initialize the course count to 1
        root->left = nullptr;           // Set left pointer to null
        root->right = nullptr;          // Set right pointer to null
    }
    // If the student's name is less than the current node's name, insert into the left subtree
    else if (studentName < root->studentName)
    {
        Insert(root->left, studentName, grade);
    }
    // If the student's name is greater than the current node's name, insert into the right subtree
    else if (studentName > root->studentName)
    {
        Insert(root->right, studentName, grade);
    }
    // If the student's name already exists in the tree, update the average grade and course count
    else
    {
        // Calculate the new average grade
        root->averageGrade = ((root->averageGrade * root->numCourses) + grade) / (++root->numCourses);
    }
}

void PrintTree(TreeNode *root, ofstream &out)
{
    if (root != nullptr)
    {
        PrintTree(root->left, out);
        out << root->studentName << " "
            << static_cast<int>(round(root->averageGrade)) << endl;
        PrintTree(root->right, out);
    }
}

int main()
{

    string inputFileName;
    string outputFileName;

    cout << "Please type the text file name: ";
    cin >> inputFileName;
    cout << "Please give the output text file name: ";
    cin >> outputFileName;

    ifstream inFile(inputFileName);
    if (!inFile)
    {
        cout << "Error opening input file." << endl;
        return 1;
    }
    ofstream outFile(outputFileName);
    if (!outFile)
    {
        cout << "Error opening output file." << endl;
        return 1;
    }

    // Create a binary search tree
    TreeNode *root = nullptr;
    string studentName, course;
    int grade;

    // Populate the tree with data from the input file
    while (inFile >> studentName >> course >> grade)
    {
        Insert(root, studentName, grade); // Only storing studentName and grade in the tree
    }

    // Write the tree to the output file
    PrintTree(root, outFile);

    // Close the files
    inFile.close();
    outFile.close();

    cout << "You are done! You can open the file \"sorted.txt\" to check." << endl;
    return 0;
}