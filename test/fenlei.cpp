#include <iostream>
#include <map>
#include <vector>
#include <set>
using namespace std ;
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        map<string, string> owner;          // map from the representative to name
        map<string, string> parents;        // map from an account to its representative
        map<string, set<string>> unions;    // the unions of accounts
        for (int i = 0; i < accounts.size(); ++i) {
            for (int j = 1; j < accounts[i].size(); ++j) {
                parents[accounts[i][j]] = accounts[i][j];   // initialize as itself
                owner[accounts[i][j]] = accounts[i][0];
            }
        }
        for (int i = 0; i < accounts.size(); ++i) {         // find and union
            string ancestor = find(accounts[i][1], parents);
            for (int j = 2; j < accounts[i].size(); ++j) {
                parents[find(accounts[i][j], parents)] = ancestor;
            }
        }
        for (int i = 0; i < accounts.size(); ++i) {
            for (int j = 1; j < accounts[i].size(); ++j) {
                unions[find(accounts[i][j], parents)].insert(accounts[i][j]);
            }
        }
        vector<vector<string>> res;
        for (auto p : unions) {
            vector<string> emails(p.second.begin(), p.second.end());
            emails.insert(emails.begin(), owner[p.first]);
            res.push_back(emails);
        }
        return res;
    }
private:
    string find(string s, map<string, string> &p) {
        return p[s] == s ? s : find(p[s], p);
    }
};
