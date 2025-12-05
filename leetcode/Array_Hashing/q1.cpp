#include <iostream>
#include <vector>
#include <unordered_set>

bool containsDuplicate(std::vector<int>& nums) {
	std::unordered_set<int> uniqueSet;
	for (const int num : nums)
	{
		if (uniqueSet.find(num) != uniqueSet.end())
			return true;
		else
			uniqueSet.insert(num);
	}
	return false;
}

int main() {
	std::vector<int> test = { 1,1,1,3,3,4,3,2,4,2 };
	std::vector<int> uni = { 1,2,3,4 };
	std::cout << containsDuplicate(test) << std::endl;
	std::cout << containsDuplicate(uni) << std::endl;

	return 0;
}


