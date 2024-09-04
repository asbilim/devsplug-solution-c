#include <stdio.h>
#include <stdlib.h>
#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

/*
 Problem statement: Given an array of integers and a number k, 
 representing the size of the sliding window, return an array of the maximum values 
 of each window as the window slides from left to right across the original array.
 Each window shifts one element to the right in subsequent steps.
*/


int max_value(int* array,int array_size){

    /*
        getting the size of the array
        and returning the highest value of an array
    */

    int max_val = array[0];

    for (int i=1;i<array_size;i++){
        if(array[i] > max_val){
            max_val = array[i];
        }
    }

    return max_val;

}


int* sliding_window(int* array,int size,int k,int* result_array_size){

    int* default_array = malloc(sizeof(int));

    if(k >= size) {
        if(default_array == NULL){
            return NULL;
        }
        default_array[0] = max_value(array,size);
        return default_array;
    }

    int remaining = size % k;
    int times = (size -remaining) / k;

    int* result = malloc(times +(remaining!=0) * sizeof(int));

    for(int i=0;i<times;i++){
        int max_val = array[0];
        int rythm = i*k; 
        /*
            this way , we can make a subsliding function , 
            for example for times = 0, we start at 1 , then for 2 , 5 etc... if k=5
        */
        for(int j=0;j<k;j++){
            if(max_val < array[rythm+j] ){
                max_val = array[rythm+j];
            }
        }

        result[i] = max_val;
    }

    if(remaining !=0){
        *result_array_size = times+1;
        int max_val = array[k+times];
        for(int i=k*times;i<size;i++){
            if(max_val < array[i]){
                max_val = array[i];
            }
        }
        result[times] = max_val;
    }else{
        *result_array_size = times;
    }
    return result;

}



int main(){

    int my_array[5] = {0,1,2,3,4};
    int result_size = 0;
    int* test = sliding_window(my_array,5,4,&result_size);
    
    for(int i=0;i<result_size;i++){
        printf("maximums are %d\n",test[i]);
    }
    return 0;
}