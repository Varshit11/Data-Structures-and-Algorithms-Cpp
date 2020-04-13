#include <iostream>
using namespace std;
 
void fun(string &s){
	s = "qwerty";
}
 
int main() {
	string s;
	fun(s);
	s.insert(0, "1");
	cout<<s<<endl;
	// cin>>s;
	return 0;
}
