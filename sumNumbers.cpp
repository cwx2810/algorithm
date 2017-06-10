#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits>
using namespace std;

int main(){

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
}

//�Ѷ�����ÿ��·��������Ԫ��ת����һ�����֣��������·�����ֵĺ� 

int sumNumbers(TreeNode* root) {
        //��ʼ��ջ
        vector<int> arr;
    	//��ʼ��sum
    	int sum=0;
    	//����dfs��������ڵ㣬ջ��sum
    	DFS(root,arr,sum);
    	//����sum 
    	return sum;
    }
    //����ջԪ��תsum����
    int vec2sum(vector<int>& arr){
    	//��ʼ����ʱnum
    	int num=0;
    	//����ջ������Ԫ�أ�ÿ��sumʮ������һ��
    	for(auto n : arr) {
    		num=num*10+n;
    	}
    	//����������	
    	return num;
    }
//����dfs
void DFS(TreeNode* root,vector<int>& arr,int& sum){
	//corner case ���ڵ�Ϊ��
	if(root==nullptr){
		return;
	}
	//���ڵ�ѹջ
	arr.push_back(root->val);
	//����Ҷ�ӽڵ㣬������ת�����ּ���һ·�ϵ�sum
	if(root->left==nullptr && root->right==nullptr){
		sum+=vec2sum(arr);
	}else{
		//��֮û��Ҷ�ӽڵ㣬���������ݹ�dfs
		if(root->left!=nullptr){
			DFS(root->left,arr,sum);
		}
		if(root->right!=nullptr){
			DFS(root->right,arr,sum);
		}
	}
	//����ջ��
	arr.pop_back();
}
