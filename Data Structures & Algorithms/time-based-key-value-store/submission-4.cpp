class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> store;

public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (store.find(key) == store.end()) return "";

        const vector<pair<int, string>>& history = store[key];

        auto it = upper_bound(
            history.begin(), 
            history.end(), 
            timestamp, 
            [](int ts, const pair<int, string>& p) {
                return ts < p.first;
            }
        );

        if (it == history.begin()) return "";

        return (it - 1)->second;
    }
};