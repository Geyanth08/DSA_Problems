// Find fixed point (vakue equal to index) in agiven array

#include <bits/stdc++.h>
using namespace std;

// Function Declaration
vector<int> valueEqualToIndex(int arr[], int n);

// Main Function
int main(){
    int n;
    cin >> n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    vector<int> fixed_points = valueEqualToIndex(arr,n);

    if(fixed_points.empty()){
        cout << " Not Found";
    }else{
        for(int x : fixed_points){
            cout << x << " ";
        }cout << "\n";
    }
}

// Using linear Search -> Time Complexity - O(n), Space Comlexity - O(n)
vector<int> valueEqualToIndex(int arr[], int n){
    vector<int> res;
	
    for(int i=0;i<n;i++){
        if(arr[i]==i+1){
	        res.push_back(i+1);
        }
    }
	    
	return res;
}