//Quadritic probing


#include <iostream>
#include <vector>
using namespace std;

void insert_using_quadratic_probing(vector<int> &h)
{
    int n;
    cout << "Enter the number of elements that you want to insert = ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int a;
        cout << "Enter the element = ";
        cin >> a;

        int index = a % 10;
        int count = 0;
        int o = 0;
        int original_index=index;
        while (h[index] != -1 && count < 10){
            o++;
            o = (o*o) % 10;
            index = (original_index + o) % 10;
            count++;

            if (count == 10)
            {
                cout << "Table is full" << endl;
                return;
            }
        }
        h[index] = a;
    }
}

void displaying(const vector<int> &h)
{
    cout << "----------Hash Table -----------" << endl;
    for (int i = 0; i < 10; i++)
    {
        if (h[i] == -1)
        {
            cout << i << " : " << "Empty" << endl;
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
        cout << "----------Menu----------" << endl;
        cout << "1. Inserting using Quadratic probing" << endl;
        cout << "2. Display the hash table" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            insert_using_quadratic_probing(h);
            break;
        case 2:
            displaying(h);
            break;
        case 3:
            cout << "Exiting the program" << endl;
            break;
        default:
            cout << "Invalid choice. Please enter a valid choice." << endl;
        }
    } while (choice != 3);

    return 0;
}
