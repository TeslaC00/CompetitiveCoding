#include<iostream>
#include<string>

int lengthOfLongestSubstring(std::string s) {
	int charIndex[128] = {};
	std::fill_n(charIndex, 128, -1);
	int left = 0, maxLength = 0;
	for (int right = 0; right < s.size(); right++) {
		char ch = s[right];
		if (charIndex[ch] >= left) {
			left = charIndex[ch] + 1;
		}
		charIndex[ch] = right;
		maxLength = std::max(maxLength, right - left + 1);
	}

	return maxLength;
}

int main() {
	std::cout << "" << std::endl;
}