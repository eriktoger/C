//
// https://www.spoj.com/problems/STRHH/
//
#include <string.h>
#include <stdio.h>
void strhh(){

    int testCases;
    scanf ("%d",&testCases);

    while(testCases--){
        char word[200];
        scanf("%s",word);
        //printf("Your string: %s\n", word);
        unsigned len = strlen(word) / 2;
        //printf("Your string: %s\n", word);
        for(int i = 0; i <len; i=i+2 ){
            printf("%c",word[i]);
        }
        printf("\n");
    }

}