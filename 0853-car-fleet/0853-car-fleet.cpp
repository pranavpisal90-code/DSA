#include <vector>
#include <algorithm>

class Solution {
public:
    int carFleet(int target, std::vector<int>& position, std::vector<int>& speed) {
        int n = position.size();
        std::vector<std::pair<int, double>> cars(n);

        for (int i = 0; i < n; ++i) {
            cars[i] = {position[i], (double)(target - position[i]) / speed[i]};
        }

        // Sort cars descending by starting position
        std::sort(cars.rbegin(), cars.rend());

        int fleets = 0;
        double max_time = 0.0;

        for (const auto& car : cars) {
            // If this car takes strictly longer than the current fleet ahead,
            // it forms a new fleet and becomes the new bottleneck time.
            if (car.second > max_time) {
                fleets++;
                max_time = car.second;
            }
        }

        return fleets;
    }
};