//
// https://www.spoj.com/problems/FCTRL
//
#include <memory.h>

// I needed  to trim off all comments to get under 2000 bytes for the problem
void fctrl2(){

    int testCases;
    const int DIGITS = 162; // only 158 digits in 100! but j+1 <= 4
    scanf ("%d",&testCases);

    while(testCases--){

        int answer[DIGITS];
        memset( answer, 0, DIGITS*sizeof(int) );
        int temp1[DIGITS];
        memset( temp1, 0, DIGITS*sizeof(int) );
        int temp2[DIGITS];
        memset( temp2, 0, DIGITS*sizeof(int) );

        int fact;
        scanf("%d",&fact);
        int nextNumber = fact -1;

        int index = 0;
        while(fact > 0){
            answer[index] = fact % 10;
            fact/=10;
            index++;
        }

        while(nextNumber > 1){
            for(int i = 0; i < DIGITS; i++){
                temp1[i] = answer[i];
                answer[i]= 0;
                temp2[i] = 0;
            }

            fact = nextNumber;
            index =0;

            while(fact > 0){
                temp2[index] = fact % 10;
                fact/=10;
                index++;
            }

            // uses long division with reminder and saves to answer
            //answer[i+j] is the reminder and answer[i+j+1] becomes the new one
            for(int i=0; i < (DIGITS-4);i++){
                for(int j=0; j < index; j++ ){
                    int partOfAnswer = temp1[i] * temp2[j] + answer[i+j];
                    answer[i+j] = partOfAnswer%10 ;
                    answer[i+j+1] += partOfAnswer/10;
                }
            }

            nextNumber--;
        }

        // printing the number but not leading 0s
        int firstNonZero =0;
        for(int i = (DIGITS-1);i >= 0;i--){

            if(!firstNonZero){
                if(answer[i] != 0){
                    firstNonZero = 1;
                }
            }
            if(firstNonZero){
                printf("%d",answer[i]);
            }
        }
        if(testCases >0)
        printf( "\n");
    }
}