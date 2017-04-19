#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int parent(int i){
    
    return (i-1)/2;
}

int left(int i){
    
    return (2*i+1);
}

int right(int i){
    
    return (2*i+2);
}

void insert(int arr[], int *heapsize, int key){
    
    if(*heapsize > 20)
        return;
    
    *heapsize++;
    int i = *heapsize-1;
    arr[i] = key;
    
    while(i != 0 && arr[parent(i)] > arr[i]){
        
        int temp = arr[parent(i)];
        arr[parent(i)] = arr[i];
        arr[i] = temp;
        
        i = parent(i);
    }
}

void minheapify(int i, int arr[], int h){
    
    int smallest = i;
    int l = left(i);
    int r = right(i);
    
    if(l < h && arr[l] < arr[i])
        smallest = l;
    
    if(r < h && arr[r] < arr[smallest])
        smallest = r;
    
    if(smallest != i){
        
        int temp = arr[smallest];
        arr[smallest] = arr[i];
        arr[i] = temp;
        
        minheapify(smallest, arr, h);
    }
}

void deletekey(int dkey, int arr[], int *heapsize){
    
    int dindex;
    for(int i = 0; i<*heapsize; i++){
        if(arr[i] = dkey){
            dindex = i;
        }
    }
    
    arr[dindex] = -10;
    
    while(dindex != 0 && arr[parent(dindex)] > arr[dindex]){
        
        int temp = arr[parent(dindex)];
        arr[parent(dindex)] = arr[dindex];
        arr[dindex] = temp;
        
        dindex = parent(dindex);
    }
    
    arr[dindex] = arr[*heapsize-1];
    *heapsize--;
    minheapify(0, arr, *heapsize);
}

int getmin(int arr[]){
    
    return arr[0];
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    int q;
    cin >> q;
    
    int arr[20];
    int heapsize = 0;
    
    for(int i=0; i<q; i++){
        
        int temp;
        cin >>  temp;
        
        if(temp == 1){
            
            int key;
            cin >> key;
            
            insert(arr, &heapsize, key);
        }
        
        else if(temp == 2){
            
            int dkey;
            cin >> dkey;
            
            deletekey(dkey, arr, &heapsize);
        }
        
        else if(temp == 3){
            
            int temp = getmin(arr);
            cout << temp << endl;
        }
    }
    return 0;
}
