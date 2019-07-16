//
// Created by erik on 2019-07-15.
//

#include <memory.h>
#include <stdio.h>
#include "../utils/oftenUsedFunctions.h"
//using quickSort

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