#include <iostream>
using namespace std;

void divide(){}
void merge(){}

void sortBubble(){}
void sortSelection(){}
void sortInsertion(){}
void sortMerge(){}
void sortQuick(){}
void sortCount(){}

void printArray(int arr[],int len){
    for(int i=0;i<len;i++){
        cout << arr[i] << " ";
    }
}

void sortBubble(int arr[],int len){
    for(int i=0;i<len-1;i++){
        for(int c=0;c<len-i-1;c++){
            if(arr[c+1]<arr[c]){
                int temp = arr[c+1];
                arr[c+1] = arr[c];
                arr[c] = temp;
            }
        }
    }
}

void sortSelection(int arr[],int len){
    for(int i=0;i<len;i++){
        int c = i;
        for(int j=i+1;j<len;j++){
            if(arr[j]<arr[c]){
                c = j;
            }
        }
        if(c!=i){
            int temp = arr[c];
            arr[c] = arr[i];
            arr[i] = temp;
        }
    }
}

void sortInsertion(int arr[],int len){
    int i,c,v;
    for(int i=1;i<len;i++){
        v = arr[i];
        c = i-1;
        while(c>=0 && arr[c]>v){
            arr[c+1] = arr[c];
            c = c-1;
        }
        arr[c+1] = v;
    }
}

void merge(int L[],int R[],int arr[],int nL,int nR){
    int i = 0,j = 0,k = 0;

    while(i<nL && j<nR){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i += 1;
        } else{
            arr[k] = R[j];
            j += 1;
        }
        k += 1;
    }

    while(i < nL){
        arr[k] = L[i];
        i += 1;
        k += 1;
    }

    while(j < nR){
        arr[k] = R[j];
        j += 1;
        k += 1;
    }
}

void sortMerge(int arr[],int n) {
    if(n < 2)
        return;

    int mid = n/2;

    int L[mid],R[n-mid];

    for (int i=0;i<mid;i++)
        L[i] = arr[i];

    for (int i=mid;i<n;i++)
        R[i-mid] = arr[i];

    sortMerge(L,mid);
    sortMerge(R,n -mid);

    merge(L,R,arr,mid,n-mid);
}

void countingSort(int arr[], int n, int k) {
    int countArr[k];
    int outputArr[n];

    cout << "Initial array:" << endl;
    printArray(arr, n);

    for (int i = 0; i < k; i++) {
        countArr[i] = 0;
    }

    cout << "Initial counting array:" << endl;
    printArray(countArr, k);

    for (int j = 0; j < n; j++) {
        countArr[arr[j]]++;
    }

    cout << "Frequency counting array:" << endl;
    printArray(countArr, k);

    for (int i = 1; i < k; i++) {
        countArr[i] += countArr[i - 1];
    }

    cout << "Cumulative sum counting array:" << endl;
    printArray(countArr, k);

    for (int j = n - 1; j >= 0; j--) {
        outputArr[countArr[arr[j]] - 1] = arr[j];
        countArr[arr[j]]--;
    }

    cout << "Sorted array:" << endl;
    printArray(outputArr, n);
}

// int main(){
//     int ex1[] = {1,4,93,34,43,67,27,98,1};
//     int ex2[] = {6,2,8,4,3,7,5,1};
//     int len1 = sizeof(ex1)/sizeof(ex1[0]);
//     int len2 = sizeof(ex2)/sizeof(ex2[0]);

//     sortBubble(ex1,len1);
//     sortMerge(ex2,len2);

//     cout << endl;
//     printArray(ex2,len2);
//     cout << endl;

//     return 0;
// }