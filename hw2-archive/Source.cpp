#include<iostream>
#include<fstream>
#include<string>
#include <sstream>
#include "ArgumentManager.h"
#include<math.h>
using namespace std;

struct Node {
	long long num;
	int count;
	string numstr;
	Node* prev;
	Node* next;
};

void PrintForward(Node* head) {};

class DoubleLinkedList {
public:
	void Insert(int num)
	{
		Node * nd = new Node();
		Node * cur = tail->prev;
		nd->num = num;
		nd->numstr = "";
		string tempstr = to_string(num);
		
		count++;

		if (count < nod)
		{
			for (int i = tempstr.length(); i < m_digitsPerNode; i++)
			{
				nd->numstr += "0";
			}
			nd->numstr += tempstr;
		}
		else
		{
			nd->numstr = tempstr;

		}



		nd->next = head->next;
		nd->prev = head;

		head->next->prev = nd;
		head->next = nd;

	}

	string Print()
	{
		Node * c = head->next;
		string line = to_string(c->num);
		string line2;
		while (c != tail)
		{
			//cout << c->numstr;
			line2.append(c->numstr);
			c = c->next;
		}

		return line2;
		
	}

	int WhatList = 0;
	DoubleLinkedList() {		//first node of list starting from the front
		head = new Node();
		tail = new Node();
		nod = 0;
		head->next = tail;
		head->prev = NULL;
		tail->prev = head;
		tail->next = NULL;
		count = 0;
		sign = true;
		m_digitsPerNode = 0;

	};   // default construct


