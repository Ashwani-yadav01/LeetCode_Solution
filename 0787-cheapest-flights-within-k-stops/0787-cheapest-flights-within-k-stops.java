class Solution {

    public int findCheapestPrice(int n, int[][] flights, int src, int dst, int k) {

        ArrayList<ArrayList<int[]>> adj = new ArrayList<>();

        for(int i = 0; i < n; i++)
            adj.add(new ArrayList<>());

        for(int[] f : flights){
            adj.get(f[0]).add(new int[]{f[1], f[2]});
        }

        Queue<int[]> q = new LinkedList<>();
        q.offer(new int[]{src, 0});

        int[] dist = new int[n];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[src] = 0;

        int level = 0;

        while(!q.isEmpty() && level <= k){

            int size = q.size();

            for(int i = 0; i < size; i++){

                int[] curr = q.poll();
                int node = curr[0];
                int cost = curr[1];

                for(int[] nbr : adj.get(node)){

                    int next = nbr[0];
                    int price = nbr[1];

                    if(cost + price < dist[next]){
                        dist[next] = cost + price;
                        q.offer(new int[]{next, dist[next]});
                    }
                }
            }

            level++;
        }

        return dist[dst] == Integer.MAX_VALUE ? -1 : dist[dst];
    }
}