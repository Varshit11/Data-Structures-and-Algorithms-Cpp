/* C++ program to find the number of ways to fill a N*4 wall with 1*4 bricks */

#include<iostream>
using namespace std;

int fill_wall(int N){
	if(N<4) return 1;
	return fill_wall(N-1) + fill_wall(N-4);
}

int fill_wall_bottom_up(int N){
	int temp[N+1];
	temp[0] = 1;
	temp[1] = 1;
	temp[2] = 1;
	temp[3] = 1;
	for(int i = 4; i<= N; i++) temp[i] = temp[i-1] + temp[i-4];
	return temp[N];
}

int main(){
	int N = 8;
	cout<<"Using recursion the number of ways to fill the wall is "<<fill_wall(N)<<endl;
	cout<<"Using bottom up DP the number of ways to fill the wall is "<<fill_wall_bottom_up(N)<<endl;
	return 0;
}

