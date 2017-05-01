class Solution {
public:
    vector<int> getRow(int rowIndex) {
		vector<int> vals;
 		vals.resize(rowIndex+1,1);//要算的是下一行的，初始化要多一行
		for(int i=3;i<=rowIndex+1;i++){//遍历需要算的行，前两行都是1不用算
			for(int j=i-1;j>=2;j--){//遍历需要算的列，开头和结尾不用算，要倒着算，覆盖下次要用的后一个元素
				vals[j-1]=vals[j-1]+vals[j-2];//给的是行列号，作为下标要-1
			}
		}
		return vals;
    }
};
