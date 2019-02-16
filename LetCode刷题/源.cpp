#include<iostream>
#include<vector>
#include<algorithm>
#include <unordered_map>
#include <memory>
#include <thread>
//#include <sys>
using namespace std;


int climbStairs(int n) {

	/*if (n == 1)return 1;
	int sum[100] = { 0 };
	sum[0] = 0; sum[1] = 1; sum[2] = 2;
	for (int i = 3; i <= n; i++) {
		sum[i] = sum[i - 2] + sum[i - 1];
	}
	return sum[n];
*/
	int a[100] = { 0 };

	a[1] = 1;
	a[2] = 2;
	for (int i = 1; i <= n - 2; ++i)
	{
		a[i + 2] = a[i] + a[i + 1];
	}
	return a[n];
}
int minCostClimbingStairs(vector<int>& cost) {
	int n = cost.size();
	int j = 0;
	int *Sum = new int[n];
	Sum[0] = cost[0];
	Sum[1] = cost[1];
	for (int i = 2; i < n; ++i)
	{
		Sum[i] = cost[i] + (Sum[i - 1] > Sum[i - 2] ? Sum[i - 1] : Sum[i - 2]);
	}
	return (Sum[n - 1] < Sum[n - 2]) ? Sum[n - 1] : Sum[n - 2];
}
int min(int a, int b)
{
	if (a > b) return b;
	return a;
}
int removeDuplicates(vector<int>& nums, int val) {
	//去掉nums中多余的重复元素并返回去除后的数组的长度
	sort(nums.begin(), nums.end());
	nums.erase(unique(nums.begin(), nums.end()), nums.end());
	return nums.size();

	//删除nums中所有值为val的元素
	int len = 0;
	std::vector<int>::iterator j = nums.begin(), i = nums.begin();
	//双指针法，很重要的的思想
	for (; i < nums.end(); ++i)
		if (*i != val)
		{
			++len;
			*j = *i;
			++j;
		}
	nums.erase(j + 1, nums.end());
	return nums.size();
}

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}

};
//删除链表中值为val的结点
ListNode* removeElements(ListNode* head, int val) {
	//一定要先考虑链表的第一个结点值是否为val，若不考虑链表第一份个结点的值域，就会出错
	while (head != NULL && head->val == val) {
		ListNode *temp = head;
		head = head->next;   //将头节点后移
		free(temp);
		temp = NULL;
	}
	//链表为空时不再执行下面的步骤，直接返回
	if (head == NULL)
		return head;

	ListNode *p1 = NULL, *p2 = NULL;
	p1 = head;
	p2 = head->next;

	while (p2 != NULL)
	{
		if (p2->val != val)
		{
			p1 = p2;
		}
		else
		{

			p1->next = p2->next;
			free(p2);
			p2 = p1;
		}
		p2 = p2->next;
	}

	return head;
}



//class Solution {
//public:
//	/*给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，
//	并返回他们的数组下标。你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组
//	中同样的元素。*/
//	vector<int> twoSum(vector<int>& nums, int target) {
//		unordered_map<int, int> mapping;
//		vector<int> result;
//		for (int i = 0; i < nums.size(); i++) {
//			mapping[nums[i]] = i;
//		}
//		for (unsigned int i = 0; i < nums.size(); i++) {
//			const int gap = target - nums[i];
//			if (mapping.find(gap) != mapping.end() && mapping[gap] > i) {
//				result.push_back(i);
//				result.push_back(mapping[gap]);
//				break;
//			}
//		}
//		return result;
//	}
//};
//
///*
//给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，
//并且它们的每个节点只能存储 一位 数字。如果，我们将这两个数相加起来，则会返回一个新的链表
//来表示它们的和。您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
//*/
//class Solution2{
//public:
//	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
//	{
//		ListNode* start = NULL;
//		ListNode** ret = &start;
//		int carry = 0;
//		while (l1 != NULL || l2 != NULL)
//		{
//			int x1 = (l1 != NULL) ? l1->val : 0;
//			int x2 = (l2 != NULL) ? l2->val : 0;
//			int sum = x1 + x2 + carry;
//			carry = sum / 10;
//			ListNode* tmp = new ListNode(sum % 10);
//			(*ret)= tmp;
//			ret = &(tmp->next);
//			if (l1 != NULL) l1 = l1->next;
//			if (l2 != NULL) l2 = l2->next;
//		}
//
//		if (carry > 0) {
//			(*ret) = new ListNode(carry);
//		}
//		return start;
//	}
//};


class A
{
public:
	int a;
};
class parent 
{
public:
	void foo()
	{

	}
};

class son:public parent
{
public:
	void son_foo()
	{
		cout << "孩子函数的输出结果" << endl;
	}
protected:
private:
};


void function1(int i)
{
	cout << i << endl;
}


int main()
{
	
	///**auto a = function();*/
	//*cout << &a << endl; */
	//	cout << temp->use_count() << endl; */
	/*parent* point = new son();
	reinterpret_cast<son*>(point)->son_foo();*/
	for (int i = 0; i < 8; ++i)
	{
		int *a = new int(200);
		/*thread t(function1, i);*/
		thread t2(	[&a,&i]()->void
		{
			cout << "第"<<i<<"个"<<*a << endl;
			
		}
		);
		t2.detach();
	}
	
	

	system("pause");
	return 0;
}
