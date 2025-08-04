//  link to the problem : https://cses.fi/alon/task/1629
//  Concepts Used : Sort by End (greedy) . Do Search the concept why do sort by end ?

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n;
    cin>>n;
    
    vector<vector<int>> movieTime;
    for(int i=0; i<n; i++){
        int a,b;
        cin>>a>>b;
        
        movieTime.push_back({a,b});
    }

    sort(movieTime.begin(),movieTime.end(),[](vector<int> v1,vector<int> v2){
        if(v1[1]==v2[1]){
            return v1[0] < v2[0];
        }
        return v1[1] < v2[1];
    });

    int canWatch = 1 , end = movieTime[0][1];

    for(int i=1; i<n; i++){
        if(movieTime[i][0] >= end){
            canWatch++;
            end = movieTime[i][1];
        }
    }

    cout<<canWatch<<endl;
    return 0;
}