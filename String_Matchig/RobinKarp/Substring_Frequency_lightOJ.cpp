#include <bits/stdc++.h>
using namespace std;

#define fileIO                        \freopen("input.txt", "r", stdin); \freopen("output.txt", "w", stdout);
#define fast                          \ios_base::sync_with_stdio(false); \cin.tie(NULL);
#define ll long long
#define ld long double
#define mod 1000000007
#define PI 3.1415926535897932384626433
#define pb push_back;
#define mp make_pair
#define endl '\n'
#define d 256

vector<int> rabinKarp(string pattern, string text, ll q)
{
    int k = 1;
    vector<int> v;
    int m = pattern.size();
    int n = text.size();
    int i, j;
    ll p = 0;
    ll t = 0;
    ll h = 1;

    for (i = 0; i < m - 1; i++)
        h = (h * d) % q;

    for (i = 0; i < m; i++)
    {
        p = (d * p + int(pattern[i])) % q;
        t = (d * t + int(text[i])) % q;
    }

    for (i = 0; i <= n - m; i++)
    {
        if (p == t)
        {
            for (j = 0; j < m; j++)
            {
                if (text[i + j] != pattern[j])
                    break;
            }

            if (j == m)
                v.push_back(i + 1);
        }

        if (i < n - m)
        {
            t = (d * (t - int(text[i]) * h) + int(text[i + m])) % q;

            if (t < 0)
                t = (t + q);
        }
    }
    return v;
}

int main()
{
    int T, q = 101;
    cin >> T;
    int k = 1;
    while (T--)
    {
        string txt, pat;
        cin >> txt >> pat;
        vector<int> v = rabinKarp(pat, txt, q);
        cout << "Case " << k << ": " << v.size() << endl;
        k++;
    }
    
    return 0;
}
