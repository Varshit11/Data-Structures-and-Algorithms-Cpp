/* C++ program to sort a nearly sorted array, 
Problem statement  - https://www.geeksforgeeks.org/find-k-numbers-occurrences-given-array/
*/

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

void sort_nearly_sorted(vector<int>& nums, int K){
	int i, index = 0;
	priority_queue <int, vector<int>, greater<int>> p;
	for(i = 0; i<K; i++)
		p.push(nums[i]);
	for(i = K; i< nums.size(); i++){
		if(nums[i] < p.top())
			nums[index++] = nums[i];
		else{
			nums[index++] = p.top();
			p.pop();
			p.push(nums[i]);
		}
	}
	while(!p.empty()){
		nums[index++] = p.top();
		p.pop();
	}
}

int main(){
	int N, K, num;
	cout<<"Enter the number of elements and the value of K"<<endl;
	cin>>N>>K;
	vector<int> nums;
	cout<<"Enter the elements to be sorted "<<endl;
	for(int i = 0; i<N; i++){
		cin>>num;
		nums.push_back(num);
	}
	sort_nearly_sorted(nums, K);
	cout<<"The sorted array is "<<endl;
	for(int i = 0; i<N; i++)
		cout<<nums.at(i)<<" ";
	return 0;
}

