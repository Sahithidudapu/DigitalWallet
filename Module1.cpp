#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool compare(pair<int,int> x, pair<int,int> y) {
    if(x.second == y.second) {
        return x.first < y.first;
    }
        return x.second < y.second;
    
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n;
    cin >> n;
    vector<pair<int,int>> vec1;
    vector<int> vec2(n);
    int userID,bal;
    for(int i = 0; i < n; i++)
    {
        cin >> userID >> bal;
        vec2[userID] = bal;
    }
    int t;
    cin >> t;
    vector<string> a;
    while(t--)
    {
        int from_userID,to_userID,amt;
        cin >> from_userID >> to_userID >> amt;
            int value;
            value = vec2[from_userID] - amt;
            if(value > 0){
                a.push_back("Success");
                vec2[from_userID]  = value;
                vec2[to_userID] = vec2[to_userID] + amt;
            }
            else {
                a.push_back("Failure");
            }
    }
    for(int i=1; i <= n; i++)
    {
        if(vec2[i] > 0)vec1.push_back({i,vec2[i]});
    }
    for(string str : a)
    {
        cout << str << endl;
    }
    cout << endl;
    sort(vec1.begin(), vec1.end(), compare);
    for(int i = 0; i < n; i++) {
        cout << vec1[i].first << " " <<vec1[i].second << endl;
    }
    return 0;
}

