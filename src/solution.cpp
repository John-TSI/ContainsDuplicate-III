#include<cmath>
#include"../inc/solution.hpp"


bool Solution::containsNearbyAlmostDuplicate(std::vector<int>& nums, int k, int t)
{
    auto left = nums.begin(), right = nums.begin() + k;  // iterators mark start/end of a sliding window of length k
    std::vector<int> window{left, right+1};  // using a separate vector, but could modify to be in-place instead
    std::sort(window.begin(), window.end());

    // values within window are sorted, iterate through and check pairwise differences
    // long conversion as difference between values can be > 32 bit INT_MAX
    for(int i{0}; i<k-1; ++i){ if(std::abs( (long) window[i] - window[i+1] ) <= t){ return true; } }

    // window doesn't contain an 'almost duplicate', so proceed to slide it along nums
    while(right != nums.end())
    {
        window.push_back(*(++right));  // insert value from new right end of window
        window.erase( std::find(window.begin(), window.end(), *left) );  // remove value that has fallen off left side of window
        ++left;

        std::sort(window.begin(), window.end());  // sort window after inserting new value
        auto newest = std::find(window.begin(), window.end(), *right);  // find position of inserted value

        // window is sorted, and we know that no almost duplicate exists; we only ever need to check the 
        // neighbours of the newly inserted value, as they are guaranteed to be closest in value
        if
        ( 
            ( newest != window.begin() && std::abs( (long) *newest - *(newest - 1) ) <= t ) ||
            ( newest != window.end()-1 && std::abs( (long) *newest - *(newest + 1) ) <= t )
        )   { return true; }
    }
    return false;
}