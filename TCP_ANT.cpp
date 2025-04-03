#include <bits/stdc++.h>
using namespace std;

class AntColonyOptimizationTSP
{
    int numCities, numAnts, maxIterations;
    double alpha, beta, evaporationRate, Q;
    vector<vector<double>> distances;     // Base distance matrix
    vector<vector<double>> traffic;       // Traffic delay factors
    vector<vector<double>> roadCondition; // Road condition factors
    vector<vector<double>> pheromones;    // Pheromone matrix
    mt19937 rng;                          // Random number generator

public:
    // Constructor now accepts traffic and road condition matrices.
    AntColonyOptimizationTSP(int numCities, int numAnts, int maxIterations,
                             double alpha, double beta, double evaporationRate,
                             double Q, const vector<vector<double>> &distances,
                             const vector<vector<double>> &traffic,
                             const vector<vector<double>> &roadCondition)
        : numCities(numCities), numAnts(numAnts), maxIterations(maxIterations),
          alpha(alpha), beta(beta), evaporationRate(evaporationRate), Q(Q),
          distances(distances), traffic(traffic), roadCondition(roadCondition)
    {
        pheromones = vector<vector<double>>(numCities, vector<double>(numCities, 1.0));
        random_device rd;
        rng = mt19937(rd());
    }

    // Solve the TSP using ACO and return the best tour.
    vector<int> solve()
    {
        vector<int> bestTour;
        double bestTourLength = numeric_limits<double>::max();

        for (int iter = 0; iter < maxIterations; iter++)
        {
            vector<vector<int>> allTours(numAnts, vector<int>(numCities));
            vector<double> allTourLengths(numAnts, 0.0);
            for (int ant = 0; ant < numAnts; ant++)
            {
                allTours[ant] = constructTour();
                allTourLengths[ant] = getTourLength(allTours[ant]);
                if (allTourLengths[ant] < bestTourLength)
                {
                    bestTourLength = allTourLengths[ant];
                    bestTour = allTours[ant];
                }
            }
            updatePheromones(allTours, allTourLengths);
        }
        cout << "Best Tour Length: " << getTourLength(bestTour) << "\n";
        return bestTour;
    }

    // Calculate the tour length using effective distances.
    double getTourLength(const vector<int> &tour)
    {
        double length = 0.0;
        for (int i = 0; i < numCities - 1; i++)
        {
            length += getEffectiveDistance(tour[i], tour[i + 1]);
        }
        // Return to the start city
        length += getEffectiveDistance(tour[numCities - 1], tour[0]);
        return length;
    }

private:
    // Compute effective distance combining distance, traffic, and road condition.
    double getEffectiveDistance(int i, int j)
    {
        return distances[i][j] * traffic[i][j] * roadCondition[i][j];
    }

    // Construct a tour for an ant.
    vector<int> constructTour()
    {
        vector<int> tour(numCities, 0);
        vector<bool> visited(numCities, false);

        // Choose a random starting city.
        uniform_int_distribution<int> dist(0, numCities - 1);
        int currentCity = dist(rng);
        tour[0] = currentCity;
        visited[currentCity] = true;

        for (int i = 1; i < numCities; i++)
        {
            int nextCity = selectNextCity(currentCity, visited);
            tour[i] = nextCity;
            visited[nextCity] = true;
            currentCity = nextCity;
        }
        return tour;
    }

    // Select the next city based on a roulette wheel selection using pheromone and effective distance.
    int selectNextCity(int currentCity, const vector<bool> &visited)
    {
        vector<double> probabilities(numCities, 0.0);
        double sum = 0.0;
        for (int i = 0; i < numCities; i++)
        {
            if (!visited[i])
            {
                double effDistance = getEffectiveDistance(currentCity, i);
                probabilities[i] = pow(pheromones[currentCity][i], alpha) *
                                   pow(1.0 / effDistance, beta);
                sum += probabilities[i];
            }
        }

        // Roulette wheel selection.
        uniform_real_distribution<double> distReal(0.0, sum);
        double randValue = distReal(rng);
        double cumulative = 0.0;
        for (int i = 0; i < numCities; i++)
        {
            if (!visited[i])
            {
                cumulative += probabilities[i];
                if (cumulative >= randValue)
                    return i;
            }
        }
        throw runtime_error("No next city found!");
    }

