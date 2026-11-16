class Solution {
public:
    void merge(vector<int>& num1, int m, vector<int>& num2, int n) {
        int i=m-1;
    int j=n-1;
    int k=m+n-1;
    
    while(i>=0 && j>=0){
        if(num1[i]>num2[j]){
            num1[k]=num1[i];
            i--;
        }
        else{
             num1[k]=num2[j];
             j--;
        }
        k--;
    }
    while(j>=0){
        num1[k]=num2[j];
        j--;
        k--;
    } 
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