//这题的求pascal只让输出某一行，空间自然也只能用线性的
//因为只有一行数组，再用一行推下一行会出现覆盖问题，所以要从后往前算 
class Solution {
public:
    vector<int> getRow(int rowIndex) {
    	//初始化返回数组 
		vector<int> vals;
		//要算的是下一行的，初始化要多一个元素位子 
 		vals.resize(rowIndex+1,1);
 		//遍历需要算的行的所有元素，前两行都是1不用算
		for(int i=3;i<=rowIndex+1;i++){
			//遍历需要算的列，开头和结尾都是1不用算，要倒着算，覆盖下次要用的后一个元素
			for(int j=i-1;j>=2;j--){
				//给的是行列号，作为下标要-1
				vals[j-1]=vals[j-1]+vals[j-2];
			}
		}
		//返回 
		return vals;
    }
};
