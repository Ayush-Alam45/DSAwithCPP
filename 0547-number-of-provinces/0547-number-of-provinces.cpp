class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        vector<bool> vis(n, false);
        int count = 0;

        for (int i = 0; i < n; i++) {

            if (!vis[i]) {
                count++;

                queue<int> q;
                q.push(i);
                vis[i] = true;

                while (!q.empty()) {
                    int u = q.front();
                    q.pop();

                    for (int v = 0; v < n; v++) {

                        if (isConnected[u][v] == 1 && !vis[v]) {
                            vis[v] = true;
                            q.push(v);
                        }
                    }
                }
            }
        }

        return count;
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