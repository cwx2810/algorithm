#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits>
using namespace std;

int main(){

}

//判断一个链表是否存在环，给出环的开始节点 
//设置双指针，一个每次走两步，一个每次走一步，如果追上了，显然存在环 
//那么如何得到环的开始节点？画个图可以看出来，环的开始节点一定在起点和重合点的中间 
ListNode *detectCycle(ListNode *head) {
    //corner case 给定链表为空
	//初始化快慢指针
	//只要快指针没有追上慢指针就说明可能有环，一直迭代
	//移动快慢指针
	//如果追上了，则有环，环的开始节点在中间，所以把慢指针移回去还是构成双指针往中间走 
	//设置慢指针为初始节点
	//只要快慢没有碰头，就一直移动
	//碰头了，返回慢指针或快指针 
	//迭代完了都没有追上，则没有环 
}
