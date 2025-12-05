#include<iostream>
#include<string>

int characterReplacement(std::string s, int k) {
	if (s.size() == 1) return 1;
	int freq[26] = { 0 };
	int left = 0, maxFreq = 0, result = 0;
	for (int right = 0; right < s.size(); right++)
	{
		maxFreq = std::max(maxFreq, ++freq[s[right] - 'A']);
		if ((right - left + 1) - maxFreq > k)
		{
			--freq[s[left] - 'A'];
			left++;
		}
		result = std::max(result, right - left + 1);
	}
	return result;
}

int main() {
	std::cout << characterReplacement("ABAB", 2) << std::endl;
	std::cout << characterReplacement("AABABBA", 1) << std::endl;
}