class Solution {
public:
    vector<long long> minTimeMaxPower(int n, vector<vector<int>>& edges, int power, vector<int>& cost, int source, int target) {

        if(source == target){
            return {0, (long long)power};
        }
        // build adj list
        vector<vector<pair<int, int>>> adj(n);
        for(const auto& e : edges){
            adj[e[0]].push_back({e[1],e[2]});
        }
        vector<vector<long long>> dist(n , vector<long long>(power+1, LLONG_MAX));

        priority_queue<tuple<long long, int, int>> pq;

        dist[source][power] = 0;
        pq.push({0,power, source});

        while(!pq.empty()){
            auto [neg_t, p, u] = pq.top();
            pq.pop();
            long long t = - neg_t;
            if(u == target){
                return {t, (long long)p};
            }

            if( t > dist[u][p]){
                continue;
            }

            if(p < cost[u]){
                continue;
            }
            int nxt_p = p - cost[u];

            for(const auto& edge : adj[u]){
                int v = edge.first;
                long long nxt_t = t + edge.second;

                if(nxt_t < dist[v][nxt_p]){
                    dist[v][nxt_p] = nxt_t;
                    pq.push({-nxt_t, nxt_p, v});
                }
            }
        }
        return {-1, -1};
    }
};