#include <string>
#include <unordered_map>
#include <vector>
#include <utility>
#include <iostream>

class TimeMap {
private:
	std::unordered_map<std::string, std::vector<std::pair<int, std::string>>> map;

public:
	TimeMap() {

	}

	void set(std::string key, std::string value, int timestamp) {
		map[key].push_back({ timestamp,value });
	}

	std::string get(std::string key, int timestamp) {
		std::unordered_map<std::string, std::vector<std::pair<int, std::string>>>::iterator it
			= map.find(key);
		// can use upper_bound to get strictly greater than timestamp to abstract the binary search

		if (it == map.end()) return "";

		std::vector<std::pair<int, std::string>>& timestamps = it->second;
		int right = timestamps.size() - 1;
		int left = 0;
		int answer = -1;

		while (left <= right)
		{
			int mid = left + (right - left) / 2;

			if (timestamps[mid].first <= timestamp)
			{
				answer = mid;
				left = mid + 1;
			}
			else
			{
				right = mid - 1;
			}
		}

		return (answer == -1) ? "" : timestamps[answer].second;
	}
};

int main() {
	TimeMap* obj = new TimeMap();
	obj->set("foo", "bar", 1);
	std::cout << obj->get("foo", 1) << std::endl;
	std::cout << obj->get("foo", 3) << std::endl;

	obj->set("foo", "bar2", 4);
	std::cout << obj->get("foo", 4) << std::endl;
	std::cout << obj->get("foo", 5) << std::endl;

	int in;
	std::cin >> in;
	delete obj;

	return 0;
}

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */