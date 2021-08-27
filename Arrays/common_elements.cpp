// Find common elements from 3 sorted arrays

#include <bits/stdc++.h>
using namespace std;

// Function Declaration
vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3);

// Main Function
int main(){
    int n1,n2,n3;
    cin >> n1 >> n2 >> n3;

    int arr1[n1],arr2[n2],arr3[n3];
    for(int i=0;i<n1;i++){
        cin >> arr1[i];
    }
    for(int i=0;i<n2;i++){
        cin >> arr2[i];
    }
    for(int i=0;i<n3;i++){
        cin >> arr3[i];
    }

    vector<int> result;

    result = commonElements(arr1,arr2,arr3,n1,n2,n3);

    vector<int>::iterator it;
    for(it=result.begin();it < result.end();it++){
        cout << *it << " ";
    }cout << endl;
    
    return 0;
}

// Simple Apporach by Searching - Time Complexity - O(n1+n2+n3), Space Complexity - O(n1+n2+n3)
vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3){
    
    int i=0,j=0,k=0;
    vector<int> repeat_elements;
            
    while(i<n1 && j<n2 && k<n3){
        if(A[i]==B[j] && A[i]==C[k]){
            repeat_elements.push_back(A[i]);
            i++; j++; k++;
        }else if(A[i] < B[j]){
            i++;
        }else if(B[j] < C[k]){
            j++;
        }else{
            k++;
        }
    }

    // Removing Repeated elements  
    vector<int>::iterator ip;
    ip = unique(repeat_elements.begin(), repeat_elements.end());
    repeat_elements.resize(distance(repeat_elements.begin(), ip));
           
    return repeat_elements;

}
