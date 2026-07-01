class Solution {
public:
    // Function to calculate how many days are needed
    int findDays(vector<int>& weights, int capacity) {
        int days = 1;
        int load = 0;

        for (int weight : weights) {
            // If adding this package exceeds capacity,
            // ship it on the next day.
            if (load + weight > capacity) {
                days++;
                load = weight;
            } else {
                load += weight;
            }
        }

        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int requiredDays = findDays(weights, mid);

            if (requiredDays <= days) {
                // Capacity is sufficient, try a smaller one
                high = mid - 1;
            } else {
                // Capacity is too small
                low = mid + 1;
            }
        }
        return low;
    }
};