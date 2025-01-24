//Linear probing 


#include <iostream>
#include <vector>
using namespace std;

void inserting(vector<int> &h)
{
    int n;
    cout << "Enter the number that you want to insert: ";
    cin >> n;

    int index = n % 10;
    if (h[index] == -1)
    {
        h[index] = n;
    }
    else
    {
        int count = 0;
        int originalIndex = index;
        while (h[index] != -1 && count < 10)
        {
            index = (index + 1) % 10;
            count++;
            if (count == 10)
            {
                cout << "Table is full" << endl;
                return;
            }
        }
        if (h[index] == -1)
        {
            h[index] = n;
        }
    }
}

int searching(const vector<int> &h)
{
    int n;
    cout << "Enter the element that you want to search: ";
    cin >> n;

    int index = n % 10;
    int count = 0;
    while (h[index] != n && count < 10)
    {
        index = (index + 1) % 10;
        count++;
        if (count == 10)
        {
            cout << "Element not found in the table" << endl;
            return -1;
        }
    }
    cout << "The index of " << n << " is " << index << endl;
    cout << "The number of steps to find " << n << " are " << count << endl;
}

void deleting(vector<int> &h)
{
    int n;
    cout << "Enter the element that you want to delete: ";
    cin >> n;

    int index = n % 10;
    int count = 0;
    while (h[index] != n && count < 10)
    {
        index = (index + 1) % 10;
        count++;
        if (count == 10)
        {
            cout << "Element not found in the table" << endl;
            return;
        }
    }
    if (h[index] == n)
    {
        h[index] = -2;
        cout << "Element deleted successfully" << endl;
    }
    cout << "The number of steps to delete " << n << " are " << count << endl;
}

void display(const vector<int> &h)
{
    cout << "Index: Value" << endl;
    for (int i = 0; i < 10; i++)
    {
        if (h[i] == -1)
        {
            cout << i << " : " << "Empty" << endl;
        }
        else if (h[i] == -2)
        {
            cout << i << " : " << "Deleted" << endl;
        }
        else
        {
            cout << i << " : " << h[i] << endl;
        }
    }
}

int main()
{
    vector<int> h(10, -1);
    int choice;
    do
    {
        cout << "------ Menu ------" << endl;
        cout << "1. Inserting an element" << endl;
        cout << "2. Display hash table" << endl;
        cout << "3. To search an element" << endl;
        cout << "4. To delete an element" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            inserting(h);
            break;
        case 2:
            display(h);
            break;
        case 3:
            searching(h);
            break;
        case 4:
            deleting(h);
            break;
        case 5:
            cout << "Exiting the program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
