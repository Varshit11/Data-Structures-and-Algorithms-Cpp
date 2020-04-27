/* C++ program to find inversion in an array. Given an array we need to find the count where
A[i] > A[j] when i<j */

#include<iostream>
#include<vector>
using namespace std;

int Merge_and_count(vector<int> &A, int low, int mid, int high){
	int i = low, j = mid+1, k = 0, count = 0;
	vector<int> temp;
	while(i<= mid && j<=high){
		if(A[i] > A[j]){
			count += mid-i+1;
			temp.push_back(A[j++]);
		}else{
			temp.push_back(A[i++]);
		}
	}
	while(i<=mid){
		temp.push_back(A[i++]);
	}
	while(j<=high){
		temp.push_back(A[j++]);
	}
	
	for(i=low;i<=high;i++){
		A[i] = temp[k++];
	}
	return count; 
}

int count_inversions(vector<int> &A, int low, int high){
	if(low>= high) return 0;
	int mid = low+(high-low)/2;
	int l = count_inversions(A, low, mid);
	int r = count_inversions(A, mid+1, high);
	int m = Merge_and_count(A, low, mid, high);
	return l+r+m;
}	

int main(){
	vector<int> A = {4,3,2,1};
	cout<<"The number of inversions in the vector are "<<count_inversions(A, 0, A.size()-1)<<endl;
	return 0;
}
