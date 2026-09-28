class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> store;

public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {

        if (store.find(key) == store.end()) return "";

        const vector<pair<int, string>>& history = store[key];

        int left = 0;
        int right = history.size() - 1;
        string res = "";

        while (left <= right) {
            int middle = left + (right - left) / 2;

            if (history[middle].first <= timestamp) {
                res = history[middle].second;
                left = middle + 1;
            } else {
                right = middle - 1;
            }
        }

        return res;
        
    }
};
