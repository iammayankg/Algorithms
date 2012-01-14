/* The following questions was asked to me during the "Global Scholar" recruitement process
 * 
 * Given a string of colors right a function which returns a result "success" if all sides of
 * the cube can be painted such that no two adjacent sides have the same color otherwise false
 * 
 * During the interview a proposed a long solution using graph theory with O(n2) and panicked during coding.
 * But a good night sleep worked and I woke up with a new O(n) solution.
 * If you find a better solution write back to me at mayank.gupta22@ymail.com
 */




#include <iostream>
#include <map>
#include <string>
using namespace std;
class cube
{
	private:
		int max_colors;					//Contains the maximum number of unique colors allowed
		int total_colors;				//Actual number of unique colors found in the string
		map < string, int> hm;			//hash map of count of each color
		string *unique_color;			//String containing unique colors found
		
	public:
		//Constructor for class cube
		cube(int num)
		{
			max_colors=num;
			total_colors=0;
			unique_color=new string[num];
		}
		//Builds a map from the string 
		void populate(string *col,int len)
		{
			for(int i=0;i<len;i++)
			{
				if(hm[col[i]])		//color already present 
				{
					hm[col[i]]+=1;
					}
				else              //color not present so add to unique_colors
				{
					hm[col[i]]=1;
					unique_color[total_colors++]=col[i];
				}
			}
		}
		//Here's the logic: If we need to paint the cube we either need 6 unique colors aur a minimum of 3 unique colors 
		//with a count of 2 so that we can paint all the six sides with the opposite sides painted with the same color
		void calculate()
		{
			int i=0;
			int count=0;
			if(total_colors>=6)			//we have 6 distinct colors to paint each side
			{
				 cout<<"Success";
				 return;
			 }
			else
			{
				while(i<=total_colors)
				{
					if(hm[unique_color[i]]>1) 
						count+=2; 									//If reference count is GT 2 each color can be used only twice 
					else 
						count+=1;									//to paint the opposite sides so we increase it by 2
																	//otherwise we can only use it once
					if(count>=6)									//We have enough colors to paint all the sides
					{
						cout<<"Success";
						return;
					}
					i++;
				}
			}
			cout<<"Able to paint only "<<count<<" sides";
			return;
		}
};
		

int main()
{
	string col[6]={"red","blue","green","green","black","blue"};
	cube *obj= new cube(6);
	obj->populate(col,5);
	obj->calculate();	
}

