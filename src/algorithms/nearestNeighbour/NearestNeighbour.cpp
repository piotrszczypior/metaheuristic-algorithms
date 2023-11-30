#include <climits>
#include "NearestNeighbour.h"

pair<int, vector<int>> NearestNeighbour::find_solution(vector<vector<int>> graph) {
    int number_of_cities = graph.size();
    vector<bool> visited_cities(number_of_cities, false);
    int current_city = 0;
    visited_cities[current_city] = true;
    int next_nearest_city = 0;
    vector<int> nearest_neighbour_path(number_of_cities + 1, 0);
    int minimum_distance = INT_MAX;
    int path_cost = 0;

    for (int i = 1; i < number_of_cities; ++i) {
        minimum_distance = INT_MAX;
        for (int next_city = 0; next_city < number_of_cities; ++next_city) {
            if (graph[current_city][next_city] < minimum_distance && !visited_cities[next_city]) {
                minimum_distance = graph[current_city][next_city];
                next_nearest_city = next_city;
            }
        }
        nearest_neighbour_path[i] = next_nearest_city;
        path_cost += minimum_distance;
        current_city = next_nearest_city;
        visited_cities[current_city] = true;
    }
    path_cost += graph[current_city][0];

    return make_pair(path_cost, nearest_neighbour_path);
}
