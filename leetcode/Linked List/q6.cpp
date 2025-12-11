#include <iostream>
#include <vector>
#include <unordered_map>

class Node {
public:
	int val;
	Node* next;
	Node* random;

	Node(int _val) {
		val = _val;
		next = nullptr;
		random = nullptr;
	}
};


class Solution {
public:
	Node* copyRandomList(Node* head) {
		// 1-pass: Create new nodes in original
		// 2-pass: Assign random to new nodes
		// 3-pass: Assign next to new nodes and Detach

		Node* current = head;

		while (current != nullptr)
		{
			Node* newNode = new Node(current->val);
			newNode->next = current->next;
			current->next = newNode;
			current = newNode->next;
		}

		current = head;

		while (current != nullptr)
		{
			if (current->random != nullptr)
				current->next->random = current->random->next;

			current = current->next->next;	// current->next is always the copy
		}

		current = head;
		Node dummy(0);
		Node* newList = &dummy;

		while (current != nullptr)
		{
			newList->next = current->next;
			current->next = current->next->next;
			newList = newList->next;
			current = current->next;
		}

		return dummy.next;
	}
};


//ListNode* createList(std::vector<int>& nums) {
//	ListNode* head = new ListNode(nums[0]);
//	ListNode* current = head;
//
//	for (size_t i = 1; i < nums.size(); i++)
//	{
//		current->next = new ListNode(nums[i]);
//		current = current->next;
//	}
//
//	return head;
//}
//
//void printList(ListNode* head)
//{
//	ListNode* current = head;
//	while (current != nullptr)
//	{
//		std::cout << current->val << " ";
//		current = current->next;
//	}
//	std::cout << std::endl;
//}

int main()
{
	return 0;
}