    // Update pheromone trails based on the tours of all ants.
    void updatePheromones(const vector<vector<int>> &allTours, const vector<double> &allTourLengths)
    {
        for (int i = 0; i < numCities; i++)
        {
            for (int j = 0; j < numCities; j++)
            {
                pheromones[i][j] *= (1.0 - evaporationRate);
            }
        }
        for (int ant = 0; ant < numAnts; ant++)
        {
            double contribution = Q / allTourLengths[ant];
            const vector<int> &tour = allTours[ant];
            for (int i = 0; i < numCities - 1; i++)
            {
                int city1 = tour[i];
                int city2 = tour[i + 1];
                pheromones[city1][city2] += contribution;
                pheromones[city2][city1] += contribution;
            }
            // Deposit pheromone for the closing edge (last city to start city).
            int last = tour[numCities - 1];
            int first = tour[0];
            pheromones[last][first] += contribution;
            pheromones[first][last] += contribution;
        }
    }
};

int main()
{
    // Number of cities.
    int numCities = 100;

    // Generate a random symmetric distance matrix for 100 cities.
    vector<vector<double>> distances(numCities, vector<double>(numCities, 0.0));
    vector<vector<double>> traffic(numCities, vector<double>(numCities, 1.0));
    vector<vector<double>> roadCondition(numCities, vector<double>(numCities, 1.0));

    random_device rd;
    mt19937 gen(rd());
    // Uniform distribution for distances (e.g., between 10 and 100).
    uniform_real_distribution<double> distGen(10.0, 100.0);
    // Uniform distribution for traffic factors (e.g., between 0.8 and 1.5).
    uniform_real_distribution<double> trafficGen(0.8, 1.5);
    // Uniform distribution for road condition factors (e.g., between 0.9 and 1.2).
    uniform_real_distribution<double> roadGen(0.9, 1.2);

    for (int i = 0; i < numCities; i++)
    {
        for (int j = i + 1; j < numCities; j++)
        {
            double d = distGen(gen);
            distances[i][j] = d;
            distances[j][i] = d;

            double t = trafficGen(gen);
            traffic[i][j] = t;
            traffic[j][i] = t;

            double r = roadGen(gen);
            roadCondition[i][j] = r;
            roadCondition[j][i] = r;
        }
    }

    // ACO parameters.
    int numAnts = 10;        // Increase number of ants.
    int maxIterations = 200; // Increase iterations for larger problem.
    double alpha = 1.0;
    double beta = 2.0;
    double evaporationRate = 0.5;
    double Q = 100;

    // Create the ACO object with extra factors.
    AntColonyOptimizationTSP aco(numCities, numAnts, maxIterations,
                                 alpha, beta, evaporationRate, Q,
                                 distances, traffic, roadCondition);
    vector<int> bestTour = aco.solve();

    // Print detailed tour information.
    cout << "\nDetailed Best Tour Path:\n";
    double totalDistance = 0.0;
    for (int i = 0; i < numCities; i++)
    {
        int fromCity = bestTour[i];
        int toCity = (i == numCities - 1) ? bestTour[0] : bestTour[i + 1];
        double effDist = distances[fromCity][toCity] * traffic[fromCity][toCity] * roadCondition[fromCity][toCity];
        totalDistance += effDist;
        cout << "Ant traveled from City " << fromCity << " to City " << toCity
             << " with effective distance = " << effDist << "\n";
    }
    cout << "\nOptimal Path: ";
    for (int city : bestTour)
    {
        cout << city << " ";
    }
    cout << bestTour[0] << "  (returns to start)\n";
    cout << "Total Tour Length: " << totalDistance << "\n";

    return 0;
}
