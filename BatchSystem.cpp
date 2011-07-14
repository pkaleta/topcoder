#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<cstring>
using namespace std;

class BatchSystem {
    public:
        typedef pair<vector<int>, int> mypair;

        struct mycmp
        {
            bool operator () (const mypair& a, const mypair& b)
            {
                return a.second < b.second;
            }
        };

        vector <int> schedule(vector <int> duration, vector <string> user) {
            map<string, mypair> m;
            for (int i = 0; i < duration.size(); ++i)
            {
                if (m.find(user[i]) != m.end())
                {
                    mypair u = m[user[i]];
                    u.first.push_back(i);
                    m[user[i]] = mypair(u.first, duration[i]+u.second);
                }
                else
                {
                    vector<int> x;
                    x.push_back(i);
                    m[user[i]] = mypair(x, duration[i]);
                }
            }
            vector<mypair> users;
            map<string, mypair>::iterator I;
            for (I = m.begin(); I != m.end(); ++I)
                users.push_back(I->second);

            sort(users.begin(), users.end(), mycmp());
            vector<int> result;
            for (int i = 0; i < users.size(); ++i)
            {
                for (int j = 0; j < users[i].first.size(); ++j)
                    result.push_back(users[i].first[j]);
            }
            return result;
        }
};
