#include <bits/stdc++.h>
using namespace std;

const int N = 5;                // Number of cities
const double ALPHA = 1.0;       // Pheromone importance
const double BETA = 2.0;        // Heuristic importance
const double EVAPORATION = 0.5; 
const double Q = 100;          
const int ANTS = 10;           
const int ITERATIONS = 100;

vector<vector<double>> distances = {
    // {0, 2, 9, 10, 7},
    // {1, 0, 6, 4, 3},
    // {15, 7, 0, 8, 5},
    // {6, 3, 12, 0, 9},
    // {9, 8, 10, 6, 0}
    {0, 0, 0},
    {1, 1, 1},
    {2, 2, 2},
    {3, 3, 3},
    {4, 4, 4}};

vector<vector<double>> pheromones(N, vector<double>(N, 1.0));

double probability(int from, int to, const vector<bool> &visited)
{
    if (visited[to])
        return 0.0;
    double numerator = pow(pheromones[from][to], ALPHA) * pow(1.0 / distances[from][to], BETA);
    double denominator = 0.0;
    for (int i = 0; i < N; i++)
    {
        if (!visited[i])
        {
            denominator += pow(pheromones[from][i], ALPHA) * pow(1.0 / distances[from][i], BETA);
        }
    }
    return numerator / denominator;
}

vector<int> find_tour()
{
    vector<int> tour;
    vector<bool> visited(N, false);
    int current = rand() % N;
    tour.push_back(current);
    visited[current] = true;

    for (int step = 1; step < N; step++)
    {
        vector<double> probs(N, 0.0);
        for (int i = 0; i < N; i++)
        {
            probs[i] = probability(current, i, visited);
        }

        int next = max_element(probs.begin(), probs.end()) - probs.begin();
        if (visited[next])
        {
            for (int i = 0; i < N; i++)
            {
                if (!visited[i])
                {
                    next = i;
                    break;
                }
            }
        }
        tour.push_back(next);
        visited[next] = true;
        current = next;
    }
    return tour;
}

void update_pheromones(const vector<vector<int>> &all_tours)
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            pheromones[i][j] *= (1 - EVAPORATION);

    for (const auto &tour : all_tours)
    {
        double tour_length = 0;
        for (int i = 0; i < N - 1; i++)
            tour_length += distances[tour[i]][tour[i + 1]];
        tour_length += distances[tour[N - 1]][tour[0]];

        for (int i = 0; i < N - 1; i++)
            pheromones[tour[i]][tour[i + 1]] += Q / tour_length;
    }
}

void aco_tsp()
{
    vector<int> best_tour;
    double best_length = DBL_MAX;

    for (int iter = 0; iter < ITERATIONS; iter++)
    {
        vector<vector<int>> all_tours;
        for (int ant = 0; ant < ANTS; ant++)
            all_tours.push_back(find_tour());

        for (const auto &tour : all_tours)
        {
            double tour_length = 0;
            for (int i = 0; i < N - 1; i++)
                tour_length += distances[tour[i]][tour[i + 1]];
            tour_length += distances[tour[N - 1]][tour[0]];

            if (tour_length < best_length)
            {
                best_length = tour_length;
                best_tour = tour;
            }
        }
        update_pheromones(all_tours);
    }

    cout << "Best Path: ";
    for (int city : best_tour)
        cout << city << " ";
    cout << best_tour[0] << endl;
    cout << "Best Path Length: " << best_length << endl;
}

int main()
{
    srand(time(0));
    aco_tsp();
    return 0;
}
