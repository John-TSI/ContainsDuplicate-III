// https://leetcode.com/problems/contains-duplicate-iii/

#include<iostream>
#include"../inc/solution.hpp"

int main()
{
	//std::vector<int> vec{1,2,3,1};
	//std::cout << Solution().containsNearbyAlmostDuplicate(vec,3,0);  // true

	//std::vector<int> vec{1,0,1,1};
	//std::cout << Solution().containsNearbyAlmostDuplicate(vec,1,2);  // true

	std::vector<int> vec{1,5,9,1,5,9};
	std::cout << Solution().containsNearbyAlmostDuplicate(vec,2,3);  // false

	return 0;
}

