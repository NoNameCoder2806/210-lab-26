// COMSC-210 | Lab 26 | Dat Hoang Vien
// IDE used: Visual Studio Code

// Libraries
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <chrono>
#include <vector>
#include <list>
#include <set>
#include <string>
using namespace std;
using namespace std::chrono;

// Enum class
enum class type{VECTOR, LIST, SET};

// Constants
const string DATA_PATH = "codes.txt";
const int OPERATIONS = 4;
const int DATA_STRUCTURES = 3;
const int SIMULATIONS = 15;
const string INSERT_ELEMENT = "TESTCODE";
const int FIELD_SIZE = 10;
const int VECTOR_NO = 0;
const int LIST_NO = 1;
const int SET_NO = 2;
const int READ_NO = 0;
const int SORT_NO = 1;
const int INSERT_NO = 2;
const int DELETE_NO = 3;

// Function prototypes
long long read(vector<string>& v);
long long read(list<string>& l);
long long read(set<string>& s);

long long sort(vector<string>& v);
long long sort(list<string>& l);
long long sort(set<string>& s);

long long insert(vector<string>& v);
long long insert(list<string>& l);
long long insert(set<string>& s);

long long deletion(vector<string>& v);
long long deletion(list<string>& l);
long long deletion(set<string>& s);

// Main function
int main()
{
    // Start timing
    auto start = high_resolution_clock::now();

    // Create data structures to race
    vector<string> v;
    list<string> l;
    set<string> s;

    // Create a 3D array to store the time
    long long results[DATA_STRUCTURES][OPERATIONS][SIMULATIONS] = {0};
    // First layer: each data structures
    // Second layer: the time for each operations
    // Third layer: the time for each operation in each experiments

    // Create a 2D array to store the sum
    long long sumResults[DATA_STRUCTURES][OPERATIONS] = {0};
    // First layer: each data structures
    // Second layer: the sum of time for each operation

    // Create a loop to perform all the operations 15 times
    for (int i = 0; i < SIMULATIONS; i++)
    {
        // Clear all the data every time
        v.clear();
        l.clear();
        s.clear();

        // Perform the read operation and store the result
        results[VECTOR_NO][READ_NO][i] = read(v);
        results[LIST_NO][READ_NO][i] = read(l);
        results[SET_NO][READ_NO][i] = read(s);

        // Perform the sort operation and store the result
        results[VECTOR_NO][SORT_NO][i] = sort(v);
        results[LIST_NO][SORT_NO][i] = sort(l);
        results[SET_NO][SORT_NO][i] = sort(s);

        // Perform the insert operation and store the result
        results[VECTOR_NO][INSERT_NO][i] = insert(v);
        results[LIST_NO][INSERT_NO][i] = insert(l);
        results[SET_NO][INSERT_NO][i] = insert(s);

        // Perform the delete operation and store the result
        results[VECTOR_NO][DELETE_NO][i] = deletion(v);
        results[LIST_NO][DELETE_NO][i] = deletion(l);
        results[SET_NO][DELETE_NO][i] = deletion(s);

        // Update the sum of the results
        for (int j = 0; j < OPERATIONS; j++)                 // For each operations
        {
            for (int k = 0; k < DATA_STRUCTURES; k++)        // For each data structures
            {
                sumResults[k][j] += results[k][j][i];        // Update the sum
            }
        }
    }

    // Display the number of simulations
    cout << "Number of simulations: " << SIMULATIONS << endl;

    // Display a header
    cout << setw(FIELD_SIZE) << right << "Operation";
    cout << setw(FIELD_SIZE) << right << "Vector";
    cout << setw(FIELD_SIZE) << right << "List";
    cout << setw(FIELD_SIZE) << right << "Set";
    cout << endl;

    // Create a loop to display all the average results
    for (int i = 0; i < OPERATIONS; i++)
    {
        // Display the operation
        if (i == 0)
        {
            // Read operation
            cout << setw(FIELD_SIZE) << right << "Read";
        }
        else if (i == 1)
        {
            // Sort operation
            cout << setw(FIELD_SIZE) << right << "Sort";
        }
        else if (i == 2)
        {
            // Insert operation
            cout << setw(FIELD_SIZE) << right << "Insert";
        }
        else
        {
            // Delete operation
            cout << setw(FIELD_SIZE) << right << "Delete";
        }

        // Display the race results
        for (int j = 0; j < DATA_STRUCTURES; j++)
        {
            // Display the time for each operation
            cout << setw(FIELD_SIZE) << right << sumResults[j][i] / 15;
        }

        // Enter a new line after each operation
        cout << endl;
    }

    return 0;
}

