class Solution {

    int n, k;
    int[] nums;
    Node[] tree;

    class Node {
        int total;
        int[] pref;
        int[] suff;
        int[] ans;

        Node() {
            pref = new int[k];
            suff = new int[k];
            ans = new int[k];
        }
    }

    public int[] resultArray(int[] nums, int k, int[][] queries) {
        this.nums = nums;
        this.k = k;
        this.n = nums.length;

        tree = new Node[4 * n];

        build(1, 0, n - 1);

        int[] result = new int[queries.length];

        for (int i = 0; i < queries.length; i++) {
            int index = queries[i][0];
            int value = queries[i][1];
            int start = queries[i][2];
            int x = queries[i][3];

            nums[index] = value;

            update(1, 0, n - 1, index, value);

            Node res = query(1, 0, n - 1, start, n - 1);

            result[i] = res.pref[x];
        }

        return result;
    }

    void build(int node, int l, int r) {
        if (l == r) {
            tree[node] = makeNode(nums[l]);
            return;
        }

        int mid = (l + r) / 2;

        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    Node makeNode(int value) {
        Node res = new Node();

        int rem = value % k;

        res.total = rem;
        res.pref[rem] = 1;
        res.suff[rem] = 1;
        res.ans[rem] = 1;

        return res;
    }

    Node merge(Node left, Node right) {
        Node res = new Node();

        res.total = (left.total * right.total) % k;

        // Prefix
        for (int r = 0; r < k; r++) {
            res.pref[r] += left.pref[r];

            int nr = (left.total * r) % k;
            res.pref[nr] += right.pref[r];
        }

        // Suffix
        for (int r = 0; r < k; r++) {
            res.suff[r] += right.suff[r];

            int nr = (r * right.total) % k;
            res.suff[nr] += left.suff[r];
        }

        // Subarrays completely inside left/right
        for (int r = 0; r < k; r++) {
            res.ans[r] += left.ans[r];
            res.ans[r] += right.ans[r];
        }

        // Subarrays crossing left and right
        for (int a = 0; a < k; a++) {
            for (int b = 0; b < k; b++) {
                int nr = (a * b) % k;

                res.ans[nr] += left.suff[a] * right.pref[b];
            }
        }

        return res;
    }

    void update(int node, int l, int r, int index, int value) {
        if (l == r) {
            tree[node] = makeNode(value);
            return;
        }

        int mid = (l + r) / 2;

        if (index <= mid) {
            update(node * 2, l, mid, index, value);
        } else {
            update(node * 2 + 1, mid + 1, r, index, value);
        }

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    Node query(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            return tree[node];
        }

        int mid = (l + r) / 2;

        if (qr <= mid) {
            return query(node * 2, l, mid, ql, qr);
        }

        if (ql > mid) {
            return query(node * 2 + 1, mid + 1, r, ql, qr);
        }

        Node left = query(node * 2, l, mid, ql, qr);
        Node right = query(node * 2 + 1, mid + 1, r, ql, qr);

        return merge(left, right);
    }
}