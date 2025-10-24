void dijkstra(vector<pair<int, int>> adj_list[], vector<int> shortest_distances, int source_vertex, int destination_vertex)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source_vertex}); // marking the initial distance of source vertex as 0.
    shortest_distances[source_vertex] = 0;
    while (!pq.empty())
    {
        int curr_dist = pq.top().first;
        int curr_vertex = pq.top().second;
        pq.pop();
        for (auto j : adj_list[curr_vertex])
        {
            if (shortest_distances[j.first] > curr_dist + j.second)
            {
                shortest_distances[j.first] = curr_dist + j.second;
                pq.push({shortest_distances[j.first], j.first});
            }
        }
    }
    return;
}
