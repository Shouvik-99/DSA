
//? Day 2


#include <bits/stdc++.h>
using namespace std;

//! using priority queue
int kthSmallest(vector<vector<int>>& matrix, int k) {
    priority_queue<int> pq;  
    for(int i = 0; i<matrix.size();i++){
        for(int j = 0; j<matrix[0].size();j++){
            pq.push(matrix[i][j]);
            if(pq.size() > k) pq.pop();
        }
    }
    return pq.top();
}    

//! using binary search
int kthSmallest(vector<vector<int>>& matrix, int k){
    int n = matrix.size();     
    int low = matrix[0][0];
    int high = matrix[n-1][n-1];
    int mid;
    int count;
           
    while(low<high){
        count = 0;
        mid = low + (high - low)/2;
        for(int i=0;i<n;i++){
            count += upper_bound(matrix[i].begin(),matrix[i].end(),mid) - matrix[i].begin();
        }
        if(count < k){
            low = mid+1;
        }
        else{
            high = mid;
        }
    }
    return low;
}

int main(){
    return 0;
}