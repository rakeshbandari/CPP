/*
The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value and the median is the mean of the two middle values.

For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.

Implement the MedianFinder class:

MedianFinder() initializes the MedianFinder object.
void addNum(int num) adds the integer num from the data stream to the data structure.
double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.

*/
#include <bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>> pqmax;
priority_queue<int, vector<int>, greater<int>> pqmin;
MedianFinder() {
    
}

void addNum(int num) 
{
    if(pqmax.size()==pqmin.size())
	{
        if(pqmax.size()==0){
            pqmax.push(num);
            return;
        }
        if(num < pqmax.top())
            pqmax.push(num);
        else
            pqmin.push(num);
    }
    else
	{
        if(pqmax.size() > pqmin.size())
		{
            if(num >= pqmax.top())
			{
                pqmin.push(num);
            }
            else
			{
                int temp=pqmax.top();
                pqmax.pop();
                pqmin.push(temp);
                pqmax.push(num);
            }
        }
        if(pqmin.size() > pqmax.size())
		{
            if(num<=pqmin.top())
			{
                pqmax.push(num);
            }
            else
			{
                int temp=pqmin.top();
                pqmin.pop();
                pqmax.push(temp);
                pqmin.push(num);
            }
        }
    }
}

double findMedian() 
{
    if(pqmax.size()==pqmin.size())
        return ((pqmax.top()+pqmin.top())/2.0);

    else if(pqmax.size() > pqmin.size())
        return pqmax.top();

    return pqmin.top();
}


int main()
{
	double res;
	
    MedianFinder();
	addNum(1);
	addNum(2);
	
	res = findMedian();
	cout << res << endl;
	
	addNum(3);
	
	res = findMedian();
	cout << res << endl;
	
    return 0;
}
 


