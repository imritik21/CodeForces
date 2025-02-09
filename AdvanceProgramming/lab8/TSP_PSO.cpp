#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <random>
#include <limits>

class City
{
public:
    int id;
    double x, y;
    City(int id, double x, double y) : id(id), x(x), y(y) {}
};

class Particle
{
public:
    std::vector<int> position;
    std::vector<int> velocity;
    std::vector<int> bestPosition;
    double bestFitness;

    Particle(int size) : position(size), velocity(size), bestPosition(size), bestFitness(std::numeric_limits<double>::max()) {}
};

class PSO_TSP
{
private:
    std::vector<City> cities;
    std::vector<Particle> particles;
    std::vector<int> globalBestPosition;
    double globalBestFitness;
    int numParticles;
    int maxIterations;
    double c1, c2;
    std::mt19937 rng;

public:
    PSO_TSP(const std::vector<City> &cities, int numParticles, int maxIterations, double c1, double c2)
        : cities(cities), numParticles(numParticles), maxIterations(maxIterations), c1(c1), c2(c2),
          globalBestFitness(std::numeric_limits<double>::max())
    {
        rng.seed(std::random_device()());
        initializeParticles();
    }

    void initializeParticles()
    {
        for (int i = 0; i < numParticles; ++i)
        {
            Particle particle(cities.size());
            for (int j = 0; j < cities.size(); ++j)
            {
                particle.position[j] = j;
            }
            std::shuffle(particle.position.begin(), particle.position.end(), rng);
            particle.bestPosition = particle.position;
            particle.bestFitness = calculateFitness(particle.position);
            particles.push_back(particle);

            if (particle.bestFitness < globalBestFitness)
            {
                globalBestFitness = particle.bestFitness;
                globalBestPosition = particle.position;
            }
        }
    }

    double calculateFitness(const std::vector<int> &tour)
    {
        double distance = 0;
        for (int i = 0; i < tour.size(); ++i)
        {
            int from = tour[i];
            int to = tour[(i + 1) % tour.size()];
            double dx = cities[from].x - cities[to].x;
            double dy = cities[from].y - cities[to].y;
            distance += std::sqrt(dx * dx + dy * dy);
        }
        return distance;
    }

    void updateVelocity(Particle &particle)
    {
        std::uniform_real_distribution<> dis(0.0, 1.0);
        for (int i = 0; i < particle.velocity.size(); ++i)
        {
            particle.velocity[i] = particle.velocity[i] + c1 * dis(rng) * (particle.bestPosition[i] - particle.position[i]) + c2 * dis(rng) * (globalBestPosition[i] - particle.position[i]);
        }
    }

    void updatePosition(Particle &particle)
    {
        std::vector<std::pair<int, int>> indexedPosition(particle.position.size());
        for (int i = 0; i < particle.position.size(); ++i)
        {
            indexedPosition[i] = {particle.position[i], particle.velocity[i]};
        }
        std::sort(indexedPosition.begin(), indexedPosition.end(),
                  [](const auto &a, const auto &b)
                  { return a.second < b.second; });
        for (int i = 0; i < particle.position.size(); ++i)
        {
            particle.position[i] = indexedPosition[i].first;
        }
    }

    void optimize()
    {
        for (int iter = 0; iter < maxIterations; ++iter)
        {
            for (auto &particle : particles)
            {
                updateVelocity(particle);
                updatePosition(particle);

                double fitness = calculateFitness(particle.position);
                if (fitness < particle.bestFitness)
                {
                    particle.bestFitness = fitness;
                    particle.bestPosition = particle.position;
                }

                if (fitness < globalBestFitness)
                {
                    globalBestFitness = fitness;
                    globalBestPosition = particle.position;
                }
            }
        }
    }

    void printBestTour()
    {
        std::cout << "Best tour: ";
        for (int city : globalBestPosition)
        {
            std::cout << city << " ";
        }
        std::cout << "\nTotal distance: " << globalBestFitness << std::endl;
    }
};

int main()
{
    std::vector<City> cities = {
        {0, 0, 0}, {1, 1, 1}, {2, 2, 2}, {3, 3, 3}, {4, 4, 4}};

    PSO_TSP pso(cities, 50, 1000, 1.5, 1.5);
    pso.optimize();
    pso.printBestTour();

    return 0;
}
