/* C++ program for Sudoku
Problem Statement - https://www.geeksforgeeks.org/sudoku-backtracking-7/
*/

#include<iostream>
#include<vector>
using namespace std;

//bool check(vector<vector<int>> &mat, vector<vector<int>> &temp, int num, int row, int col, int main1, int main2){
//	int i,j;
//	for(i=0;i<9;i++) if(num == mat[3*main1+row][i]) return false;
//	for(i=0;i<9;i++) if(num == mat[i][3*main2+col]) return false;
//	for(i=0;i<3;i++) for(j=0;j<3;j++) if(temp[i][j] == num) return false;
//	return true;
//}
//
//bool fill_temp(vector<vector<int>> &mat, vector<vector<int>> &temp, int row, int col, int main1, int main2){
//	cout<<"Row is "<<row<<"col is "<<col<<endl;
//	if(col>=3){
//		col = 0;
//		row++;
//	}
//	if(row>=3) return true;
//	if(temp[row][col] == 0){
//		for(int i = 1; i<=9;i++){
//			if(check(mat, temp, i, row, col, main1, main2)) temp[row][col] = i;
//			if(fill_temp(mat, temp, row, col+1, main1, main2)) return true;
//			temp[row][col] = 0;
//		}
//	}else {
//		bool j = fill_temp(mat, temp, row, col+1, main1, main2);
//	}
//	return false;
//}
//
//void initialise_temp(vector<vector<int>> &mat, vector<vector<int>> &temp, int row, int col){
//	int h = 0, k = 0;
//	for(int i = 3*row; i<3*row+3; i++){
//		k = 0;
//		for(int j = 3*col; j<3*col+3; j++) {
//			temp[h][k] = mat[i][j];
//			++k;
//		}
//		h++;
//	}
//}
//
//void fill_mat(vector<vector<int>> &mat, vector<vector<int>> &temp, int row, int col){
//	for(int i = 0; i<3; i++) for(int j = 0; j<3; j++) mat[3*row+i][3*col+j] = temp[i][j];
//}
//
//void sudoko(vector<vector<int>> &mat){
//	vector<vector<int>> temp(3, vector<int>(3));
//	for(int i = 0; i<3; i++){
//		for(int j = 0; j<3; j++){
//			initialise_temp(mat, temp, i, j);
//			bool k = fill_temp(mat, temp, 0, 0, i, j);
//			fill_mat(mat, temp, i, j);
//		}
//	}
//}
// the above commented code is giving wrong result.
// Correct solution - 
bool check(vector<vector<int>> &mat, int row, int col, int num){
	int i, j;
	for(i=0; i<mat.size(); i++) if(mat[i][col] == num) return false; // checking column
	for(i=0; i<mat.size(); i++) if(mat[row][i] == num) return false; // checking row
	// checking box..
	row -= row%3;
	col -= col%3;
	for(i=0;i<3;i++) for(j=0;j<3;j++) if(mat[i+row][j+col] == num) return false;
	return true;
}

bool find_unassigned(vector<vector<int>> &mat, int &row, int &col){
	for(row = 0; row<mat.size(); row++){
		for(col = 0; col<mat.size(); col++){
			if(mat[row][col] == 0){
				return true;
			}
		}
	}
	return false;
}

bool sudoko(vector<vector<int>> &mat){
	int row, col;
	if(!find_unassigned(mat, row, col)) return true;
	for(int i = 1; i<=9; i++){
		if(check(mat, row, col, i)){
			mat[row][col] = i;
			if(sudoko(mat)) return true;
			mat[row][col] = 0;
		}
	}
	return false;
}

int main(){
	vector<vector<int>> mat = {{3,0,6,5,0,8,4,0,0},{5,2,0,0,0,0,0,0,0}, {0,8,7,0,0,0,0,3,1}, {0,0,3,0,1,0,0,8,0},
	{9,0,0,8,6,3,0,0,5}, {0,5,0,0,9,0,6,0,0}, {1,3,0,0,0,0,2,5,0}, {0,0,0,0,0,0,0,7,4}, {0,0,5,2,0,6,3,0,0}};
	
	if(!sudoko(mat)) cout<<"Sudoko not possible "<<endl;
	else{
		cout<<"The sudoko is "<<endl;
		for(int i = 0; i<9;i++){
			for(int j = 0; j<9;j++) cout<<mat[i][j]<<" ";
			cout<<endl;
		}
	}
	return 0;
}

