//����˹�����ǣ���ҪҪ������������ά����Ĺ��ɣ�ÿ��Ԫ�غ��к���ȣ���һ�������һ��Ԫ�غ��к���ȣ��м��Ҳ�еݹ鹫ʽ 
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
    	//��ʼ��������˹�����ǵķ������� 
		vector<vector<int>> vals;
		//�������鳤�� 
		vals.resize(numRows);
		//ѭ���������飬���丳ֵ 
        for(int i=0;i<numRows;i++){
        	//��ʼ��ÿ��Ԫ�صĵڶ�ά����Ϊ�к�+1����Ϊ��k����k��Ԫ�أ���i�Ǵ�0��ʼ�ģ�����Ҫ+1 
			vals[i].resize(i+1);
			//ÿ�еĿ�ʼ�ͽ�βԪ������1 
			vals[i][0]=1;
			vals[i][vals[i].size()-1]=1;
			//����ÿ���м��Ԫ�أ���1��size-2 
			for(int j=1;j<vals[i].size()-1;j++){
				//���ƹ�ʽ�ǣ�����Ԫ��=��һ��ͬһλ�ӵ�Ԫ��+��һ��ǰһ��λ�ӵ�Ԫ�� 
				vals[i][j]=vals[i-1][j-1]+vals[i-1][j];
			}
		}
		//���� 
		return vals;
    }
};
