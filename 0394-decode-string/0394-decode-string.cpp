class Solution {
public:
    string decodeString(string s) {
        stack<int> counts;
        stack<string> strs;
        string curr;
        int num = 0;
        
        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } else if (c == '[') {
                counts.push(num);
                strs.push(curr);
                curr.clear();
                num = 0;
            } else if (c == ']') {
                int k = counts.top();
                counts.pop();
                
                string prev = strs.top();
                strs.pop();
                
                for (int i = 0; i < k; i++) {
                    prev += curr;
                }
                
                curr = prev;
            } else {
                curr += c;
            }
        }
        
        return curr;
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