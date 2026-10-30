class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> adj(n);

        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }
        long long inf = 1e18;
        vector<vector<long long>> dist(n, vector<long long>(k + 1, inf));

        priority_queue<tuple<long long, int, int>,
                       vector<tuple<long long, int, int>>, greater<>>
            pq;

        dist[0][1]=0;
        pq.push({0,0,1});
        while(!pq.empty()){
         auto [d,u,count]=pq.top();
             pq.pop();

            if(d>dist[u][count]) continue;

            for(auto &[v,w]:adj[u]){
                int newCount=0;
                if(labels[v]==labels[u]){
                    newCount=count+1;
                }else{
                    newCount=1;
                }
                if(newCount>k){
                    continue;
                }
                long long nd=d+w;
                if(nd<dist[v][newCount]){
                    dist[v][newCount]=nd;
                    pq.push({nd,v,newCount});
                }
            }
        }
        long long ans=inf;

        for(int count=1;count<=k;count++){
            ans=min(ans,dist[n-1][count]);
        }
        return ans==inf?-1:ans;
    }
};