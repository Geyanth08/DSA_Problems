// Leetcode link - https://leetcode.com/problems/search-a-2d-matrix/
// Search a element in a array which is sorted (increasing) row wise and column wise

#include <iostream>
using namespace std;

// Main Function
int main(){
    int row,col;
    cin >> row >> col;

    int arr[row][col];
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++)
            cin >> arr[i][j];
    }

    int target; cin >> target;

    // Time Complexity -> O(row + col), Space Complexity -> O(1)
    bool found = false;

    int r = 0, c = row-1;

    while(r<col && c>=0){
        if(arr[r][c] == target){
            found = true;
        }
        arr[r][c] > target ? c-- : r++;
    }

    if(found){
        cout << "Element is found"  << endl;
    }else {
        cout << "Element is not found" << endl;
    }
    return 0;
}