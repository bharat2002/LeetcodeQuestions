#include <iostream>
#include <vector>
#include <map>
using namespace std;
#include <set>
class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) 
    {
        vector<int> res;
        vector<int> prefixSum(words.size() + 1, 0); // Prefix sum to count vowel-strings
        
        set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        
        // Build the prefix sum
        for (int i = 0; i < words.size(); i++) {
            // Check if the word starts and ends with a vowel
            if (vowels.find(words[i][0]) != vowels.end() && 
                vowels.find(words[i].back()) != vowels.end()) {
                prefixSum[i + 1] = prefixSum[i] + 1;
            } else {
                prefixSum[i + 1] = prefixSum[i];
            }
        }
        
        // Process the queries
        for (int i = 0; i < queries.size(); i++) {
            int start = queries[i][0];
            int end = queries[i][1];
            // Use the prefix sum to calculate the number of valid vowel-strings in the range
            res.push_back(prefixSum[end + 1] - prefixSum[start]);
        }
        
        return res;    
    }
};
int main()
{
    Solution s;
    vector<string> words = {"aba","bcb","ece","aa","e"};
    vector<vector<int>> queries = {{0,2},{1,4},{1,1}};
    vector<int> res = s.vowelStrings(words, queries);
    for(int i = 0; i < res.size(); i++)
    {
        cout<<res[i]<<" ";
    }
    return 0;
}