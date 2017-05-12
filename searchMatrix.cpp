#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

bool searchMatrix(vector<vector<int> > &matrix, int target);

int main(){
	int a[]={1,3,5,7};
	int b[]={10,11,16,20};
	int c[]={23,30,34,50};
	vector<int> A(a,a+4);
	vector<int> B(b,b+4);
	vector<int> C(c,c+4);
	vector<vector<int> > matrix;
	matrix.push_back(A);
	matrix.push_back(B);
	matrix.push_back(C);
	int target=10;
	cout<<searchMatrix(matrix,target);
}



//�жϾ�������û��Ԫ��ֵ���ڸ���ֵ 
//˼·���̶����Ͻ�Ԫ�أ���ʼ����row=0��col=��󣬲����������Ӽ��ж���û�� 
bool searchMatrix(vector<vector<int> > &matrix, int target){
	//corner case
	if(matrix.size()==0){
		return false;
	}
	if(matrix[0].size()==0){
		return false;
	}
	//��ʼ������λ��
	int row=0;
	int col=matrix[0].size()-1;
	//whileѭ���������½�Խ��
	while(row<matrix.size() && col>=0){
		if(matrix[row][col]<target){
			++row;
		}else if(matrix[row][col]>target){
			--col;
		}else{
			return true;
		}
	} 
	return false;
} 
