#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<iostream>
#include<cctype>
#include<map>
#include<stack>
#include<cstdlib>
#include<queue>
#include<vector>
#include<algorithm>
#include<bitset>
#include<algorithm>
#include<set>
#include<limits.h>
#include <sstream>
using namespace std;
#define ll                      long long int
#define fi                      first
#define se                      second
#define pb                      push_back
#define pbb                     pop_back
#define mp                      make_pair
#define pii     	            pair<int,int>
#define all(x)                  x.begin(), x.end()
#define mem(array, value)       memset(array, value, sizeof(array))
#define fastRead 	            ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

struct node
{
    node *next[26 + 1];
    int cnt;
    node (){
        cnt = 0;
        for (int i = 0; i < 26; i++){
            next[i] = NULL;
        }
    }
} *root;

void Insert(string s, int len)
{
    node *cur = root;
    for (int i = 0; i < len; i++){
        int id = s[i] - 'a';
        if (cur -> next[id] == NULL){
            cur -> next[id] = new node();
        }
        cur = cur -> next[id];
        cur -> cnt++;
    }
}

int Search(string s, int len)
{
    node *cur = root;
    for (int i = 0; i < len; i++){
        int id = s[i] - 'a';
        cur = cur -> next[id];
        if (cur -> cnt == 1){
            return i + 1;
        }
    }
}

vector<string> ara;

int main ()
{
    #ifdef Lollipop
        freopen ("input.txt", "r", stdin);
        //freopen ("output.txt", "w", stdout);
    #endif
    //fastRead;
    string s;
    root = new node();
    while (cin >> s){
        ara.pb(s);
        Insert(s, s.size());
    }
    int len = ara.size();
    for (int i = 0; i < len; i++){
        cout << ara[i] << " " << ara[i].substr(0, Search(ara[i], ara[i].size())) << endl;
    }
    return 0;
}

