class Solution {
    public int maxDepth(String s) {
        int mx = Integer.MIN_VALUE;
        int count=0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') {
                count++;
            } else if (s.charAt(i) == ')') {
                count--;
            }
            mx = Math.max(count, mx);
        }
        return mx;
    }
}