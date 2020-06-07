/* C++ program to solve Employee importance problem
Problem Statement - https://leetcode.com/problems/employee-importance/
*/

#include<bits/stdc++.h>
using namespace std;

class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
    Employee(int x, int y, vector<int> z): id(x), importance(y), subordinates(z){}
};

void dfs(int id, map<int, pair<int, vector<int>>>& m, map<int, bool>& visited, int& ans){
    visited[id] = true;
    ans+= m[id].first;
    vector<int> adj_list = m[id].second;
    for(int i = 0; i<adj_list.size(); i++){
        int temp = adj_list[i];
        if(!visited[temp]) dfs(temp, m, visited, ans);
    }
}
    
int getImportance(vector<Employee*> employees, int id) {
    map<int, pair<int, vector<int>>> m;
    map<int, bool> visited;
    for(int i = 0; i<employees.size(); i++){
        m[employees[i]->id] = {employees[i]->importance, employees[i]->subordinates};
        visited[employees[i]->id] = false;
    }
    int ans = 0;
    dfs(id, m, visited, ans);
    return ans;
}

int main(){
	// code passed all test cases on leetcode, one test case is shown here for demonstration
	vector<Employee*> employees;
	vector<int> sub1 = {2,3};
	Employee* temp1 = new Employee(1,5, sub1);
	vector<int> sub2;
	Employee* temp2 = new Employee(2,3, sub2);
	vector<int> sub3;
	Employee* temp3 = new Employee(3,3,sub3);
	
	employees.push_back(temp1);
	employees.push_back(temp2);
	employees.push_back(temp3);
	
	cout<<"The total importance value of employee with id 1 is "<<getImportance(employees, 1)<<endl;
	return 0;
}

