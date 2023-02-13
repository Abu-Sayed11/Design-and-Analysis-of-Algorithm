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

void LPS(string pat,int m,int lps[]);

void LPS(string pat,int M,int lps[]){

    int i = 0;
    int j = 1;
    lps[0] = 0;

    while(j < M){
        if(pat[i] == pat[j]){
            i++;
            lps[j] = i;
            j++;
        }else{
            if(i != 0){
                i = lps[i-1];
            }else{
                lps[j] = 0;
                j++;
            }
        }
    }
}

 vector<int> kmp(string text,string pat){

    int N = text.size();
    int M = pat.size();
    vector<int> v;
    int lps[M];

    LPS(pat,M,lps);

    int i = 0,j = 0;
    while((N-i) >= (M-j)){
        if(text[i] == pat[j]){
            i++;
            j++;
        }
        if(j == M){
            v.push_back(i-j);
            j = lps[j-1];
        }else if(i < N && pat[j] != text[i]){
            if(j != 0){
                j = lps[j-1];
            }else{
                i++;
            }
        }
    }
    return v;
}

int main(){

    int t;
    cin >> t;
    int i = 1;
    while(t--){
        string text,pat;
        cin >> text >> pat;
        vector<int> ans = kmp(text,pat);
        cout << "Case " << i << ": " << ans.size() << endl;
        i++;
    }

    return 0;
}
