#include <bits/stdc++.h>
using namespace std;

int main() {
    // Declare a priority queue with 3 elements in the tuple: (cost, city, stops)
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

    // Push some sample data into the priority queue
    pq.push(make_tuple(100, 1, 0)); // (cost = 100, city = 1, stops = 0)
    pq.push(make_tuple(50, 2, 1));  // (cost = 50, city = 2, stops = 1)
    pq.push(make_tuple(200, 3, 2)); // (cost = 200, city = 3, stops = 2)

    // Pop and display elements from the priority queue
    while (!pq.empty()) {
        tuple<int, int, int> top = pq.top();  // Get the top element (tuple)
        pq.pop();
        
        int cost = get<0>(top);  // Get the cost (1st element of the tuple)
        int city = get<1>(top);  // Get the city (2nd element of the tuple)
        int stops = get<2>(top); // Get the stops (3rd element of the tuple)

        cout << "Cost: " << cost << ", City: " << city << ", Stops: " << stops << endl;
    }

    return 0;
}
