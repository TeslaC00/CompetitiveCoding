#include<iostream>
#include<vector>

int maxProfit(std::vector<int>& prices) {
	if (prices.size() == 1) return 0;

	int min = prices[0], max = 0;
	for (size_t i = 0; i < prices.size(); i++)
	{
		min = std::min(min, prices[i]);
		max = std::max(max, prices[i] - min);
	}
	return max;
}

int main() {
	std::vector<int> input1 = { 7,1,5,3,6,4 };
	std::vector<int> input2 = { 7,6,4,3,1 };
	std::cout << maxProfit(input1) << std::endl;
	std::cout << maxProfit(input2) << std::endl;
}