#include <bits/stdc++.h>
using namespace std;

enum State {
    EMPTY, // The element is not pushed to table
    OCCUPIED, // The element was pushed to table
    DELETED // The element was deleted to table
};

class OpenAddressing {
    private:
        int m; // The number of buckets
        int n; // The number of keys

        vector<pair<int,State>> table; // {key, state}

        int hashFirst(int key) { return key % m; }
        int hashSecond(int key) { return 1 + key % (m - 1); }

        // ==================
        // PROBING STRATEGIES
        // ==================

        int linear(int key, int i) { return (hashFirst(key) + i) % m; }
        int quadratic(int key, int i) { return (hashFirst(key) + i + (i * i)) % m; }
        int doubleHash(int key, int i) { return (hashFirst(key) + i * hashSecond(key)) % m; }

        void rehash() {
            auto old_table = table;
            table.clear();

            m *= 2;

            for (auto &[key, state] : old_table) insert(key);
        }
    public:
        OpenAddressing(int __m) : m(__m) { m *= 2; table.resize(m); }
        OpenAddressing(vector<int> &nums) {
            m = (int)nums.size() * 2;
            table.resize(m);
            for (auto &element : nums) insert(element);
        }

        /**
         * @brief Insert a key to table
         * @param element The key
         */
        void insert(int element) {
            if ((n + 1.0) / m > 0.7) { rehash(); }

            int i = 0;

            while (i < m) {
                int index = linear(element, i);

                while (table[index].second != OCCUPIED) {
                    table[index].second = OCCUPIED;
                    table[index].first = element;
                    n++;
                    return;
                }

                i++;
            }
        }

        int search(int target) {

        }
};

int main() {
    vector<int> nums = {0,1,2,3,4,5,6,7,8,9};
    OpenAddressing oa(nums);

    return 0;
}