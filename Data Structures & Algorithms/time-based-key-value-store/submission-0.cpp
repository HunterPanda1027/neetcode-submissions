class TimeMap {
private:
    // Maps each key to a vector of (timestamp, value) pairs.
    // The vector remains sorted by timestamp because set() timestamps are strictly increasing.
    std::unordered_map<std::string, std::vector<std::pair<int, std::string>>> store;

public:
    TimeMap() {
        
    }
    
    void set(std::string key, std::string value, int timestamp) {
        store[key].push_back({timestamp, value});
    }
    
    std::string get(std::string key, int timestamp) {
        // If the key doesn't exist, return empty string
        if (store.find(key) == store.end()) {
            return "";
        }

        const auto& history = store[key];

        // Binary search using std::upper_bound to find the first entry 
        // with a timestamp strictly greater than the given timestamp.
        auto it = std::upper_bound(
            history.begin(), 
            history.end(), 
            timestamp, 
            [](int ts, const std::pair<int, std::string>& pair) {
                return ts < pair.first;
            }
        );

        // If upper_bound points to the beginning, no timestamp <= requested timestamp exists
        if (it == history.begin()) {
            return "";
        }

        // The target element is right before the iterator returned by upper_bound
        return (it - 1)->second;
    }
};
