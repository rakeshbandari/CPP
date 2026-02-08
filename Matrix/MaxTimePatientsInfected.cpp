/*
Given a matrix arr[][], consisting of only 0, 1, and 2, that represents an empty ward, an uninfected patient, and an infected patient respectively. 
In one unit of time, an infected person at index (i, j) can infect an uninfected person adjacent to it i.e., at index (i – 1, j), (i + 1, j), (i, j – 1), and (i, j + 1). 
The task is to find the minimum amount of time required to infect all the patients. If it is impossible to infect all the patients, then print “-1”.
*/

#include <bits/stdc++.h>
using namespace std;
 
vector<pair<int, int> > direction = { { 1, 0 }, { 0, -1 }, { -1, 0 }, { 0, 1 } };
 
int maximumTime(vector<vector<int> > arr)
{
    // Stores the number of rows
    int n = arr.size();
 
    // Stores the number of columns
    int m = arr[0].size();
 
    // Stores the time of infection
    // of the patient at index (i, j)
    int timeofinfection[n][m];
 
    // Stores index and time of
    // infection of infected persions
    queue<pair<pair<int, int>, int> > q;
 
    // Traverse the matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
 
            // Set the cell as unvisited
            timeofinfection[i][j] = -1;
 
            // If the current patient
            // is already infected
            if (arr[i][j] == 2) {
 
                // Push the index and time of
                // infection of current patient
                q.push({ { i, j }, 0 });
                timeofinfection[i][j] = 0;
            }
        }
    }
 
    // Iterate until queue becomes empty
    while (!q.empty()) {
        // Stores the front element of queue
        pair<pair<int, int>, int> current
            = q.front();
 
        // Pop out the front element
        q.pop();
 
        // Check for all four
        // adjacent indices
        for (auto it : direction) {
 
            // Find the index of the
            // adjacent cell
            int i = current.first.first
                    + it.first;
            int j = current.first.second
                    + it.second;
 
            // If the current adjacent
            // cell is invalid or it
            // contains an infected patient
            if (i < 0 || j < 0 || i >= n
                || j >= m || arr[i][j] != 1
                || timeofinfection[i][j] != -1) {
 
                // Continue to the next
                // neighbouring cell
                continue;
            }
 
            // Push the infected
            // neighbour into queue
            q.push({ { i, j },
                     current.second + 1 });
            timeofinfection[i][j]
                = current.second + 1;
        }
    }
 
    // Stores the maximum time
    int maxi = INT_MIN;
 
    // Stores if any uninfected
    // patient exists or not
    int flag = 0;
 
    // Traverse the matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // If no patient is
            // present at index (i, j)
            if (arr[i][j] != 1)
                continue;
 
            // If an uninfected patient
            // is present at index (i, j)
            if (arr[i][j] == 1
                && timeofinfection[i][j] == -1) {
                // Set flag as true
                flag = 1;
                break;
            }
 
            // Update the maximum time of infection
            maxi = max(maxi, timeofinfection[i][j]);
        }
    }
 
    // If an ininfected patient is present
    if (flag)
        return -1;
 
    return maxi;
}
 
int main()
{
    vector<vector<int> > arr = { { 2, 1, 0, 2, 1 },
					             { 1, 0, 1, 2, 1 },
					             { 1, 0, 0, 2, 1 } };
    cout << maximumTime(arr);
 
    return 0;
}
