//����һ���������һ����������+1���ֵ��ע���λ���� 
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
    	//��ʼ��ÿ����һλ֮�� 
		int sum=0;
		//��ʼ��ÿ�μӵ�������ʼ��1 
		int one=1;
		//�Ӹ����������һλ��ʼ�� 
		for(int i=digits.size()-1;i>=0;i--){
			//����ÿλ����ʵ�� 
			sum=one+digits[i];
			//��ȡ��õ�ÿλ���� 
			digits[i]=sum%10;
			//�õ���λ 
			one=sum/10;
		}
		//�ӵ���ǰ�滹�н�λ���Ͳ��뵽������ǰ�� 
		if(one>0){
			digits.insert(digits.begin(),one);
		}
		//�������õ������������� 
		return digits;
    }
};
