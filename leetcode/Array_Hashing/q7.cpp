#include<vector>
#include<iostream>

/*
* Example 1:
Input: nums = [1,2,3,4]
Output: [24,12,8,6]

Example 2:
Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
*/
std::vector<int> productExceptSelf(std::vector<int>& nums) {
	std::vector<int> products(nums.size());
	int totalProduct = 1;
	products[0] = 1;
	for (size_t i = 0; i < nums.size() - 1; i++) {
		totalProduct *= nums[i];
		products[i + 1] = totalProduct;
	}
	totalProduct = 1;
	for (size_t i = nums.size() - 1; i > 0; i--) {
		totalProduct *= nums[i];
		products[i - 1] *= totalProduct;
	}
	return products;
}

static void print(const std::vector<int>& vec) {
	for (int num : vec)
	{
		std::cout << num << ", ";
	}
	std::cout << std::endl;
}

int main() {
	std::vector<int> input1 = { 1,2,3,4 };
	std::vector<int> input2 = { -1,1,0,-3,3 };
	std::vector<int> input3 = { 0,0 };
	print(productExceptSelf(input1));
	print(productExceptSelf(input2));
	print(productExceptSelf(input3));
	std::cout << "" << std::endl;
}