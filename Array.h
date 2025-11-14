#pragma once
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void printArr(int arr[],int len){
    for(int i=0;i<len;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void inputManual1by1(int arr[],int len){
    for(int i=0;i<len;i++){
        cout << "Input value at index " << i << "<-- ";
        int value; cin >> value;
        cout << endl;
        printArr(arr,len);
        cout << endl;
    }
}

void inputManualSingle(int arr[],int len){
    cout << "Select index (0 ~ " << len-1 << "): ";
    int index; cin >> index;
    cout << "Input value at index " << index << "<-- ";
    int value; cin >> value;
    cout << endl;
    printArr(arr,len);
    cout << endl;
}



struct ArrayInt1D{
    int len;
    int* arr = new int[len];

    ArrayInt1D(int len){
        for (int i=0;i<len;i++){
            arr[i] = -255;
        }
    }

    ArrayInt1D(int len,int val){
        for (int i=0;i<len;i++){
            arr[i] = val;
        }
    }

    void insert(int pos,int val){
        arr[pos]=val;
    }

    ~ArrayInt1D(){
        delete[] arr;
    }
};

struct oldArrayD{
    int len;
    int length=0;
    int arr[len];

    void initArray(){
        for(int i=0;i<len;i++){
            arr[i]=nullptr;
        }
    }

    void initArray(int v){
        for(int i=0;i<len;i++){
            arr[i]=v;
            length=len;
        }
    }

    int getLength(){
        int count=0;
        for(int i=0;i<len;i++){
            if(arr[i]!=0){
                count++;
            } else{
                return count;
            }
        }
    }

    int at(int pos){
        return arr[pos];
    }

    bool isEmpty(){
        for(int i=0;i<len;i++){
            if(arr[i]!=0){
                break;
                return false;
            } else{
                return true;
            }
        }
    }

    bool isFull(){
        if(length==len){
            return true;
        } else{
            return false;
        }
    }

    void print(){
        for(int i=0;i<len;i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void insert(int v){
        arr[length]=v;
    }

    void insertAt(int v,int pos){
        for(int i=length;i>pos-1;i--){
            arr[i]=arr[i-1];
        }
        arr[pos-1]=v;
    }

    void replaceAt(int v,int pos){
        arr[pos]=v;
    }

    void remove(){
        arr[length]=0;
    }

    void removeAt(int pos){
        arr[pos]=0;
    }

    void initArray(){
        for(int i=0;i<len;i++){
            arr[i]=0;
            length=0;
        }
    }

    int sumUpArray(int arr[], int maxSize){
        int sum=0;
        for(int i=0;i<maxSize;i++){
            sum+=arr[i];
        }
        return sum;
    }

    void reverseArray(){
        int rev[len];
        int j=0;

        for(i=len;i>0;i--){
            rev[j++]=arr[i];
        }

        for(int i=0;i<len;i++){
            arr[i]=rev[i];
        }
    }

    void copyArray(int data[], int n){
        for(int i=0;i<n;i++){
            arr[i]=data[i];
        }
    }
};

struct oldArray2D {
    static const int LENX=16;
        static const int LENY=16;
        int arr[LENX][LENY];

    void initArray2D(){
        for(int r=0;r<LENY;r++){
            for(int c=0;c<LENX;c++){
                arr[r][c]=nullptr;
            }
        }
    }

    void initArray(int v){
        for(int r=0;r<LENY;r++){
            for(int c=0;c<LENX;c++){
                arr[r][c]=v;
            }
        }
    }

    void printArray(){
        cout << endl;
        for(int r=0;r<LENY;r++){
            for(int c=0;c<LENX;c++){
                cout << arr[r][c] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    void printDiagonalL(){
        if(LENY==LENX){
            cout << endl;
            for(int r=0;r<LENY;r++){
                for(int s=0;s<r;s++){
                    cout << " ";
                }

                for(int c=0;c<LENX;c++){
                    if(r==c){
                        cout << arr[r][c];
                    }
                }
                cout << endl;
            }
            cout << endl;
        } else{
            cout << "Not a square matrix." << endl;
        }
    }

    void printDiagonalR(){
        if(LENY==LENX){
            cout << endl;
            for(int r=0;r<LENY;r++){
                for (int s=0;s<LENY-r-1;s++) {
                    cout << " ";
                }

                for(int c=0;c<LENX;c++){
                    if(r+c==LENY-1){
                        cout << arr[r][c];
                    }
                }
                cout << endl;
            }
            cout << endl;
        } else{
            cout << "Not a square matrix." << endl;
        }
    }

    void printAltIndex(){
        for(int r=0;r<LENY;r++){
            for(int c=0;c<LENX;c++){
                if((r+c)%2==0){
                    cout << arr[r][c] << " ";
                }
            }
        }
        cout << endl;
    }

    int sumUpArray(){
        int sum=0;
        for(int r=0;r<LENY;r++){
            for(int c=0;c<LENX;c++){
                sum+=arr[r][c];
            }
        }

        return sum;
    }
};