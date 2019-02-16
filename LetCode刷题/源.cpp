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
	//ȥ��nums�ж�����ظ�Ԫ�ز�����ȥ���������ĳ���
	sort(nums.begin(), nums.end());
	nums.erase(unique(nums.begin(), nums.end()), nums.end());
	return nums.size();

	//ɾ��nums������ֵΪval��Ԫ��
	int len = 0;
	std::vector<int>::iterator j = nums.begin(), i = nums.begin();
	//˫ָ�뷨������Ҫ�ĵ�˼��
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
//ɾ��������ֵΪval�Ľ��
ListNode* removeElements(ListNode* head, int val) {
	//һ��Ҫ�ȿ�������ĵ�һ�����ֵ�Ƿ�Ϊval���������������һ�ݸ�����ֵ�򣬾ͻ����
	while (head != NULL && head->val == val) {
		ListNode *temp = head;
		head = head->next;   //��ͷ�ڵ����
		free(temp);
		temp = NULL;
	}
	//����Ϊ��ʱ����ִ������Ĳ��裬ֱ�ӷ���
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
//	/*����һ���������� nums ��һ��Ŀ��ֵ target�������ڸ��������ҳ���ΪĿ��ֵ���� ���� ������
//	���������ǵ������±ꡣ����Լ���ÿ������ֻ���Ӧһ���𰸡����ǣ��㲻���ظ������������
//	��ͬ����Ԫ�ء�*/
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
//�������� �ǿ� ������������ʾ�����Ǹ������������У����Ǹ��Ե�λ���ǰ��� ���� �ķ�ʽ�洢�ģ�
//�������ǵ�ÿ���ڵ�ֻ�ܴ洢 һλ ���֡���������ǽ��������������������᷵��һ���µ�����
//����ʾ���ǵĺ͡������Լ���������� 0 ֮�⣬���������������� 0 ��ͷ��
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
		cout << "���Ӻ�����������" << endl;
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
			cout << "��"<<i<<"��"<<*a << endl;
			
		}
		);
		t2.detach();
	}
	
	

	system("pause");
	return 0;
}
