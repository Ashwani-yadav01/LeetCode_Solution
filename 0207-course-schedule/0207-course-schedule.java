class Solution {
    private ArrayList<ArrayList<Integer>> adj;

    public boolean detectCycle(int V) {

        int[] inDegree = new int[V];

        for (int i = 0; i < V; i++) {
            for (int neighbour : adj.get(i)) {
                inDegree[neighbour]++;
            }
        }

        Queue<Integer> queue = new LinkedList<>();

        for (int i = 0; i < V; i++) {
            if (inDegree[i] == 0) {
                queue.add(i);
            }
        }

        int count = 0;

        while (!queue.isEmpty()) {
            int node = queue.poll();
            count++;

            for (int neighbour : adj.get(node)) {
                inDegree[neighbour]--;

                if (inDegree[neighbour] == 0) {
                    queue.add(neighbour);
                }
            }
        }

        if (count != V) {
            return false;
        } else {
            return true;
        }
    }

    public boolean canFinish(int numCourses, int[][] prerequisites) {
        adj = new ArrayList<>();

        for (int i = 0; i < numCourses; i++) {
            adj.add(new ArrayList<>());
        }

        for (int[] val : prerequisites) {
            int u = val[1];
            int v = val[0]; 

            adj.get(u).add(v);
        }
        return detectCycle(numCourses);
    }
}