#include<vector>
#include<iostream>

std::vector<int> twoSum(std::vector<int>& numbers, int target) {
	if (numbers.size() <= 2) return { 1,2 };

	int left = 0, right = numbers.size() - 1;
	while (left < right)
	{
		int diff = target - numbers[left];
		if (numbers[right] == diff) return { left + 1,right + 1 };
		else if (numbers[right] > diff) right--;
		else left++;
	}
	return {};
}

int main() {
	std::cout << "" << std::endl;
}