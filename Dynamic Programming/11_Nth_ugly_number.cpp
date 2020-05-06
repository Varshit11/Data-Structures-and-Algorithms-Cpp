/* C++ program to find Nth ugly number
*/

#include<iostream>
#include<vector>
using namespace std;

int Nth_ugly_number(int N){ // time O(N) and space O(N)
	vector<int> v;
	v.push_back(1);
	int p2 = 0, p3 = 0, p5 = 0;
	for(int i = 1; i<N; i++){
		// finding the mimimum of the values pointed by p2, p3, p5 multiplied by 2,3 and 5 respectively
		int next = min(v[p2]*2, v[p3]*3);
		next = min(next, v[p5]*5);
		v.push_back(next);
		if(v[p2]*2 == next) p2++;
		if(v[p3]*3 == next) p3++;
		if(v[p5]*5 == next) p5++;
	}
	return v[v.size()-1];
}

int main(){
	int N = 10;
	cout<<"The 10th ugly number is "<<Nth_ugly_number(N)<<endl;
	return 0;
}

