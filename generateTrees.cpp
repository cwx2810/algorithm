#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits>
using namespace std;

int main(){

}

//���������n��ʾ�ڵ�����������ж��������з�ʽ
//����һ�������з�ʽ������ͬ����һ��ֱ�������з�ʽ������˼·һ����ֻ����Ҫ��һ��������������ݹ鷵��֮���� 
 

vector<TreeNode*> generateTrees(int n) {
	//corner case û�нڵ㣬����Ҫ��һ���߽�������������ӣ���������ݹ�ͻ᷵��һ��[[]]�����еĿգ�����ͨ�������ԣ�Ӧ�÷���[]
	//��Ҳ�����ڽ��ⱨ�����׶ȷ��ִ��� 
	vector<TreeNode*> ret; 
	if(n==0) return ret; 
    //���غ��������뿪ʼ�ڵ�ͽ�β�ڵ� 
    return generate(1,n);
}
//�������غ���
vector<TreeNode*> generate(int start,int stop){
	//��ʼ������
	vector<TreeNode*> vs;
	//corner case ��ʼ�Ƚ�β��˵��û��������ѹ��գ����ؿ�ջ
	if(start>stop){
		vs.push_back(NULL);
		return vs;
	}
	
	//������������
	for(int i=start;i<=stop;i++){
		//�ݹ鹹�������� 
		auto left=generate(start,i-1);
		//�ݹ鹹��������
		auto right=generate(i+1,stop);
		//˫ѭ����������������Ҫ������ѹջ������
		for(int j=0;j<left.size();j++){
			for(int k=0;k<right.size();k++){
				//new���ڵ�
				TreeNode* root=new TreeNode(i);
				//����������
				root->left=left[j];
				//����������
				root->right=right[k];
				//���ڵ�ѹջ
				vs.push_back(root);
			}
		}
	}
	//����ջ	
	return vs;
}
 