	DoubleLinkedList(const std::string& num, int digitsPerNode) {
		head = new Node();
		tail = new Node();
		nod = 0;
		head->next = tail;
		head->prev = NULL;
		tail->prev = head;
		tail->next = NULL;
		m_digitsPerNode = digitsPerNode;
		int numberNode = 0;
		int remainNum = 0;
		int tnum = 0;
		count = 0;
		numberNode = num.length() / digitsPerNode;
		remainNum = num.length() % digitsPerNode;


		if (remainNum != 0)
		{
			numberNode++;
		}

		int i = num.length() - 1;

		int count = num.length() - 1;


		int checkNum = 0;

		if (remainNum == 0) {

			for (int i = 0; i < numberNode; i++)
			{
				for (int j = 0; j < digitsPerNode; j++)
				{
					tnum = tnum + (num[count--] - 48) * pow(10, checkNum++);

				}

				this->Insert(tnum);
				checkNum = 0;
				tnum = 0;
			}

		}
		else
		{
			for (int i = 0; i < numberNode - 1; i++)
			{
				for (int j = 0; j < digitsPerNode; j++)
				{
					tnum = tnum + (num[count--] - 48) * pow(10, checkNum++);

				}
				this->Insert(tnum);


				checkNum = 0;
				tnum = 0;
			}


		}

		if (remainNum != 0)
		{
			for (int i = 0; i < remainNum; i++)
			{
				tnum = tnum + (num[count--] - 48) * pow(10, checkNum++);
			}

			this->Insert(tnum);

		}



	};



public:
	void Set(const std::string& num, int dpn, bool sn) {
	
		m_digitsPerNode = dpn;
		
		int numOfNode, total = 0, check = 0;
		int idx = num.length() - 1;


		numOfNode = num.length() / dpn;

		if (num.length() % dpn != 0)
			numOfNode++;

		nod = numOfNode;

		if (sn == true)
			sign = true;
		else
			sign = false;

		for (int i = 0; i < numOfNode; i++)
		{
			for (int j = 0; j < dpn; j++)
			{
				total = total + (num[idx--] - 48) * pow(10, j);
				check++;
				if (check == num.length())			
					break;
			}
			Insert(total);
			total = 0;
		}




	}
	int getDPN()
	{

		return m_digitsPerNode;
	}
	int getFirstData()
	{
		c = head->next;

		return c->num;


	}
	bool getSign()
	{
		if (sign == true)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool moveNext()
	{
		if (c == head)
		{
			return false;
		}

		c = c->prev;
		return true;
	}
	int getNextData()
	{
		if (c->next == NULL || c->next == tail)
		{
			return -1;
		}

		c = c->next;
		return c->num;


	}

	int getNOD()
	{

		return nod;
	}


	const Node* GetHead() const {
		return head;

	};
	const Node* GetTail() const {
		return tail;

	};

private:
	Node* head;
	Node* tail;
	Node* n;
	Node* list1;
	Node* list2;
	Node* c;
	bool sign;
	int count;
	int nod;
	int m_digitsPerNode;
	long long remainder; // for / operator
	float decimal;

};


bool compNegative(DoubleLinkedList &l1, DoubleLinkedList &l2)
{
	if (l1.getNOD() < l2.getNOD())
		return true;
	else if (l1.getNOD() > l2.getNOD())
		return false;
	else
	{
		if (l1.getFirstData() < l2.getFirstData())
			return true;
		else if (l1.getFirstData() > l2.getFirstData())
			return false;
		else
		{
			for (int i = 0; i < l1.getNOD(); i++)
			{
				int lnum = l1.getNextData();
				int rnum = l2.getNextData();
				if (lnum == -1 || rnum == -1)
					break;

				if (lnum < rnum)
					return true;
				else if (lnum > rnum)
					return false;
			}
			return false;
		}
	}

} 
bool compPositive(DoubleLinkedList &l1, DoubleLinkedList &l2)
{
	if (l1.getNOD() > l2.getNOD())
		return true;
	else if (l1.getNOD() < l2.getNOD())
		return false;
	else
	{
		if (l1.getFirstData() > l2.getFirstData())
			return true;
		else if (l1.getFirstData() < l2.getFirstData())
			return false;
		else
		{
			for (int i = 0; i < l1.getNOD(); i++)
			{
				int lnum = l1.getNextData();
				int rnum = l2.getNextData();
				if (lnum == -1 || rnum == -1)
					break;

				if (lnum > rnum)
					return true;
				else if (lnum < rnum)
					return false;
				
			}
			return false;
		}
	}

}

bool equal(DoubleLinkedList &l1, DoubleLinkedList &l2)
{
	if (l1.getNOD() > l2.getNOD())
		return false;
	else if (l1.getNOD() < l2.getNOD())
		return false;
	else
	{
		if (l1.getFirstData() > l2.getFirstData())
			return false;
		else if (l1.getFirstData() < l2.getFirstData())
			return false;
		else
		{
			for (int i = 0; i < l1.getNOD(); i++)
			{
				int lnum = l1.getNextData();
				int rnum = l2.getNextData();
				if (lnum == -1 || rnum == -1)
					break;

				if (lnum > rnum)
					return false;
				else if (lnum < rnum)
					return false;

			}
			return true;
		}
	}

}
bool lesscompPositive(DoubleLinkedList &l1, DoubleLinkedList &l2)
{
	if (l1.getNOD() > l2.getNOD())
		return false;
	else if (l1.getNOD() < l2.getNOD())
		return true;
	else
	{
		if (l1.getFirstData() < l2.getFirstData())
			return true;
		else if (l1.getFirstData() > l2.getFirstData())
			return false;
		else
		{
			for (int i = 0; i < l1.getNOD(); i++)
			{
				int lnum = l1.getNextData();
				int rnum = l2.getNextData();
				if (lnum == -1 || rnum == -1)
					break;

				if (lnum < rnum)
					return true;
				else if (lnum > rnum)
					return false;
			}
			return false;
		}
	}

}

DoubleLinkedList** PositiveSelectSort(DoubleLinkedList * ar[], int n)
{
	int i = 0;
	int j = 0;
	int target = 0;;
	DoubleLinkedList * p;

	for (i = 0; i < n - 1; i++)
	{
		target = i;

		for (j = i + 1; j<n; j++)
		{
			if (!compPositive(*ar[j], *ar[target]))
			{
				target = j;
			} 
		
		}

			p = ar[i];
			ar[i] = ar[target];
			ar[target] = p;
	}

	return ar;

}

DoubleLinkedList** NegativeSelectSort(DoubleLinkedList * ar[], int n)
{
	int i = 0;
	int j = 0;
	int target = 0;;
	DoubleLinkedList * p;

	for (i = 0; i < n - 1; i++)
	{
		target = i;

		for (j = i + 1; j<n; j++)
		{
			if (!compNegative(*ar[j], *ar[target]))
			{
				target = j;
			}

		}

		p = ar[i];
		ar[i] = ar[target];
		ar[target] = p;
	}

	return ar;

}
DoubleLinkedList** PositiveInsertSort(DoubleLinkedList * ar[], int n)
{
	int i = 0;
	int j = 0;
	DoubleLinkedList * p;


	for (i = 1; i<n; i++)
	{
		p = ar[i];

		for (j = i - 1; j >= 0; j--)
		{
			
			if (compPositive(*ar[j], *p))
			{
				ar[j + 1] = ar[j];
			}
			else
			{
				break;
			}
		}

		ar[j + 1] = p;
	}
	return ar;
}

DoubleLinkedList** NegativeInsertSort(DoubleLinkedList * ar[], int n)
{
	int i = 0;
	int j = 0;
	DoubleLinkedList * p;


	for (i = 1; i<n; i++)
	{
		p = ar[i];

		for (j = i - 1; j >= 0; j--)
		{

			if (compNegative(*ar[j], *p))
			{
				ar[j + 1] = ar[j];
			}
			else
			{
				break;
			}
		}

		ar[j + 1] = p;
	}
	return ar;
}


int main(int argc, char* argv[]) {

	if (argc < 2) {
		std::cerr << "Usage: infinitearithmetic \"input=xyz.txt;digitsPerNode=<number>;algorithm=<sort_type>;output=<file_name>\"\n";
	}
	ArgumentManager am(argc, argv);
	string filename = am.get("input");
	string outfile = am.get("output");
	ofstream ofs(outfile.c_str());

	
	int digitsPerNode = atoi(am.get("digitsPerNode").c_str());
	ifstream ifs(filename.c_str());
	string line;


	DoubleLinkedList * PositiveArr[11111];
	DoubleLinkedList * NegativeArr[11111];
	DoubleLinkedList l1[11111];

	string algorithm = am.get("algorithm");
	//int digitsPerNode = 2;
	bool sign = true;
	int i = 0;
	int j = 0;
	int index = 0;
	//ifstream ifs("test.txt");
	//string line;
	if (algorithm == "heap")
		index++;
	while (getline(ifs, line)) {
		string num1;

		num1 = line;

		if (!isdigit(num1[0]))
		{
			
			NegativeArr[j++] = &l1[index];
			sign = false;
			num1 = num1.substr(1, num1.length());
		}
		else
		{
			

			PositiveArr[i++] = &l1[index];
		}
		l1[index++].Set(num1, digitsPerNode, sign);
		sign = true;
	}



	if (algorithm == "select") {
		if (i != 0)
			PositiveSelectSort(PositiveArr, i);
		if (j != 0)
			NegativeSelectSort(NegativeArr, j);
		for (int k = 0; k < j; k++)
		{
			ofs << "-";
			//cout << "-";
			ofs << NegativeArr[k]->Print();
			if (k < i - 1)
				ofs << endl;
			//cout << endl;
		}

		for (int k = 0; k < i; k++)
		{
			ofs << PositiveArr[k]->Print();
			if (k < i - 1)
				ofs << endl;
			//cout << endl;
		}
	}
	else if (algorithm == "insert") {
		
		if (i != 0)
			PositiveInsertSort(PositiveArr, i);
		if (j != 0)
			NegativeInsertSort(NegativeArr, j);
		for (int k = 0; k < j; k++)
		{
			ofs << "-";
		//	cout << "-";
			ofs << NegativeArr[k]->Print();
			if (k < i - 1)
				ofs << endl;
		//	cout << endl;
		}

		for (int k = 0; k < i; k++)
		{
			ofs << PositiveArr[k]->Print();
			if (k < i - 1)
				ofs << endl;
		//	cout << endl;
		}
	}
	else if (algorithm == "quick") {



	}
	else if (algorithm == "merge") {
	}
	else if (algorithm == "heap") {

		

		

	}


	
	system("pause");
	
	return 0;
}