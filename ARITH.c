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



            /*
            while( strlen(firstNumber) < nrOfdashes ){
                firstNumber[strlen(firstNumber)] = ' ';
            }

            while(strlen(secondNumber) < nrOfdashes ){
                firstNumber[strlen(secondNumber)] = ' ';
            }

            while(strlen(answerPlus) < nrOfdashes ){
                firstNumber[strlen(answerPlus)] = ' ';
            }

           printf("here should answer be\n");
           printf("%s\n",firstNumber);
           printf("%c%s\n",operator,secondNumber);
           printf("%s\n",dashesArray);
           printf("%s\n",answerPlus);
            */

        }
        else if(operator == '-' ){
            char answerMinus[502];
        }
        else{ // operator == *


            char answerMult[1001];

        }


    }
}