//
// https://www.spoj.com/problems/ARITH/
//

// input output
// http://contest.felk.cvut.cz/00cerc/solved/arith.in
// http://contest.felk.cvut.cz/00cerc/solved/arith.out

#include <memory.h>
#include <stdlib.h>
const int ZERO_CHAR = 48;
void arith(){
    int testCases;
    scanf ("%d",&testCases);

    while(testCases--){
        char twoNumbersAndOp[1002];

        scanf("%s",twoNumbersAndOp);

        char firstNumber[501];
        int firstCounter = 0;
        char secondNumber[501];
        int secondCounter = 0;
        char operator = '.';
        int charFound = 0;

        for(int i =0; i< strlen(twoNumbersAndOp); i++){

            if(twoNumbersAndOp[i] =='+' ||twoNumbersAndOp[i] =='-'
                || twoNumbersAndOp[i] =='*' ){
                operator = twoNumbersAndOp[i];
                charFound = 1;
            }
            else{
                if(charFound){
                    secondNumber[secondCounter] = twoNumbersAndOp[i];
                    secondCounter++;
                }
                else{
                  firstNumber[firstCounter] = twoNumbersAndOp[i];
                  firstCounter++;
                }

            }
        }

        firstNumber[firstCounter] = '\0';
        secondNumber[secondCounter] = '\0';

        printf("%s\n",firstNumber);
        printf("%c\n",operator);
        printf("%s\n",secondNumber);

        if(operator == '+'){
            printf("inside +\n");
            // Do I want this as char or int?
            //maybe I want to do the conversion earlier?


            // -1 is beacuse second number has the operator
            // this does not work when answer i longer
            int spaces = abs( strlen(firstNumber) - strlen(secondNumber) -1);
            int answerCounter = strlen(firstNumber) > strlen(secondNumber) ? strlen(firstNumber) : strlen(secondNumber);
            printf("%d %d \n",strlen(firstNumber),strlen(secondNumber) );
            answerCounter++; // one for \0
            answerCounter++; // and one if its bigger eg 99+9 = 108
            char answerPlus[answerCounter];
            answerCounter--;
            answerPlus[answerCounter] = '\0';
            answerCounter--;
            //start with zero in the reminder
            answerPlus[answerCounter] = '0';

            firstCounter = (int) strlen(firstNumber) -1;
            secondCounter = (int) strlen(secondNumber)-1;

            int leadingDigit = 1;

            while(firstCounter>= 0 || secondCounter >= 0){
                int first = ZERO_CHAR;
                if(firstCounter >=0){
                    first = firstNumber[firstCounter];
                    firstCounter--;

                }

                int second = ZERO_CHAR;
                if(secondCounter >=0){
                    second = secondNumber[secondCounter];
                    secondCounter--;
                }

                int tempAnswer = ( first -ZERO_CHAR) + (second -ZERO_CHAR) + (answerPlus[answerCounter]- ZERO_CHAR);
                answerPlus[answerCounter] = (char) tempAnswer %10 + ZERO_CHAR;
                answerPlus[answerCounter-1] = (char) tempAnswer /10 + ZERO_CHAR;
                printf("hello? %d %s \n",tempAnswer,answerPlus);
                leadingDigit = tempAnswer /10;
                answerCounter--;
            }


            printf("goodbye!\n\n");
            printf("hello again");
            printf("answerPlus: %d", leadingDigit);
            // either answer or op+second i largest.
            // --- should be the same length
            // everything should be right alligned.

            int nrOfdashes = 0;

            if( (strlen(answerPlus) - 1 + leadingDigit) > (strlen(secondNumber) +1) ){
                nrOfdashes = (strlen(answerPlus) -1 + leadingDigit);
            }
            else{
                nrOfdashes = (strlen(secondNumber) +1);
            }

            char dashesArray[nrOfdashes+1];
            for(int i = 0; i< nrOfdashes;i++){
                dashesArray[i] = '-';
            }

            dashesArray[nrOfdashes] = '\0';

            printf("\nhere should answer be\n");

            int spacesFN = nrOfdashes - strlen(firstNumber);
            while(spacesFN--){
                printf(" ");
            }

            printf("%s\n",firstNumber);

            int spacesOSN = nrOfdashes - strlen(secondNumber) -1;
            while(spacesOSN--){
                printf(" ");
            }

            printf("%c%s\n",operator,secondNumber);


            printf("%s\n",dashesArray);

            int spacesANS = nrOfdashes - strlen(answerPlus) + 1 - leadingDigit;

            while(spacesANS--){
                printf(" ");
            }
            int i =0;
            if(answerPlus[0] == '0'){
                i =1;
            }
            for(; i< strlen(answerPlus);i++){
                printf("%c",answerPlus[i]);
            }
            printf("\n");


        }
        else if(operator == '-' ){
            char answerMinus[strlen(firstNumber)+1];
            firstCounter = (int) strlen(firstNumber) - 1;
            secondCounter = (int) strlen(secondNumber) - 1;
            int answerCounter = firstCounter;

            for(int i =0; i< strlen(answerMinus);i++){
                answerMinus[i] = firstNumber[i];
            }
            answerMinus[answerCounter + 1] = '\0';


            int diff = firstCounter- secondCounter;


            for(int i = (int) strlen(answerMinus)-1; i>=0;i--){

                answerMinus[i];

                if(i-diff >=0) {
                    printf("i: %d  %d %c\n",i,secondNumber[i-diff],secondNumber[i-diff]);
                    answerMinus[i] -= (secondNumber[i-diff] - ZERO_CHAR);
                    printf("%d\n",answerMinus[i]);

                   if(answerMinus[i] <  ZERO_CHAR){
                       answerMinus[i] += 10;
                       int back = 0;
                       while(1){
                           answerMinus[i-1-back]-=1;
                           if(answerMinus[i-1-back] == '/'){
                               answerMinus[i-1-back] = '9';
                               back++;
                           }
                           else {
                               break;
                           }


                       }
                   }


                }


            }

            printf("\nhere should answer be\n");

            // first can only be one less
            if(strlen(firstNumber) == strlen(secondNumber)){
                printf(" ");
            }

            printf("%s\n",firstNumber);

            diff--;
            while(diff-- >0){
                printf(" ");

            }
            printf("%c%s\n",operator,secondNumber);
            int lengthMinus = strlen(firstNumber) > strlen(secondNumber) + 1 ? strlen(firstNumber) : strlen(secondNumber) + 1;
            while(lengthMinus--){
                printf("-");
            }
            printf("\n");
            //printf("%s\n",answerMinus);

            int nonZero =0;
            for(int i= 0; i< strlen(answerMinus);i++){
                if(!nonZero){
                    if(answerMinus[i]!= '0'){
                        nonZero = 1;
                    }
                    else{
                        printf(" ");
                    }

                }
                if(nonZero){
                    printf("%c",answerMinus[i]);
                }

            }


        }
        else{ // operator == *


            char answerMult[1001];

        }


    }
}