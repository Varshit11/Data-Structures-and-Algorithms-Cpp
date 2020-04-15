/* C++ program to solve the celebrity problem. uppose there are N people.
A person is called as celebrity if rest of the people know him but the 
person himself doesn't know anyone. The input will be an adjacency matrix
where mat[i][j] will be 1 if person i, knows j, else 0. The diagonal
elements are 0. */
#include <iostream>
using namespace std;
#define MAX 20
#define N 10

int stack[20];
int top=-1;
int mat[N][N]={{0,0,0,0,1},
			   {0,0,0,0,1},
			   {0,0,0,0,1},
		       {0,0,0,0,1},
		       {0,0,0,0,0}};


int isEmpty()
{
	return ((top) == -1);
}

void push(int data)
{
	if(top==MAX){
		cout<<"Stack overflow"<<endl;
		return;
	}
	stack[++top] = data;
}


int pop()
{
	if(isEmpty()){
		cout<<"Stack empty"<<endl;
		return -1;
	}
	else{
		int value = stack[top--];
		return value;
	}
}

int size()
{
	return top+1;
}

int findCeleb(int n)
{
	int celeb;
	// push everybody to stack
	for(int i; i<n; i++)
		push(i);
	
	// get top2 elements
	int temp1 = pop();
	int temp2 = pop();

	//Find potential celebrity
	while(size()>1)
	{
		if(mat[temp1][temp2])
			temp1 = pop();
		else
			temp2 = pop();
	}
	
	celeb = pop();

	if(mat[celeb][temp2])
		celeb=temp2;
	if(mat[celeb][temp1])
		celeb=temp1;

	// Check if Celeb is actually a celebrity or not
	for (int i = 0; i < n; i++) 
    {  
        if ((i != celeb) && (mat[celeb][i] || !mat[i][celeb])) 
            return -1; 
    } 
    return celeb;
}

int main()
{
	int n = 5;
	int value = findCeleb(n);
	if(value>0)
		cout<<"The celebrity is person "<<value<<endl;
	else{
		cout<<"There are no celebrity"<<endl;
	}
	return 0;
}
