#include "iostream"
#include "vector"

int search(std::vector<int>& nums, int target) {
	int left = 0, right = nums.size() - 1;

	while (left <= right)
	{
		int mid = left + (right - left) / 2;

		if (nums[mid] == target) return mid;
		if (nums[left] <= nums[mid])	// left sorted
		{
			if (target >= nums[left] && target < nums[mid])
				right = mid - 1;
			else
				left = mid + 1;
		}
		else
		{
			if (target > nums[mid] && target <= nums[right])
				left = mid + 1;
			else
				right = mid - 1;
		}
	}

	return -1;
}

int main() {
	std::vector<int> input1 = { 5,1,3 };
	std::cout << "Output 1:" << search(input1, 5) << std::endl;
	int a;
	std::cin >> a;

	return 0;
}