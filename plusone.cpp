//给定一个数组代表一个数，计算+1后的值，注意进位即可 
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
    	//初始化每计算一位之和 
		int sum=0;
		//初始化每次加的数，开始是1 
		int one=1;
		//从给定数的最后一位开始算 
		for(int i=digits.size()-1;i>=0;i--){
			//计算每位的真实和 
			sum=one+digits[i];
			//和取余得到每位数字 
			digits[i]=sum%10;
			//得到进位 
			one=sum/10;
		}
		//加到最前面还有进位，就插入到数组最前面 
		if(one>0){
			digits.insert(digits.begin(),one);
		}
		//返回最后得到的数组代表的数 
		return digits;
    }
};
