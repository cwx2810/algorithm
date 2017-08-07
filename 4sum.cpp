#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

vector<vector<int> > fourSum(vector<int> &num, int target);

int main(){
	int a[]={-1,0,1,2,-1,-4};
    vector<int> A(a,a+6);
    int t=-6;
    vector<vector<int> > V=fourSum(A,t);
    for(int i=0;i<V.size();i++){
    	for(int j=0;j<V[i].size();j++){
    		cout<<V[i][j]<<" ";
		}
		cout<<endl;
	}
}


//4�����ĺ͵���target����3sumһëһ������һ��ѭ�� 
//���ѭ������jѭ�� 
vector<vector<int> > fourSum(vector<int> &num, int target) {
	//��ʼ���������� 
    vector<vector<int> > ret;
    //corner case �������鲻��4��Ԫ�� 
    if(num.size()<4){
    	return ret;
	}
	//������ 
	sort(num.begin(),num.end());
	for(int i=0;i<num.size();i++){//iѭ�� 
		for(int j=i+1;j<num.size();j++){//jѭ�� 
			int k=j+1;
			int l=num.size()-1;
			while(k<l){//k��lѭ�� 
				vector<int> tmp;//�洢��������� 
				if(num[i]+num[j]+num[k]+num[l]==target){//��������ѹջ 
					tmp.push_back(num[i]);
					tmp.push_back(num[j]);
					tmp.push_back(num[k]);
					tmp.push_back(num[l]);
					ret.push_back(tmp);
					k++;
					l--;
					while(num[k]==num[k-1]){//�ж�k��l�ڲ��ظ� 
						k++;
					}
					while(num[l]==num[l+1]){
						l--;
					}
				}else if(num[i]+num[j]+num[k]+num[l]<target){//�����������ƶ��α� 
					k++;
				}else{
					l--;
				}
			}
			while(num[j]==num[j+1]){//�ж�j�ڲ��ظ� 
				j++;
			}
		}
		while(num[i]==num[i+1]){//�ж�i�ڲ��ظ� 
			i++;
		}
	}
	return ret;
}


