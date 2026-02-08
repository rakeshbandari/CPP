#include <bits/stdc++.h>
using namespace std;

void display(int h[]){
	cout << endl;
	for(int i=0;i < sizeof(h);i++)
	 cout << h[i] << " ";
} 

int largestRectangleArea(vector<int> &heights) {
	
	int left[heights.size()] = {0};
	int right[heights.size()] = {0};
	
	memset(left,0,sizeof(left));
	memset(right,0,sizeof(right));

	int n = heights.size();
	int max_area=INT_MIN;
	
	stack<int> s;
		
	for( int i=0;i<heights.size();i++)
	{
		if(s.empty())
		{
			left[i]=0;
			s.push(i);
		}
		else
		{
			while(!s.empty() && heights[s.top()] >= heights[i])
			s.pop();
			
			left[i]=s.empty() ? 0 : s.top()+1;
			
			s.push(i);
		}
	}
//display(left);

	cout << "Left :" <<endl;
	for(int i=0; i < 6; i++)
	cout << left[i] << " ";
	 
	while(!s.empty())
		s.pop();
		
	for( int i=heights.size()-1;i>=0;i--)
	{
		if(s.empty())
		{
			right[i]=heights.size()-1;
			s.push(i);
		}
		else
		{
			while(!s.empty() && heights[s.top()]>=heights[i])
			s.pop();
			right[i]=s.empty()?n-1:s.top()-1;
			s.push(i);
		}

    }
    cout << "\nRight :" <<endl;
    cout << endl;
	for(int i=0; i < 6; i++)
	cout << right[i] << " ";

    cout << "\n\nDiff :" <<endl;
    cout << endl;
	for(int i=0; i < 6; i++)
	cout << heights[i] << "*"<< right[i]-left[i]+1 << " ";
		
    for( int i=0;i<heights.size();i++)
	{
    	max_area = max( max_area, heights[i] * (right[i]-left[i] + 1) );
	}
        
    return max_area;
}
 
// Driver code
int main()
{
    vector<int> heights = {2,1,5,6,2,3};
 
    cout << "\nArea of maximum rectangle is "
         << largestRectangleArea(heights);
 
    return 0;
}
