#include<iostream>
using namespace std;

int merge(int *arr, int s, int e){
    int mid = s+ (e-s)/2;
    int len1 = mid-s+1;
    int len2 = e-mid;
    int ic = 0;
    int *f = new int[len1];
    int *se = new int[len2];
      
    //copy values
    int mainArrayIndex = s;
    for(int i = 0; i<len1; i++){
        f[i] = arr[mainArrayIndex++];
    } 

    mainArrayIndex = mid+1;
     for(int i = 0; i<len2; i++){
        se[i] = arr[mainArrayIndex++];
    } 

    //merge 2 arrays
    int i1 =0;
    int i2 =0;
    mainArrayIndex = s;

    while( i1 < len1 && i2 < len2 ){
        if(f[i1] < se[i2]){
            arr[mainArrayIndex++] = f[i1++];
        }
        else{
             arr[mainArrayIndex++] = se[i2++];
             ic+=mid-i1+1;
        }
    }
     while( i1 < len1){
        arr[mainArrayIndex++] = f[i1++];
     }
     while( i2 < len2){
         arr[mainArrayIndex++] = se[i2++];
     }
return ic;
     delete []f;
     delete []se;

}

int mergeSort(int *arr, int s, int e){
//base case
int ic = 0;
if( s >= e){
    return 0;
}

int mid = s+ (e-s)/2;

//recrusion
ic+= mergeSort(arr, s, mid);
ic+=mergeSort(arr, mid+1, e);

ic+=merge(arr, s, e);
return ic;
}


int main(){
    int arr[5]= {1, 20, 6, 4, 5 };
    int n = 5;

   int ans= mergeSort(arr, 0, n-1);
   cout << ans;

    
}