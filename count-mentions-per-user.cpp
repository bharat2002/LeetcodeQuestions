#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution {
public:
    static bool cmp(vector<string> a, vector<string> b) {
        return stoi(a[1]) != stoi(b[1]) ? stoi(a[1]) < stoi(b[1]) : a[0] == "OFFLINE";
    }

    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        sort(events.begin(), events.end(), cmp);
        vector<int> ans(numberOfUsers, 0), tmp(numberOfUsers, 1);
        unordered_map<int, int> mp;

        for (auto it : events) {
            string type = it[0];
            int tt = stoi(it[1]);

            if (type == "OFFLINE") {
                int ids = stoi(it[2]);
                if (ids >= 0 && ids < numberOfUsers) {
                    mp[ids] = tt + 60;
                    tmp[ids] = 0;
                }
            }

            for (int i = 0; i < numberOfUsers; i++) {
                if (tmp[i] == 0 && mp[i] <= tt) {
                    tmp[i] = 1;
                }
            }

            if (type == "MESSAGE") {
                string str = it[2];
                vector<int> st;

                if (str == "ALL") {
                    for (int i = 0; i < numberOfUsers; i++) {
                        st.push_back(i);
                    }
                } else if (str == "HERE") {
                    for (int i = 0; i < numberOfUsers; i++) {
                        if (tmp[i]) {
                            st.push_back(i);
                        }
                    }
                } else {
                    stringstream ss(str);
                    string token;
                    while (ss >> token) {
                        int ids = stoi(token.substr(2));
                        if (ids >= 0 && ids < numberOfUsers) {
                            st.push_back(ids);
                        }
                    }
                }

                for (auto it : st) {
                    ans[it]++;
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<string>> events = {
        {"MESSAGE", "1", "id0 id1"},
        {"MESSAGE", "5", "id2"},
        {"MESSAGE", "6", "ALL"},
        {"OFFLINE", "5", "2"}
    };
    vector<int> res = s.countMentions(3, events);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    return 0;
}
