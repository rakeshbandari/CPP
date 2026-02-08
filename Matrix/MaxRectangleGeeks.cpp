#include <bits/stdc++.h>
using namespace std;
 
#define R 4
#define C 4
 
void display(vector<vector<int>> &mat)
{
	cout << endl;
	for (int i = 0; i < mat.size(); i++) 
	{
		for (int j = 0; j < mat[i].size(); j++) 
		cout << mat[i][j] << " ";
		cout << endl; 
	}
	cout << endl << endl;
}

int largestRectangleArea(vector<int>& heights) 
{
   stack<int> st;
   int max_area = 0;  
   for (int i = 0 ; i < heights.size(); i++) 
   {
       while (!st.empty() && heights[st.top()] > heights[i]) 
	   {
           int topV = st.top();
           st.pop();
           int ahead = st.empty() ? 0 : st.top() + 1;
         
           int curr_area = (i - ahead) * heights[topV];
           max_area = curr_area > max_area ? curr_area : max_area;
       } 
       st.push(i);
   }
   while (!st.empty()) 
   {
       int topV = st.top();
       st.pop();
       int ahead = st.empty() ? 0 : st.top() + 1;
      
       int curr_area = (heights.size() - ahead) * heights[topV];
       max_area = curr_area > max_area ? curr_area : max_area;
   } 
   return max_area;   
}

int maxHist(vector<int> &row)
{
    stack<int> result;
 
    int top_val; // Top of stack
 
    int max_area = 0; // Initialize max area in current
 
    int area = 0; // Initialize area with current top
 
    int i = 0;
    while (i < row.size()) 
	{
        if (result.empty() || row[result.top()] <= row[i])
            result.push(i++);
 
        else {
            top_val = row[result.top()];
            result.pop();
            area = top_val * i;
 
            if (!result.empty())
                area = top_val * (i - result.top() - 1);
            max_area = max(area, max_area);
        }
    }
 
    while (!result.empty()) 
	{
        top_val = row[result.top()];
        result.pop();
        area = top_val * i;
        
        if (!result.empty())
            area = top_val * (i - result.top() - 1);
 
        max_area = max(area, max_area);
    }
    return max_area;
}

void modify(vector<vector<int>> &mat)
{	
	for (int i = 1; i < mat.size(); i++) 
	for (int j = 0; j < mat[i].size(); j++) 
	if(mat[i][j] == 1)
	{
		mat[i][j] += mat[i-1][j];
	}		
}
 
int maxRectangle(vector<vector<int>> &A)
{
	display(A);
	modify(A);
	display(A);
	
    int result = maxHist(A[0]); 
        
    for (int i = 1; i < A.size(); i++)
    {
    	cout <<  largestRectangleArea(A[i]) << endl;
    	result = max(result, largestRectangleArea(A[i]));
	}
    	 
    return result;
}
 
// Driver code
int main()
{
    vector<vector<int>> matrix = {{1,0,1,0,0},
								  {1,0,1,1,1},
								  {1,1,1,1,1},
								  {1,0,0,1,0}};
 
    cout << "Area of maximum rectangle is "
         << maxRectangle(matrix);
 
    return 0;
}
