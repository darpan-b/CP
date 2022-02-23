#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    // attempt 1:
    // only take in ingredients which everyone likes

    int n;
    cin >> n;

    map<string, int> likes, dislikes;

    for (int i = 0; i < n; i++)
    {
        int nLikes;
        cin >> nLikes;
        for (int j = 0; j < nLikes; j++)
        {
            string str;
            cin >> str;
            likes[str]++;
        }
        int nDislikes;
        cin >> nDislikes;
        for (int j = 0; j < nDislikes; j++)
        {
            string str;
            cin >> str;
            dislikes[str]++;
        }
    }
    vector<string> answer;
    for (const auto &e : likes)
    {
        if (dislikes.find(e.first) == dislikes.end())
            answer.push_back(e.first);
    }

    cout << answer.size() << " ";
    for (const auto &e : answer)
        cout << e << " ";
    cout << "\n";

    return 0;
}
