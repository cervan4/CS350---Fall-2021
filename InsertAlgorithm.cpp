/*
	Luis Cervantes Oropeza 
	HW 3 CS350
*/
#include <cctype>
#include <iostream>
#include <cstring>
using namespace std;

int sort(int & p1, int & p2, int & pivot, int & high, int & low);
void display();
int size = 0;
int value[1000];
int flag = 0;
int flag2 = 0;
int t1 = 0;
int t2 = 0 ;
int t3 = 0 ;
int main()
{
	for(int loop = 0; loop < 1000; loop++)
	{
		value[loop] = 0;
	}
	cout<<"How many digits are you going to enter: ";
	cin>>size;
	cin.ignore();
	for(int loop = 0; loop < size; loop++)
	{
		cout<<"Enter in digit: ";
		cin>>value[loop]; 
	}
	int p1 = 1;
	int p2 = size - 1;	
	int pivot = 0;
	int high = size -1;
	int low = 0;
	t1 = low;
	t2 = high;
	sort(p1,p2,pivot, high,low);
	display();
	return 0;
}
int sort(int & p1, int & p2, int & pivot, int & high, int & low)
{
	if(high < low || low > high || low == high)
	{
		return 0;
	}	
	while(p1 != p2)
	{
		if(value[p1] > value[pivot])
		{
			flag = 1;
		}
		if(value[p2] < value[pivot])
		{
			flag2 = 1;
		}
		if(flag == 1 && flag2 == 1)
		{
			int tmp = value[p1];
			cout<<"value of value[p1] before change: "<<value[p1]<<endl;
			cout<<"value of value[p2] before change: "<<value[p2]<<endl;
			value[p1] = value[p2];
			value[p2] = tmp;
			cout<<"value of value[p1] after change: "<<value[p1]<<endl;
			cout<<"value of value[p2] after change: "<<value[p2]<<endl;
			flag = 0;
			flag2 = 0;
		}
		
		if(flag == 1 && flag2 != 1)
		{
			p2--;
		}
		if(flag == 0 && flag2 == 0)
		{
			p2--;
			p1++;
		}
		if(flag == 0 && flag2 == 1)
		{
			p1++;
		}
	}
	if(p1 == p2)
	{
		int tmp = 0;
		if(value[p2] < value[pivot])
		{
			tmp = value[pivot];
			value[pivot] = value[p2];
			value[p2] = tmp;
			t3 = p2;
		}
		else if(value[p2] > value[pivot])
		{
			value[pivot] = value[pivot];
		}
		else
		{
			p2--;
			tmp = value[pivot];
			value[pivot] = value[p2];
			value[p2] = tmp;
			t3 = p2;
		}
		high = p2 -1;
		p2 = high;
		p1 = low + 1;

		/*
		cout<<"crashes in rigth child"<<endl;
		display();
		low = p2 +1;
		p1 = low +1;;
		p2 = high;
		pivot = low;
		sort(p1,p2,pivot,high,low);*/
	}
	return sort(p1,p2,pivot,high,low);

}
void display()
{
	for(int loop = 0; loop < size; loop++)
	{
		cout<<value[loop]<<" ";
	}
	cout<<endl;
}
