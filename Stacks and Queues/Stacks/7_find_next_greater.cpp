/* C++ program to find the next greater element, for ex. if the array is 
15,12,16,2,1,0,7,8 then the output should be 16,16,-1,7,7,7,8,-1. Since there is
no element after 16 and 8 which is greater, so we will print -1.
Implement this using O(n) time. */

#include<bits/stdc++.h>
using namespace std;

// we will use C++ built in stack.
stack <int> s; // storing indexes of array in stack..

int* find_next_greater(int* arr, int n){
	int* final_ans = new int[n];
	for(int i = 0; i<n; i++){
		if(s.empty()){ // if stack is empty, just push the index in stack.
			s.push(i);
			continue;
		}
		while(!s.empty() && arr[i] > arr[s.top()]){
			// if the element is greater than the indexes of element in stack we will 
			//pop the indexes from stack till we find an index whos element is greater than the current index element..
			final_ans[s.top()] = arr[i];
			s.pop();
		}
		s.push(i); // now we will push the current element index..
	}
	// now there may be some elements who doesnt have next greater element, so they will be present in stack  till the end, so we will pop 
	// the indexes and store -1 at their indexes.
	while(!s.empty()){
		final_ans[s.top()] = -1;
		s.pop();
	}
	return final_ans;
}

int main(){
	int n,i;
	cout<<"Enter the number of elements in the array"<<endl;
	cin>>n;
	int* arr = new int[n];
	cout<<"Enter the elements"<<endl;
	for(i = 0; i<n; i++){
		cin>>arr[i];
	}
	int* final_ans = find_next_greater(arr, n);
	cout<<"The next greater elements array is"<<endl;
	for(i=0; i<n;i++){
		cout<<final_ans[i]<<" ";
	}
	
	return 0;
}

