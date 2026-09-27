class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> store;

public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        // Return empty string if key has no recorded timestamps
        if (store.find(key) == store.end()) return "";

        const vector<pair<int, string>>& history = store[key];

        int left = 0;
        int right = history.size() - 1;
        string res = "";

        // Standard binary search loop
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (history[mid].first <= timestamp) {
                res = history[mid].second; // Candidate answer found; record it
                left = mid + 1;            // Try to find a larger timestamp_prev <= timestamp
            } else {
                right = mid - 1;           // Timestamp too large; search left half
            }
        }

        return res;
    }
};