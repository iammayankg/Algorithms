/* The TRIE data structure */

#include <iostream>
#include <string>
using namespace std;
class trie{
	private:
	char number[11];
	int isvalid;
	trie *next[26];
	public:
	trie()
	{
		memset(number,0,11);
		isvalid=0;
		for(int i=0;i<26;i++) next[i]=NULL;
	}
int ind(char x){
	return x-'a';
	}	
 void add_element(char *index,char *data)
{
		int i;
		int x;
		x=ind(*index);
		//cout<<x;
			if(this->next[x]==NULL)
			{
				this->next[x]=new trie;
			//	cout<<"new trie";
			}
			if(*(index+1)==0)
			{
				this->isvalid=1;
		//		cout<<"is valid";
				strcpy(this->number,data);
			}
			else
			{
				this->next[x]->add_element(++index,data);
		}
				
}
void search_element(char *index)
	{
		int x;
		int len=strlen(index);
		trie *temp=this;
		for(int i=0;i<len;i++)
		{
			x=ind(index[i]);
		//	cout<<x;
		if(temp==NULL)
		{
			cout<<"Element not found";
			return;
		}
		else if(temp->isvalid==1 && i==len-1)
		{
			cout<<index<<":"<<temp->number<<endl;
			return;
		}
		else if(temp->isvalid==0 && i==len-1)
		{
			cout<<"Element does not exist";
			return;
		}
			temp=temp->next[x];
		
		}

	}
	
};



int main()
{
	trie *obj=new trie;
	obj->add_element("mayank","9791491710");
	obj->search_element("mayankkk");
	return 0;
}

