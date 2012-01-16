/*This program finds the nth largest element in an
 unsorted array in nlogn time complexity. A small hack of quicksort */

#include <iostream>
using namespace std;
class findmax
{
	private:
		int *a;
		int max;
	public:
		findmax(int max)
		{
			this->max=max;
			a=new int[max];
		}
		void input()
		{
			for(int i=0;i<max;i++)
			{
				cin>>a[i];
			}
		}
		void output()
		{
			for(int i=0;i<max;i++)
			{
				cout<<a[i]<<endl;
			}
		}
		void findlargest(int k)
		{
			mq(0,max-1,k);
		}
		void mq(int low,int high,int k)
		{
			int i=low;
			int pivot=low;
			int j=high;
		//	if (pivot==k) cout<< a[pivot]; 
			if(high<low) return;
			
			while(i<j)
			{
				while(a[i]<a[pivot] && i<=high) i++;
				while(a[j] >a[pivot] && j>=low) j--;
				if(i<j)
				{
					int temp=a[i];
					a[i]=a[j];
					a[j]=temp;
				}
			}
			
			int temp=a[j];
			a[j]=a[pivot];
			a[pivot]=temp;
			pivot=j;
			if (pivot==k){ cout<<a[pivot]; return;}
			else if ( pivot > k) mq(low,pivot-1,k);
			else mq(pivot+1,high,k);
		}
};
int main()
{
	findmax *obj=new findmax(10);
	obj->input();
	obj->output();
	obj->findlargest(4);
	return 0;
}
