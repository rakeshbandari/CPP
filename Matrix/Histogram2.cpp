#include <bits/stdc++.h>
using namespace std;
 
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

int main()
{
    vector<int> matrix = {2, 1, 5, 6, 2, 3};
 
 	//vector<int> matrix = {3, 1, 3, 2, 2};
    
	cout << "Area of maximum rectangle is "
         << largestRectangleArea(matrix);
 
    return 0;
}
