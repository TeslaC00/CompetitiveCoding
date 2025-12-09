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
	void reorderList(ListNode* head) {
		int count = 0;

		ListNode* current = head;
		while (current != nullptr)
		{
			count++;
			current = current->next;
		}

		if (count < 3) return;

		count = count / 2;
		ListNode* prev = nullptr;
		ListNode* midNode = head;

		while (count--)
		{
			prev = midNode;
			midNode = midNode->next;
		}

		prev->next = nullptr;

		midNode = reverseList(midNode);

		mergeTwoLists(head, midNode);
	}

	ListNode* reverseList(ListNode* head) {
		ListNode* prev = nullptr;
		ListNode* curr = head;

		while (curr != nullptr)
		{
			ListNode* next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}

		return prev;
	}

	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		ListNode head;
		ListNode* current = &head;

		while (list1 != nullptr && list2 != nullptr)
		{
			current->next = list1;
			list1 = list1->next;
			current = current->next;

			current->next = list2;
			list2 = list2->next;
			current = current->next;
		}

		current->next = (list1 != nullptr) ? list1 : list2;

		return head.next;
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
	//std::vector<int> input1 = { 1,2,3,4 };
	std::vector<int> input1 = { 1,2,3,4,5 };
	//std::vector<int> input1 = { 1,2 };
	ListNode* head1 = createList(input1);
	printList(head1);

	Solution sol;
	sol.reorderList(head1);
	printList(head1);

	int in;
	std::cin >> in;

	return 0;
}