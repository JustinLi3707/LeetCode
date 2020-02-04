class Solution {
public:
    // Time: O(nlogn)
    // Space: O(n)
    // entering and leaving point with same x, process entering point first -> set entering point to a negative value
    // entering point with same x, process the highest point first -> set entering point to a negative value
    // leaving point with same x, process the lowest point first -> set leaving point to a positive value
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> res;
        vector<pair<int, int>> points;
        for (auto & b : buildings) {
            points.emplace_back(b[0], -b[2]);
            points.emplace_back(b[1], b[2]);
            sort(points.begin(), points.end());
        }
        multiset<int> m({0});
        int pre = 0, cur = 0;
        for (auto & p : points) {
            if (p.second < 0) {
                m.insert(-p.second);
            } else {
                m.erase(m.find(p.second));
            }
            cur = *m.rbegin();
            if (cur != pre) {
                res.push_back({p.first, cur});
                pre = cur;
            }
        }
        return res;
    }
};
