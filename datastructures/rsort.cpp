/* Radix sort */

#include <iostream>
using namespace std;
class array
{
	private :
	int *a;
	int n;
	public:
	array (int n)
	{
		this->n=n;
		a=new int [n];
		if(a==NULL)
		{
			cout<<"stderr:MNA";
		}
	}
	void accept()
	{
		for(int i=0;i<n;i++)
		cin>>a[i];
	}
	void display()
	{
		for (int i=0;i<n;i++)
		cout<<a[i]<<"\t";
	}
	void rsort()
	{
		int bucket[10],exp,b[n];
		int max=-32767;
		exp=1;
		for(int i=0;i<10;i++)
		bucket[i]=0;
		for(int i=0;i<n;i++)
		if(a[i]>max)max=a[i];
		while(max/exp > 0)
		{
			for(int i=0;i<n;i++)
			++bucket[a[i]/exp%10];
			for(int i=1;i<10;i++)
			bucket[i]+=bucket[i-1];
			for(int i=n-1;i>=0;i--)
			b[--bucket[a[i]/exp%10]]=a[i];
			for(int i=0;i<n;i++)
			a[i]=b[i];
			exp*=10;
		}
	}
};
int main()
{
	array *obj=new array(8);
	obj->accept();
	obj->display();
	obj->rsort();
	obj->display();
	return 0;
}
		
