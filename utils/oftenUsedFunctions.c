//
// Created by erik on 2019-07-16.
//
#include "oftenUsedFunctions.h"

void quickSort(char *word,int low,int high){

    if(low<high){

        int part = partition(word,low,high);

        quickSort(word,low,part-1);
        quickSort(word,part+1,high);
    }
}

int partition(char *word,int low,int high){

    int j =low;
    for(;j<high;j++){

        if(word[j]<word[high]){
            swap(&word[low],&word[j]);
            low++;
        }
    }

    swap(&word[low],&word[high]);
    return low;
}

void swap(char *a,char *b){
    char temp = *a;
    *a = *b;
    *b = temp;
}