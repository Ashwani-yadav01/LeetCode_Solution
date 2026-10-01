class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        int n = nums.length;
        int i = 0, j = 0;

        List<Integer> res = new ArrayList<>();
        Deque<Integer> dq = new ArrayDeque<>();

        while (j < n) {

            // Remove smaller elements from the back
            while (!dq.isEmpty() && nums[dq.peekLast()] <= nums[j]) {
                dq.pollLast();
            }

            dq.addLast(j);

            if (j - i + 1 == k) {

                // Remove indices outside the window
                if (dq.peekFirst() < i) {
                    dq.pollFirst();
                }

                // Front contains index of maximum
                res.add(nums[dq.peekFirst()]);

                i++;
            }

            j++;
        }

        return res.stream()
                .mapToInt(Integer::intValue)
                .toArray();
    }
}