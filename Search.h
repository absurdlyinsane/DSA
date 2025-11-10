#include <iostream>
using std::cout;
using std::endl;

int searchLinear(int arr[],int len,int key){
    int result;
    for(int i=0;i<len-1;i++){
        if(key==arr[i]){
            result = i;
            break;
        } else{
            result = -1;
        }
    }
    
    if(result<0){
        cout << "Key not found" << endl;
    } else{
        cout << "Key found at index: " << result << endl;
    }
    return result;
}

int searchBinary(int arr[],int len, int key){
    int left = 0;
    int right = len-1;

    int result;

    while(left<=right){
        int mid = left+(right-left)/2;
        
        if(arr[mid]==key){
            result = mid;
            cout << "Key found at index: " << mid << endl;
            break;
        } else if(arr[mid]<key){
            left=mid+1;
        } else if(arr[mid]>key){
            right=mid-1;
        } else{
            result = -1; cout << "Key not found" << endl;
            break;
        }
    }

    return result;
}