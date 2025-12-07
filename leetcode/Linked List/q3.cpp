#include <iostream>
#include <vector>

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

bool hasCycle(ListNode* head) {
	if (head == nullptr || head->next == nullptr) return false;

	ListNode* slow = head;
	ListNode* fast = head->next;

	while (fast != nullptr && fast->next != nullptr)
	{
		if (slow == fast) return true;

		slow = slow->next;
		fast = fast->next->next;
	}

	return false;
}

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

void clearList(ListNode* head) {
	ListNode* current = head;

	while (current != nullptr)
	{
		ListNode* next = current->next;
		delete current;
		current = next;
	}
}

void loopToIndex(ListNode* head, int index) {
	ListNode* current = head;
	ListNode* loopBack = nullptr;
	int position = 0;

	while (current->next != nullptr)
	{
		if (position == index)
			loopBack = current;

		current = current->next;
		position++;
	}

	current->next = loopBack;
}

int main() {
	std::vector<int> input1 = { -21, 10, 17, 8, 4, 26, 5, 35, 33, -7, -16,
		27, -12, 6, 29, -12, 5, 9, 20, 14, 14, 2, 13, -24, 21, 23, -21, 5 };
	std::vector<int> input2 = { 3,2,0,-4 };

	ListNode* head1 = createList(input1);
	std::cout << hasCycle(head1) << std::endl;
	clearList(head1);

	ListNode* head2 = createList(input2);
	loopToIndex(head2, 1);
	std::cout << hasCycle(head2) << std::endl;
	clearList(head2);

	int n;
	std::cin >> n;

	return 0;
}