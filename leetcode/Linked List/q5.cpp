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

		ListNode dummy(0, head);
		ListNode* prev = &dummy;

		while (n--) head = head->next;

		while (head != nullptr)
		{
			head = head->next;
			prev = prev->next;
		}

		ListNode* next = prev->next;
		prev->next = prev->next->next;
		delete next;

		return dummy.next;
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
	//std::vector<int> input1 = { 1 };
	std::vector<int> input1 = { 1,2 };
	ListNode* head1 = createList(input1);
	printList(head1);

	Solution sol;
	head1 = sol.removeNthFromEnd(head1, 1);
	printList(head1);

	int in;
	std::cin >> in;

	return 0;
}