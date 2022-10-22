#pragma once
#include<iostream>
using namespace std;
class LinkedList
{
private:
	struct Node
	{
		int value;
		int occ_time; //occurence time.
		Node* next;
	};

	Node* Head;
public:
	LinkedList()
	{
		Head = NULL;	
	}

	bool is_empty()			 //added
	{
		return (Head == NULL);
	} 

	void Add_Node(int v, int occ)   //we are adding at the end of the linked list alwyas.
	{
		Node *t = new Node;
		t->value = v;
		t->occ_time = occ;
		t->next = NULL;
		if (this->is_empty())
			Head = t;
		else
		{
			Node* bird = Head;
			while (bird->next != NULL)
			{
				bird = bird->next;
			}
			bird->next = t;
		}
	}
	
	void Remove_Node()   //removing the last node in the list.
	{
		if (this->is_empty())
			cout << "The list is already empty.\n";
		else
		{
			Node* bird1=Head;
			Node* bird2=NULL;
			while (bird1->next != NULL)
			{
				bird2 = bird1;
				bird1 = bird1->next;
			}
			delete bird1->next;
			if (bird2 == NULL)
				Head = NULL;
			else
				bird2->next = NULL;
		}
	}

	void Display()
	{
		if (this->is_empty())
		{
			cout << "#List is empty.#\n";
		}
		else
		{
			cout << "-------------------------------\n";
			cout << "LIST:- \nValue\tOcc_time\n";
			Node* bird = Head;
			while (bird != NULL)
			{
				cout << "  " << bird->value << "\t    " << (*bird).occ_time << endl;
				bird = bird->next;
			}
		}

	}

	int Sum()
	{
		int sum=0;
		Node* bird = Head;
		while (bird != NULL)
		{
			sum += bird->value;
			bird = bird->next;
		}
		return sum;
	}
	
	bool exist(int x)						//added
	{
		Node* bird;
		bird = Head;
		if (bird == NULL)
			return false;
		while (bird!=NULL)
		{
			if (bird->value == x)
				return true;
			bird = bird->next;
		}
		return false;
	}

	LinkedList* v_copy(vector<int> a)
	{
		int occ;
		int val;
		for (int i = 0; i < a.size(); i++)
		{
			occ = 0;
			val = a[i];
			if (!exist(a[i]))
			{
				for (int j = i; j < a.size(); j++)
				{
					if (a[j] == val)
						occ++;
				}
				Add_Node(val, occ);
			}
		}
		return this;
	}

};
