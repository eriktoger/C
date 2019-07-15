//
// Is Unique: Implement an algorithm to determine if a string has all unique charachters.
// What if you cannot use additional data structures?

#include <memory.h>

//with extra data stuctures
void isUnique1(){

    // can we do it in one pass?
    // asume ascii with 128 chars.
    char word[128];
    char unique[128] = {0};
    char isUnique = 1;
    scanf("%s",word);

    for(int i =0; i<strlen(word); i++){
        if(unique[word[i] ]){
            isUnique = 0;
            break;
        }
        else{
            unique[ word[i] ] =1;
        }
    }

    if(isUnique){
        printf("\nis unqiue!");
    }else{
        printf("\nis not unqiue");
    }

}

// with out extra data structures
//quicksort!

void quicksort(char *word, int low, int high);
int parition(char *word, int low, int high);
void swap ( char *a, char *b);

void isUnique2(){
    char word[128];
    scanf("%s",word);

    quicksort(word,0,strlen(word)-1);
    //printf("\n%s\n",word);
    char last = word[0];
    int isUnique =1;

    for(int i =1;i< strlen(word); i++){
        if(last == word[i]){
            isUnique =0;
            break;
        }
        last = word[i];
    }

    if(isUnique){
        printf("\nis unqiue!");
    }else{
        printf("\nis not unqiue");
    }

}

void quicksort(char *word, int low, int high){

    if(low < high){
        int part= parition(word,low,high);

        quicksort(word,low,part-1);
        quicksort(word,part+1,high);
    }
}

int parition(char *word, int low, int high){

    int pivot = word[high];
    int i = low;

    for(int j = low; j < high;j++ ){
        if(word[j] <= pivot ){

            swap(&word[i],&word[j]);
            i++;
        }
    }

    swap(&word[i],&word[high]);
    return i;
}

void swap ( char *a, char *b){
    char temp = *a;
    *a = *b;
    *b = temp;
}