// Function implementations
/*
    read()
    Calculate the time to read and add all the data from DATA_PATH into a vector
    Arguments: 
        - v: a reference to a string vector
    Return:
        - time in microseconds
*/
long long read(vector<string>& v)
{
    // Create a file stream
    ifstream fin;
    fin.open(DATA_PATH);

    // Check for file stream error
    if (!fin.is_open())
    {
        // Display an error message
        cerr << "Error: could not open file " << DATA_PATH << endl;
        
        // Exit the function
        return -1;
    }

    // Create a string variable to store the line data
    string line = "";

    // Start timing
    auto start = high_resolution_clock::now();

    // Read the data
    while (getline(fin, line))
    {
        // Use push_back() to add element
        v.push_back(line);
    }

    // Clear and close the file stream
    fin.clear();
    fin.close();

    // End timing
    auto end = high_resolution_clock::now();

    // Calculate duration and return the result
    return duration_cast<microseconds>(end - start).count();
}

/*
    read()
    Calculate the time to read and add all the data from DATA_PATH into a list
    Arguments: 
        - l: a reference to a string list
    Return:
        - time in microseconds
*/
long long read(list<string>& l)
{
    // Create a file stream
    ifstream fin;
    fin.open(DATA_PATH);

    // Check for file stream error
    if (!fin.is_open())
    {
        // Display an error message
        cerr << "Error: could not open file " << DATA_PATH << endl;
        
        // Exit the function
        return -1;
    }

    // Create a string variable to store the line data
    string line = "";

    // Start timing
    auto start = high_resolution_clock::now();

    // Read the data
    while (getline(fin, line))
    {
        // Use push_back() to add element
        l.push_back(line);
    }

    // Clear and close the file stream
    fin.clear();
    fin.close();

    // End timing
    auto end = high_resolution_clock::now();

    // Calculate duration and return the result
    return duration_cast<microseconds>(end - start).count();
}

/*
    read()
    Calculate the time to read and add all the data from DATA_PATH into a set
    Arguments: 
        - s: a reference to a string set
    Return:
        - time in microseconds
*/
long long read(set<string>& s)
{
    // Create a file stream
    ifstream fin;
    fin.open(DATA_PATH);

    // Check for file stream error
    if (!fin.is_open())
    {
        // Display an error message
        cerr << "Error: could not open file " << DATA_PATH << endl;
        
        // Exit the function
        return -1;
    }

    // Create a string variable to store the line data
    string line = "";

    // Start timing
    auto start = high_resolution_clock::now();

    // Read the data
    while (getline(fin, line))
    {
        // Use insert() to add element
        s.insert(line);
    }

    // Clear and close the file stream
    fin.clear();
    fin.close();

    // End timing
    auto end = high_resolution_clock::now();

    // Calculate duration and return the result
    return duration_cast<microseconds>(end - start).count();
}

/*
    sort()
    Calculate the time to sort all elements in a vector
    Arguments: 
        - v: a reference to a string vector
    Return:
        - time in microseconds
*/
long long sort(vector<string>& v)
{
    // Start timing
    auto start = high_resolution_clock::now();

    // Use sort() from <algorithm> to sort vectors
    sort(v.begin(), v.end());

    // End timing
    auto end = high_resolution_clock::now();

    // Calculate duration and return the result
    return duration_cast<microseconds>(end - start).count();
}

