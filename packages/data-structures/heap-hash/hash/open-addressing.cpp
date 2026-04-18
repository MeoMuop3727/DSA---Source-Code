#include <bits/stdc++.h>
using namespace std;

enum State {
    EMPTY, // The element is not pushed to table (or being deleted)
    OCCUPIED, // The element was pushed to table
};
class OpenAddressing {
    private:
        int m; // The number of buckets
        int n = 0; // The number of keys

        vector<pair<int,State>> table; // {key, state}

        int hashFirst(int key) { return key % m; }
        int hashSecond(int key) { return 1 + key % (m - 1); }

        // ==================
        // PROBING STRATEGIES
        // ==================

        // Use when wanting load factor < 0.5 
        int linear(int key, int i) { return (hashFirst(key) + i) % m; }
        // Use when wanting the performance higher than linear
        int quadratic(int key, int i) { return (hashFirst(key) + i + (i * i)) % m; }
        // Use when wanting the load factor > 0.7 - 0.8
        int doubleHash(int key, int i) { return (hashFirst(key) + i * hashSecond(key)) % m; }

        void rehash() {
            auto old_table = table;
            table.clear();

            m *= 2;
            n = 0;

            table.resize(m);

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
            if ((n + 1.0) / m > 0.5) { rehash(); }

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

        /**
         * @brief Search a key in table
         * @param target The key 
         */
        int search(int target) {
            int i = 0;

            while (i < m) {
                int index = linear(target, i);

                if (table[index].second == OCCUPIED
                    && table[index].first == target) return index;
                
                i++;
            }

            return -1;
        }

        /**
         * @brief Delete a key in table
         * @param target The key 
         */
        bool remove(int target) {
            int i = 0;

            while (i < m) {
                int index = linear(target, i);

                if (table[index].second == OCCUPIED
                    && table[index].first == target) {
                        table[index].second = EMPTY;
                        return true;
                    }
            }

            return false;
        }
};

int main() {
    vector<int> nums = {0,1,2,3,4,5,6,7,8,9};
    OpenAddressing oa(nums);

    return 0;
}