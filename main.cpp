#include <vector>
#include"LinkedList.h"
using namespace std;


void InsertAfter(int fvalue, int svalue, vector<int> &a )
{
	bool check=0;
	cout << "\n";
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] == fvalue)
		{
			a.insert(a.begin()+i+1, svalue);
			check = 1;
		}
	}
	if (!check)
		cout << "#ERROR! number "<<fvalue<<" doesn't exist in the vector.#\n";
	return;
}

void Display_vector(vector<int>& a)
{
	cout << "Vector:-> {  ";
	for (int i = 0; i < a.size(); i++)
	{
		cout << a.at(i)<<"  ";
	}
	cout <<"}" << endl;
}
void main()
{
	int n, size,fnum,snum;    //creating the vector
	vector<int>numbers;
	cout << "How many numbers: "; cin >> size;
	for (int i = 0; i < size; i++)
	{
		cout << "enter number: "; cin >> n;
		numbers.push_back(n);
	}
	Display_vector(numbers);


	cout << "\n-------------------------------\n";		//Insert after
	cout << "\nEnter the first value: "; cin >> fnum;
	cout << "Enter the second value to insert: "; cin >> snum;
	InsertAfter(fnum, snum, numbers);
	Display_vector(numbers);
	


	LinkedList *l;						//Linked List
	l = new LinkedList;
	l = l->v_copy(numbers);
	l->Display();


	cout << "\n* Sum of List= " << l->Sum();								//Features
	//l->Remove_Node();
	//l->Add_Node(0, 1);
	//l->Add_Node(10, 1);
	//l->Add_Node(100, 1);
	//l->Display();
	cout << "\n\n\n";
}