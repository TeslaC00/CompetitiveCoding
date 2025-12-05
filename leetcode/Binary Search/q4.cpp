#include<vector>
#include<iostream>

int findMin(std::vector<int>& nums) {
	int left = 0, right = nums.size() - 1;

	while (left < right) {
		int mid = left + (right - left) / 2;
		if (nums[mid] > nums[right]) left = mid + 1;
		else right = mid;
	}

	return nums[right];
}

int main() {
	std::vector<int> input1 = { 4,5,6,7,0,1,2 };
	std::vector<int> input2 = { 2,1 };
	std::vector<int> input3 = { 11,13,15,17 };
	std::cout << "Output 1: " << findMin(input1) << std::endl;
	std::cout << "Output 2: " << findMin(input2) << std::endl;
	std::cout << "Output 3: " << findMin(input3) << std::endl;
}
