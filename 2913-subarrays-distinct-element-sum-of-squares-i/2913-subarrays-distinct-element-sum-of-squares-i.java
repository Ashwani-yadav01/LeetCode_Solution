class Solution {
    public int sumCounts(List<Integer> list) {

        int n = list.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            Set<Integer> set = new HashSet<>();
            for (int j = i; j < n; j++) {
                set.add(list.get(j));
                res += (set.size() * set.size());
            }
        }

        return res;
    }
}