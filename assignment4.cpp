#include<iostream>
#include<vector>
using namespace std;

void insertion(vector <int>& hash , vector <int>& chain,int count){
    int n;
    cout<<"Enter the number tha you want to insert =";
    cin>>n;
    count++;
    int index=n%10;
    if(hash[index]==-1){
        hash[index]=n;
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
    else if(count!=10){
        int new_index=index;
        int old_element=hash[index];
        hash[index]=n;
        int new_chain_index=chain[index];
        chain[index]=-1;
        while(hash[index]!=-1){
            index=(index+1)%10;
        }
        if(hash[index]==-1){
            hash[index]=old_element;
            chain[index]=new_chain_index;
        }
        for(int i=0; i<10; i++){
            if(chain[i]==new_index){
                chain[i]=index;
            }
        }
    }
    else{
        cout<<"Table is already full"<<endl;
    }

}

int searching(vector <int>& hash ,vector <int>& chain,int count){
    int n;
    cout<<"Enter the number tha you want to search =";
    cin>>n;
    count++;
    int index=n%10;
    if(hash[index]==-1){
        return index;
    }
    else 
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
            return index;
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
            searching(hash,chain,count);
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