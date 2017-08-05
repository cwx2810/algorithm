#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

vector<vector<int> > threeSum(vector<int>& nums);

int main(){
	int a[]={-1,0,1,2,-1,-4};
    vector<int> A(a,a+6);
	vector<vector<int> > ret=threeSum(A);
	for(int i=0;i<ret.size();i++){
		for(int j=0;j<ret[i].size();j++){
			cout<<ret[i][j]<<" ";
		}
		cout<<endl;
	}
}



//�������飬�ҳ��������������Ϊ0�������� 
//�ؼ�������ظ����жϣ���������ÿ��Ԫ�صı���ȷ���Ƕ����ġ�����ѭ���ģ���Ӱ����������Ԫ��
//����Ԫ���ڲ������ظ���Ҫ++��������Ȼ��������һ�������飬��Ԫ��֮������ظ� 
vector<vector<int> > threeSum(vector<int>& nums) {
	//��ʼ���������� 
    vector<vector<int> > ret;
    //corner case ��������ֻ������Ԫ���Ǵղ��������� 
    if(nums.size()<=2){
    	return ret;
	}
	sort(nums.begin(),nums.end());//��������ĿҪ������ 
	for(int i=0;i<nums.size();i++){
	    int j=i+1;
	    int k=nums.size()-1;
		while(j<k){
		    vector<int> tmp;//��������vector�е�vector 
			if(nums[i]+nums[j]+nums[k]==0){//����������ѹջ 
				tmp.push_back(nums[i]);
				tmp.push_back(nums[j]);
				tmp.push_back(nums[k]);
				ret.push_back(tmp);
				j++;//ѹ��ջ�α��ƶ� 
				k--;
				while(nums[j]==nums[j-1]){//�ƶ����Ԫ�ص����ƶ�ǰ�ģ�˵�����λ���ڲ�ѭ�����ظ���Ҫ���� 
					j++;
				}
				while(nums[k]==nums[k+1]){//ͬ�� 
					k--;
				}
			}else if(nums[i]+nums[j]+nums[k]<0){//�Ѿ��Ź����ˣ����С��0˵��С��̫С�� 
				j++;
			}else{//ͬ�����̫���� 
				k--;
			}
		}
		while(nums[i]==nums[i+1]){//��һ��λ��Ҳ�����ظ� 
			i++;
		}
	}
	return ret;
}


