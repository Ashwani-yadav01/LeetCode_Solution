
import java.math.BigInteger;

class Solution {
    public int maxLength(int[] nums) {
        int n = nums.length;
        int ans = 1;

        for (int i = 0; i < n; i++) {
            BigInteger prod = BigInteger.ONE;
            long g = 0;
            long l = 1;

            for (int j = i; j < n; j++) {
                prod = prod.multiply(BigInteger.valueOf(nums[j]));

                g = gcd(g, nums[j]);

                l = (l / gcd(l, nums[j])) * nums[j];

                BigInteger val = BigInteger.valueOf(g)
                        .multiply(BigInteger.valueOf(l));

                if (prod.equals(val)) {
                    ans = Math.max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }

    private long gcd(long a, long b) {
        while (b != 0) {
            long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
}
