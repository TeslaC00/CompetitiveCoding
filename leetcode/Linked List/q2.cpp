#include <iostream>

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
	ListNode head;
	ListNode* current = &head;

	while (list1 != nullptr && list2 != nullptr)
	{
		if (list1->val <= list2->val)
		{
			current->next = list1;
			list1 = list1->next;
		}
		else
		{
			current->next = list2;
			list2 = list2->next;
		}
		current = current->next;
	}

	current->next = (list1 != nullptr) ? list1 : list2;

	return head.next;
}

int main() {

	return 0;
}