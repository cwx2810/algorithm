class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
		int sum=0;
		int one=1;
		for(int i=digits.size()-1;i>=0;--i){
			sum=one+digits[i];//计算
			digits[i]=sum%10;//本位
			one=sum/10;//进位
		}
		if(one>0){
			digits.insert(digits.begin(),one);
		}
		return digits;
    }
};
