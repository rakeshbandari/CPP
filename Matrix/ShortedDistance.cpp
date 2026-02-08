/*

Shortest distance between two cells in a matrix or grid

s represents ‘source’ 
d represents ‘destination’ 
* represents cell you can travel 
0 represents cell you can not travel 

Input : {'0', '*', '0', 's'},
        {'*', '0', '*', '*'},
        {'0', '*', '*', '*'},
        {'d', '*', '*', '*'}
Output : 6

Input :  {'0', '*', '0', 's'},
         {'*', '0', '*', '*'},
         {'0', '*', '*', '*'},
         {'d', '0', '0', '0'}
Output :  -1

*/
#include <bits/stdc++.h>
using namespace std;
 
#define N 4
#define M 4
 
class QItem {
public:
    int row;
    int col;
    int dist;
    QItem(int x, int y, int w)
        : row(x), col(y), dist(w)
    {
    }
};
 
int minDistance(char grid[N][M])
{
    QItem source(0, 0, 0);
 
    // To keep track of visited QItems. Marking
    // blocked cells as visited.
    bool visited[N][M];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
        {
            if (grid[i][j] == '0')
                visited[i][j] = true;
            else
                visited[i][j] = false;
 
            // Finding source
            if (grid[i][j] == 's')
            {
               source.row = i;
               source.col = j;
            }
        }
    }
 
    // applying BFS on matrix cells starting from source
    queue<QItem> q;
    q.push(source);
    
    visited[source.row][source.col] = true;
    
    while (!q.empty()) {
        QItem cur = q.front();
        q.pop();
 
        // Destination found;
        if (grid[cur.row][cur.col] == 'd')
            return cur.dist;
 
        // moving up
        if (cur.row - 1 >= 0 && visited[cur.row - 1][cur.col] == false) {
            q.push(QItem(cur.row - 1, cur.col, cur.dist + 1));
            visited[cur.row - 1][cur.col] = true;
        }
 
        // moving down
        if (cur.row + 1 < N && visited[cur.row + 1][cur.col] == false) {
            q.push(QItem(cur.row + 1, cur.col, cur.dist + 1));
            visited[cur.row + 1][cur.col] = true;
        }
 
        // moving left
        if (cur.col - 1 >= 0 && visited[cur.row][cur.col - 1] == false) {
            q.push(QItem(cur.row, cur.col - 1, cur.dist + 1));
            visited[cur.row][cur.col - 1] = true;
        }
 
         // moving right
        if (cur.col + 1 < M && visited[cur.row][cur.col + 1] == false) {
            q.push(QItem(cur.row, cur.col + 1, cur.dist + 1));
            visited[cur.row][cur.col + 1] = true;
        }	
						        		
    }
    return -1;
}
 
// Driver code
int main()
{
    char grid[N][M] = { { '0', '*', '0', 's' },
                        { '*', '0', '*', '*' },
                        { '0', '*', '*', '*' },
                        { 'd', '*', '*', '*' } };
 
    cout << minDistance(grid);
    return 0;
}
