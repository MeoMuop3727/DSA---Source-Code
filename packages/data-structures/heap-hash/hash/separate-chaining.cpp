#include <bits/stdc++.h>
using namespace std;

class SeparateChaining {
    private:
        int m; // The number of buckets
        int n = 0; // The number of elements inserted
        vector<vector<int>> table;

        int hash(int key) { return key % m; }

        void rehash() {
            // When the n is too large
            // We must create new table to store keys
            // And rehash will do it

            auto old_table = table;
            table.clear();

            m = m * 2;
            n = 0;

            table.resize(m);

            for (auto &bucket : old_table) 
                for (auto &key : bucket) 
                    insert(key);
        }
    public:
        SeparateChaining(const vector<int> &__nums) {
            m = (int)__nums.size() * 2;
            table.resize(m);
            for (const int &key : __nums) insert(key);
        }
        SeparateChaining(int __m) : m(__m) { table.resize(m * 2); }

        /**
         * @brief Insert a new key 
         * @param __key
         */
        void insert(int __key) {
            if ((n + 1.0) / m > 0.7) { rehash(); }
            
            table[hash(__key)].push_back(__key);
            n++;
        }

        /**
         * @brief Return iterator of __key
         * @param __key The target
         */
        vector<int>::iterator search(int __key) {
            int index = hash(__key);

            for (auto   it = table[index].begin();
                        it != table[index].end();
                        it++) 
                            if (*(it) == __key) return it;
            
            return table[index].end();
        }

        /**
         * @brief Return bool of __key
         * @param __key The target
         */
        bool remove(int __key) {
            int index = hash(__key);

            auto it = search(__key);

            if (it != table[index].end()) {
                table[index].erase(it);
                n--;
                return true;
            }
            else return false;
        }
};

int main() {
    vector<int> nums = {0,1,2,3,4,5,6,7,8,9};
    SeparateChaining sc(nums);

    return 0;
}