/*
    sort()
    Calculate the time to sort all elements in a list
    Arguments: 
        - l: a reference to a string list
    Return:
        - time in microseconds
*/
long long sort(list<string>& l)
{
    // Start timing
    auto start = high_resolution_clock::now();

    // Use sort() member function for lists
    l.sort();

    // End timing
    auto end = high_resolution_clock::now();

    // Calculate duration and return the result
    return duration_cast<microseconds>(end - start).count();
}

/*
    sort()
    Returns -1 because sets are automatically sorted
    Arguments: 
        - s: a reference to a string set
    Return:
        - -1
*/
long long sort(set<string>& s)
{
    // Return -1 for sets because sets are sorted
    return -1;
}

/*
    insert()
    Insert the element INSERT_ELEMENT into the middle of a vector
    Arguments:
        - v: a reference to a string vector
    Return:
        - time in microseconds
*/
long long insert(vector<string>& v)
{
    // Start timing
    auto start = high_resolution_clock::now();

    // Use insert() member function for vector and pass in the middle position
    v.insert(v.begin() + v.size() / 2, INSERT_ELEMENT);

    // End timing
    auto end = high_resolution_clock::now();

    // Calculate duration and return the result
    return duration_cast<microseconds>(end - start).count();
}

/*
    insert()
    Insert the element INSERT_ELEMENT into the middle of a list
    Arguments:
        - l: a reference to a string list
    Return:
        - time in microseconds
*/
long long insert(list<string>& l)
{
    // Start timing
    auto start = high_resolution_clock::now();

    // Create an iterator
    auto it = l.begin();

    // Advance the iterator to the middle position
    advance(it, l.size() / 2);

    // Use insert() member function for sets
    l.insert(it, INSERT_ELEMENT);

    // End timing
    auto end = high_resolution_clock::now();

    // Calculate duration and return the result
    return duration_cast<microseconds>(end - start).count();
}

/*
    insert()
    Insert the element INSERT_ELEMENT into a set
    Arguments:
        - s: a reference to a string set
    Return:
        - time in microseconds
*/
long long insert(set<string>& s)
{
    // Start timing
    auto start = high_resolution_clock::now();

    // Use insert() member function for sets
    s.insert(INSERT_ELEMENT);

    // End timing
    auto end = high_resolution_clock::now();

    // Calculate duration and return the result
    return duration_cast<microseconds>(end - start).count();
}

/*
    deletion()
    Delete the middle element of a vector
    Arguments:
        - v: a reference to a string vector
    Return:
        - time in microseconds
*/
long long deletion(vector<string>& v)
{
    // Start timing
    auto start = high_resolution_clock::now();

    // Use erase() member function for vector and pass in the middle position
    v.erase(v.begin() + v.size() / 2);

    // End timing
    auto end = high_resolution_clock::now();

    // Calculate duration and return the result
    return duration_cast<microseconds>(end - start).count();
}

/*
    deletion()
    Delete the middle element of a list
    Arguments:
        - l: a reference to a string list
    Return:
        - time in microseconds
*/
long long deletion(list<string>& l)
{
    // Start timing
    auto start = high_resolution_clock::now();

    // Create an iterator
    auto it = l.begin();

    // Advance the iterator to the middle position
    advance(it, l.size() / 2);

    // Use erase() member function for sets
    l.erase(it);

    // End timing
    auto end = high_resolution_clock::now();

    // Calculate duration and return the result
    return duration_cast<microseconds>(end - start).count();
}

/*
    deletion()
    Delete the middle element of a set
    Arguments:
        - s: a reference to a string set
    Return:
        - time in microseconds
*/
long long deletion(set<string>& s)
{
    // Start timing
    auto start = high_resolution_clock::now();

    // Create an iterator
    auto it = s.begin();

    // Advance the iterator to the middle position
    advance(it, s.size() / 2);

    // Use erase() member function for sets
    s.erase(it);

    // End timing
    auto end = high_resolution_clock::now();

    // Calculate duration and return the result
    return duration_cast<microseconds>(end - start).count();
}