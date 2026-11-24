class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            long long prod = 1;
            long long GCD = nums[i];
            long long LCM = nums[i];

            for (int j = i; j < n; j++) {

                // Check product overflow
                if (nums[j] != 0 &&
                    prod > LLONG_MAX / nums[j]) {
                    break;
                }

                prod *= nums[j];

                GCD = gcd(GCD, (long long)nums[j]);

                // Calculate LCM safely
                long long g = gcd(LCM, (long long)nums[j]);

                if (LCM / g > LLONG_MAX / nums[j]) {
                    break;
                }

                LCM = (LCM / g) * nums[j];

                // Check multiplication overflow
                if (GCD != 0 && LCM > LLONG_MAX / GCD) {
                    break;
                }

                if (prod == GCD * LCM) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};