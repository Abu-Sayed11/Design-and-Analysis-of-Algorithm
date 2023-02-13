#include<bits/stdc++.h>
using namespace std;

#define ll long long 

void LPS(string pat,int M,int lps[]);

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

void kmp(string text,string pat){

    int N = text.size();
    int M = pat.size();
    
    int lps[M];
    LPS(pat,M,lps);

    int i = 0, j = 0;
    int ans = 0,best = 0,result = 0;
    while(i < N){
        if(text[i] == pat[j]){
            best++;
            i++;
            j++;
        }else{
            best = 0;
            if(j != 0){
                j = lps[j-1];
            }else{
                i++;
            }
        }
        if(best > result) result = best,ans = i - j;
        if(j == M){
            break;
        }
    }
    cout << ans << endl;
}

int main(){

    int n;
    string a,b;
    cin >> n >> a >> b;
  
    b += b;

    kmp(b,a);

    return 0;
}
