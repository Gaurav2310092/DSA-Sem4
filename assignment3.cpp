//linear prbing with chaining without replacement


#include <iostream>
#include <vector>
using namespace std;

void insertion(vector<int> &hash, vector<int> &chain, int count)
{
    int n;
    cout << "Enter the number that you want to insert = ";
    cin >> n;
    count++;
    int index = n % 10;
    if (hash[index] == -1)
    {
        hash[index] = n;
    }
    else if (count != 10 && index == hash[index] % 10)
    {
        while (chain[index] != -1)
        {
            index = chain[index];
        }
        int chain_index = index;
        while (hash[index] != -1)
        {
            index = (index + 1) % 10;
        }
        chain[chain_index] = index;
        if (hash[index] == -1)
        {
            hash[index] = n;
        }
    }
    else
    {
        while (hash[index] != -1)
        {
            index = (index + 1) % 10;
        }
        if (hash[index] == -1)
        {
            hash[index] = n;
        }
    }
}

void display(const vector<int> &hash, const vector<int> &chain)
{
    cout << "Index: Value  : Chain" << endl;
    for (int i = 0; i < 10; i++)
    {
        if (hash[i] == -1)
        {
            cout << i << "    : " << "Empty" << "  " << chain[i] << endl;
        }
        else
        {
            cout << i << "    : " << hash[i] << "      " << chain[i] << endl;
        }
    }
}


void search(vector<int>& hash , vector <int>& chain){
    int n;
    cout<<"Enter the vlaue that you want to search"<<endl;
    cin>>n;
    int count=0;
    int index=n%10;
    if(hash[index]==-1){
        cout<<"Element not present "<<endl;
        return;
    }
    else if(hash[index]==n){
        cout<<"Element is prsent at index "<<index<<endl;
        return ;
    }
    else if(hash[index]%10==index){
        while(hash[index]!=n && index!=-1){
            index=chain[index];
        }
        if(index==-1){
            cout<<"Element not present "<<endl;
            return;
        }
        else if(hash[index]==n){
            cout<<"Elment is present at index "<<index<<endl;
            return;
        }
    }
    else{
        while(hash[index]!=n && count<10){
            index=(index+1)%10;
        }
        if(hash[index]==n){
            cout<<"Element is prsent at index "<<index<<endl;
            return ;
        }
    }
}
int main()
{
    vector<int> hash(10, -1);
    vector<int> chain(10, -1);
    int choice;
    int count = 0;
    do
    {
        cout << endl;
        cout << "----------Menu----------" << endl;
        cout << "1.Insertion" << endl;
        cout << "2.Display" << endl;
        cout << "3.Searching"<<endl;
        cout << "3.Exit" << endl;
        cout << "Enter your choice " << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            insertion(hash, chain, count);
            break;
        case 2:
            display(hash, chain);
            break;
        case 3:
            search(hash,chain);
            break;
        case 4:
            cout << "Exiting the programm..." << endl;
            cout << endl;
            break;
        default:
            cout << "Invalid choice , please enter choice again" << endl;
        }
    } while (choice != 4);
}
