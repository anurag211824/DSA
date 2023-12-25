// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) {
            return nums[0];
        }

        const int ARRAY_SIZE = 30001;
        int hash[ARRAY_SIZE] = {0};
        int m = ARRAY_SIZE;

        for (int i = 0; i < n; i++) {
            if (nums[i] < 0) {
                hash[(m - 1) + nums[i]]--;
            } else {
                hash[nums[i]]++;
            }
        }

        int result = 0;
        for (int i = 0; i < m; i++) {
            if (hash[i] == -1) {
                result = i - (m - 1);
            }
            if (hash[i] == 1) {
                result = i;
            }
        }

        return result;
    }
};


int main() {
Solution s1;
vector<int> v={-1,-1,-2};
int n=s1.singleNumber(v);
cout<<n;
    return 0;
}