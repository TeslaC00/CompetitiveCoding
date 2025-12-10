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
	ListNode* removeNthFromEnd(ListNode* head, int n) {

		if (head == nullptr) return nullptr;

		int count = 0;
		ListNode* counter = head;

		while (counter != nullptr)
		{
			count++;
			counter = counter->next;
		}

		int index = count - n;
		ListNode* current = head;

		if (index == 0)
		{
			head = current->next;
			delete current;
			return head;
		}

		while (current != nullptr && --index > 0)
			current = current->next;

		if (current != nullptr && current->next != nullptr)
		{
			ListNode* next = current->next;
			current->next = current->next->next;
			delete next;
		}

		return head;
	}
};

ListNode* createList(std::vector<int>& nums) {
	ListNode* head = new ListNode(nums[0]);
	ListNode* current = head;

	for (size_t i = 1; i < nums.size(); i++)
	{
		current->next = new ListNode(nums[i]);
		current = current->next;
	}

	return head;
}

void printList(ListNode* head)
{
	ListNode* current = head;
	while (current != nullptr)
	{
		std::cout << current->val << " ";
		current = current->next;
	}
	std::cout << std::endl;
}

int main()
{
	std::vector<int> input1 = { 1 };
	//std::vector<int> input1 = { 1,2 };
	ListNode* head1 = createList(input1);
	printList(head1);

	Solution sol;
	head1 = sol.removeNthFromEnd(head1, 1);
	printList(head1);

	int in;
	std::cin >> in;

	return 0;
}