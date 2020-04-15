/* C++ program to implement Celebrity problem. Suppose there are N people.
A person is called as celebrity if rest of the people know him but the 
person himself doesn't know anyone. The input will be an adjacency matrix
where mat[i][j] will be 1 if person i, knows j, else 0. The diagonal
elements are 0. */

#include<iostream>
using namespace std;

int find_celebrity(int** mat, int N){
	int i, celeb=0, flag=0;
	for(i=0; i<N; i++){
		if(mat[celeb][i] == 1)
			celeb = i;
	}
	for(i=0;i<N;i++){
		if(i!=celeb && mat[celeb][i] == 1 && mat[i][celeb]!= 1){
			flag = 1;
			break;
		}
	}
	if(flag == 0)
		return celeb;
	else
		return -1;
}

int main(){
	int N, i, j;
	cout<<"Enter the number of people"<<endl;
	cin>>N;
	int** mat = new int*[N];
	for(i=0;i<N;i++){
		mat[i] = new int[N];
	}
	cout<<"Enter the adjacency matrix of people"<<endl;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			cin>>mat[i][j];
		}
	}
	
	int celeb = find_celebrity(mat, N);
	celeb!=-1?cout<<"The celebrity is "<<celeb<<endl : cout<<"There is no celebrity"<<endl;
	
	return 0;
}
