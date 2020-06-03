/* C++ program to solve micro and maze problem 
Problem Statement - https://www.hackerearth.com/practice/algorithms/graphs/flood-fill-algorithm/tutorial/
The problem is at the last of this tutorial
*/

#include<bits/stdc++.h>
using namespace std;

bool path_exists(vector<vector<int>> &maze, vector<vector<bool>> &visited, int row, int col){
    if(row == maze.size()-1 && col == maze[0].size()-1) return true;
    if(row>=maze.size() || col>=maze[0].size() || row<0 || col < 0) return false;
    if(maze[row][col] == 0) return false;
    if(visited[row][col]) return false;
    visited[row][col] = true;
    if(path_exists(maze, visited, row+1, col)) return true;
    if(path_exists(maze, visited, row-1, col)) return true;
    if(path_exists(maze, visited, row, col+1)) return true;
    if(path_exists(maze, visited, row, col-1)) return true;
    return false;
}


int main(){
    int M, N;
    cin>>N>>M;
    vector<vector<int>> maze(N, vector<int>(M,0));
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            cin>>maze[i][j];
        }
    }
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    if(path_exists(maze, visited, 0, 0)) cout<<"Yes";
    else cout<<"No";
    return 0;
}

