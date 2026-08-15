class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        vector<vector<pair<int,int>>> adj(n);

        for (auto f : flights) {
            adj[f[0]].push_back({f[1], f[2]});
        }

        // {cost, {node, stops}}
        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > pq;

        // dist[node][stops]
        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));

        dist[src][0] = 0;

        pq.push({0, {src, 0}});

        while (!pq.empty()) {

            auto it = pq.top();
            pq.pop();

            int cost = it.first;
            int node = it.second.first;
            int stops = it.second.second;

            if (node == dst)
                return cost;

            if (stops == k + 1)
                continue;

            for (auto edge : adj[node]) {

                int next = edge.first;
                int price = edge.second;

                int newCost = cost + price;
                int newStops = stops + 1;

                if (newCost < dist[next][newStops]) {

                    dist[next][newStops] = newCost;

                    pq.push({
                        newCost,
                        {next, newStops}
                    });
                }
            }
        }

        return -1;
    }
};