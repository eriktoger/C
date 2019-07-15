//
// Created by erik on 2019-07-15.
//

#include <memory.h>

//using quickSort

void quickSort(char *word,int low,int high);
int partition(char *word,int low,int high);
void swap(char *a,char *b);

void checkPermutation1(){
    char word1[500];
    printf("Enter word 1:\n");
    scanf("%s",word1);

    char word2[500];
    printf("Enter word 2:\n");
    scanf("%s",word2);

    int isPermutation = 1;
    if(strlen(word1) == strlen(word2) ){
        quickSort(word1,0,strlen(word1)-1);
        quickSort(word2,0,strlen(word1)-1);
        printf("word1: %s\n",word1);
        printf("word2: %s\n",word2);
        for(int i =0;i<strlen(word1);i++){
            if(word1[i] != word2[i]){
                isPermutation =0;
                break;
            }
        }

    }else{
        isPermutation = 0;
    }

    if(isPermutation){
        printf("They are permutations!");
    }
    else{
        printf("They are not permutations!");
    }


}

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


//counting chars
void checkPermutation2(){

    char count[128] ={0};
    char word1[500];
    printf("Enter word 1:\n");
    scanf("%s",word1);

    char word2[500];
    printf("Enter word 2:\n");
    scanf("%s",word2);
    int isPermutation = 1;
    if(strlen(word1) != strlen(word2)){
        isPermutation =0;
    } else{
        for(int i =0; i<strlen(word1);i++){
            count[word1[i]]++;
        }


        for(int i =0; i<strlen(word2);i++){
            count[word2[i]]--;
            if(count[word2[i]]<0){
                isPermutation =0;
                break;
            }
        }

    }


    if(isPermutation){
        printf("Is permutation!");
    }else{
        printf("Is not permutation!");
    }


}