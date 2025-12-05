#include<vector>
#include<iostream>

int canFinishThisHour(std::vector<int>& piles, int k, int h)
{
	unsigned int totalTime = 0;
	for (const int pile : piles)
		totalTime += ceil(pile / (double)k);
	return totalTime <= h;
}

int minEatingSpeed(std::vector<int>& piles, int h)
{
	int start = 1, end = *std::max_element(piles.begin(), piles.end());
	int k = (end + start) >> 1, ans = 0;
	while (start <= end)
	{
		if (canFinishThisHour(piles, k, h)) {
			ans = k;
			end = k - 1;
		}
		else
			start = k + 1;
		k = (end + start) >> 1;
	}
	return ans;
}

int main() {
	std::vector<int> input1 = { 30,11,23,4,20 };
	std::vector<int> input2 = { 1000000000 };
	std::cout << minEatingSpeed(input1, 5) << std::endl;
	std::cout << minEatingSpeed(input2, 2) << std::endl;
}