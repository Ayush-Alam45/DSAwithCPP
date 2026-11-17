class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double  answer=0;
        for(int right=0;right<k;right++){
            answer+=nums[right];
        }
         double maxsubarray=answer;
        for(int i=k ;i<nums.size();i++){
            answer=answer+nums[i]-nums[i-k];
            maxsubarray= max( maxsubarray,answer);

        }
         

         return maxsubarray/k; 
    }
};


#pragma GCC optimize("Ofast")

#include <iostream>

static constexpr std::size_t max_align = alignof(std::max_align_t);
alignas(max_align) static unsigned char BUFFER[64 * 1024 * 1024];
static std::size_t pos = 0;

void *operator new(const std::size_t size) {
    const std::size_t padding = (max_align - (pos % max_align)) % max_align;
    pos += padding + size;
    return static_cast<void *>(&BUFFER[pos - size]);
}

void *operator new[](const std::size_t size) {
    return operator new(size);
}

void operator delete(void *) noexcept {}

void operator delete[](void *) noexcept {}

void operator delete(void *, std::size_t) noexcept {}

void operator delete[](void *, std::size_t) noexcept {}