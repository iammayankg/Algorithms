/*Max subarray in O(n2) */

#include <iostream>
using namespace std;
class array
{
	private:
		int *a;
		int max;
	public:
		array(int max)
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
		void fsub()
		{
			int *b=new int[max];
			int temp=0;
			int low,high,largest=-100;
			for(int i=0;i<max;i++)
			{
				temp+=a[i];
				b[i]=temp;
			}
			
			for(int i=0;i<max;i++)
			{
				for(int j=i+1;j<max;j++)
				{
					if(b[j]-b[i] > largest)
					{
						largest=b[j]-b[i];
						low=i;
						high=j;
					}
				}
			}
			cout<<endl<<low<<"\t"<<high<<"\t"<<largest;
		}
};
int main()
{
	array* obj=new array(7);
	obj->input();
	obj->output();
	obj->fsub();
	return 0;
}
