#include <iostream>
#include <vector>

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
	int findDuplicate(std::vector<int>& nums) {
		// detect cycle
		int slow = nums[0], fast = nums[0];
		do
		{
			slow = nums[slow];
			fast = nums[nums[fast]];
		} while (slow != fast);

		// find cycle entry
		int left = nums[0], right = slow;
		while (left != right)
		{
			left = nums[left];
			right = nums[right];
		}

		return left;
	}
};

int main()
{
	std::vector<int> input1 = { 4,3,1,4,2 };
	std::vector<int> input2 = { 3,1,3,4,2 };
	std::vector<int> input3 = { 1,3,4,2,2 };
	Solution sol;
	std::cout << sol.findDuplicate(input1) << std::endl;
	std::cout << sol.findDuplicate(input2) << std::endl;
	std::cout << sol.findDuplicate(input3) << std::endl;
	int a;
	std::cin >> a;
	return 0;
}
