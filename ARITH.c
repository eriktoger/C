//
// https://www.spoj.com/problems/ARITH/
//

// input output
// http://contest.felk.cvut.cz/00cerc/solved/arith.in
// http://contest.felk.cvut.cz/00cerc/solved/arith.out

#include <memory.h>
#include <stdlib.h>
const int ZERO_CHAR = 48;
void arith() {
    int testCases;
    scanf("%d", &testCases);

    while (testCases--) {
        char twoNumbersAndOp[1002];

        scanf("%s", twoNumbersAndOp);

        char firstNumber[501];
        int firstCounter = 0;
        char secondNumber[501];
        int secondCounter = 0;
        char operator = '.';
        int charFound = 0;

        for (int i = 0; i < strlen(twoNumbersAndOp); i++) {

            if (twoNumbersAndOp[i] == '+' || twoNumbersAndOp[i] == '-'
                || twoNumbersAndOp[i] == '*') {
                operator = twoNumbersAndOp[i];
                charFound = 1;
            } else {
                if (charFound) {
                    secondNumber[secondCounter] = twoNumbersAndOp[i];
                    secondCounter++;
                } else {
                    firstNumber[firstCounter] = twoNumbersAndOp[i];
                    firstCounter++;
                }

            }
        }

        firstNumber[firstCounter] = '\0';
        secondNumber[secondCounter] = '\0';

        //printf("%s\n", firstNumber);
        //printf("%c\n", operator);
        //printf("%s\n", secondNumber);

        if (operator == '+') {
            //printf("inside +\n");
            // Do I want this as char or int?
            //maybe I want to do the conversion earlier?


            // -1 is beacuse second number has the operator
            // this does not work when answer i longer
            int spaces = abs(strlen(firstNumber) - strlen(secondNumber) - 1);
            int answerCounter = strlen(firstNumber) > strlen(secondNumber) ? strlen(firstNumber) : strlen(secondNumber);
            //printf("%d %d \n", strlen(firstNumber), strlen(secondNumber));
            answerCounter++; // one for \0
            answerCounter++; // and one if its bigger eg 99+9 = 108
            char answerPlus[answerCounter];
            answerCounter--;
            answerPlus[answerCounter] = '\0';
            answerCounter--;
            //start with zero in the reminder
            answerPlus[answerCounter] = '0';

            firstCounter = (int) strlen(firstNumber) - 1;
            secondCounter = (int) strlen(secondNumber) - 1;

            int leadingDigit = 1;

            while (firstCounter >= 0 || secondCounter >= 0) {
                int first = ZERO_CHAR;
                if (firstCounter >= 0) {
                    first = firstNumber[firstCounter];
                    firstCounter--;

                }

                int second = ZERO_CHAR;
                if (secondCounter >= 0) {
                    second = secondNumber[secondCounter];
                    secondCounter--;
                }

                int tempAnswer = (first - ZERO_CHAR) + (second - ZERO_CHAR) + (answerPlus[answerCounter] - ZERO_CHAR);
                answerPlus[answerCounter] = (char) tempAnswer % 10 + ZERO_CHAR;
                answerPlus[answerCounter - 1] = (char) tempAnswer / 10 + ZERO_CHAR;
                //printf("hello? %d %s \n", tempAnswer, answerPlus);
                leadingDigit = tempAnswer / 10;
                answerCounter--;
            }


            //printf("goodbye!\n\n");
            //printf("hello again");
            //printf("answerPlus: %d", leadingDigit);
            // either answer or op+second i largest.
            // --- should be the same length
            // everything should be right alligned.

            int nrOfdashes = 0;

            if ((strlen(answerPlus) - 1 + leadingDigit) > (strlen(secondNumber) + 1)) {
                nrOfdashes = (strlen(answerPlus) - 1 + leadingDigit);
            } else {
                nrOfdashes = (strlen(secondNumber) + 1);
            }

            char dashesArray[nrOfdashes + 1];
            for (int i = 0; i < nrOfdashes; i++) {
                dashesArray[i] = '-';
            }

            dashesArray[nrOfdashes] = '\0';

            //printf("\nhere should answer be\n");

            int spacesFN = nrOfdashes - strlen(firstNumber);
            while (spacesFN--) {
                printf(" ");
            }

            printf("%s\n", firstNumber);

            int spacesOSN = nrOfdashes - strlen(secondNumber) - 1;
            while (spacesOSN--) {
                printf(" ");
            }

            printf("%c%s\n", operator, secondNumber);


            printf("%s\n", dashesArray);

            int spacesANS = nrOfdashes - strlen(answerPlus) + 1 - leadingDigit;

            while (spacesANS--) {
                printf(" ");
            }
            int i = 0;
            if (answerPlus[0] == '0') {
                i = 1;
            }
            for (; i < strlen(answerPlus); i++) {
                printf("%c", answerPlus[i]);
            }
            printf("\n");


        } else if (operator == '-') {


            // wrong! RIGHT!
            //15455872411634497535421977825106651239480644084748380588260881446569518572081466204353180168303969921-7890872338633996076234547417439118295439292682289813367119952873793237266424653
            //5395008685556578489773806509669208819687232989738715196756623-64342539302731639
            char answerMinus[strlen(firstNumber) + 1];
            firstCounter = (int) strlen(firstNumber) - 1;
            secondCounter = (int) strlen(secondNumber) - 1;
            int answerCounter = firstCounter;

            for (int i = 0; i < strlen(firstNumber); i++) {
                answerMinus[i] = firstNumber[i];
            }
            answerMinus[answerCounter + 1] = '\0';
            //printf("%s\n",answerMinus);

            int diff = firstCounter - secondCounter;

            for (int i = (int) strlen(answerMinus) - 1; i >= 0; i--) {

                answerMinus[i];

                if (i - diff >= 0) {
                    //printf("i: %d  %d %c\n",i,secondNumber[i-diff],secondNumber[i-diff]);
                    answerMinus[i] -= (secondNumber[i - diff] - ZERO_CHAR);
                    //printf("%d\n",answerMinus[i]);

                    if (answerMinus[i] < ZERO_CHAR) {
                        answerMinus[i] += 10;
                        int back = 0;
                        while (1) {
                            answerMinus[i - 1 - back] -= 1;
                            if (answerMinus[i - 1 - back] == '/') {
                                answerMinus[i - 1 - back] = '9';
                                back++;
                            } else {
                                break;
                            }
                        }
                    }


                }


            }

            //printf("\nhere should answer be\n");

            // first can only be one less
            if (strlen(firstNumber) == strlen(secondNumber)) {
                printf(" ");
            }

            printf("%s\n", firstNumber);

            diff--;
            while (diff-- > 0) {
                printf(" ");

            }
            printf("%c%s\n", operator, secondNumber);

            int answerLength = strlen(answerMinus);
            //printf("answerL %d\n",answerLength);
            int minusAnswerLeadingZeros = 1;
            for(int i = 0; i< strlen(answerMinus);i++ ){
                if(minusAnswerLeadingZeros){
                    if (answerMinus[i] == '0'){
                        answerLength--;

                    }
                    else{
                        minusAnswerLeadingZeros = 0;
                        break;
                    }
                }
            }
            //printf("answerL %d\n",answerLength);

            if(minusAnswerLeadingZeros){ //only zeros
                answerLength++;
            }

            //printf("answerL %d\n",answerLength);
            int lengthMinus =
                    answerLength > (strlen(secondNumber) + 1) ? answerLength : strlen(secondNumber) + 1;
            //printf("lengthMinus %d\n",lengthMinus);
            int diff2 = lengthMinus - strlen(answerMinus);

            int spaceDashes = strlen(firstNumber)- lengthMinus;
            while(spaceDashes-->0){
                printf(" ");
            }

            while (lengthMinus-->0) {
                printf("-");
            }
            printf("\n");

            //printf("diff2:  %d ",diff2);
            while (diff2-- > 0) {
                printf(" ");
            }

            int nonZero = 0;
            for (int i = 0; i < strlen(answerMinus); i++) {
                if (!nonZero) {
                    if (answerMinus[i] != '0') {
                        nonZero = 1;
                    } else {
                        printf(" ");
                    }

                }
                if (nonZero || i == (strlen(answerMinus) - 1)) {
                    printf("%c", answerMinus[i]);
                }

            }
            printf("\n");


        } else { // operator == *

            int lengthFirst = strlen(firstNumber);
            int lengthSecond = strlen(secondNumber);
            char answerMult[lengthSecond+1][lengthFirst +2]; // last is used for \0

            int memory = 0;

            int lastPlace = 80;
            char finalAnswer [lastPlace+1];

            finalAnswer[lastPlace] = '\0';

            for(int i =0; i<lastPlace;i++){
                finalAnswer[i]= '0';
            }

            for (int i = lengthSecond -1; i >= 0; i--) {

                int second = secondNumber[i];
                for (int j = lengthFirst-1; j >= 0; j--) {
                    int tempAnswer = (firstNumber[j] - ZERO_CHAR) * (second - ZERO_CHAR);
                    //printf("%d %d \n",(firstNumber[j] - ZERO_CHAR),(second - ZERO_CHAR));


                    // I handle memory twice )=
                    int index = lastPlace-1- lengthSecond+1 - lengthFirst+1+i+j;
                    //printf("index %d\n", index);
                    finalAnswer[index] +=tempAnswer % 10;
                    if(finalAnswer[index] >'9' ){
                        finalAnswer[index]-= 10;
                        finalAnswer[index-1] +=1;
                    }
                    finalAnswer[index-1] += tempAnswer /10;
                    int back = 1;
                    while(finalAnswer[index-back] >'9' ){
                        finalAnswer[index-back]-= 10;
                        finalAnswer[index-back-1] +=1;
                        back++;
                    }

                    tempAnswer += memory;
                    answerMult[i][j+1] = tempAnswer % 10 + ZERO_CHAR;
                    memory = tempAnswer / 10;
                    //printf("%d\n",tempAnswer);

                    //printf("%s\n",finalAnswer);
                    //4333*54344
                    //235472552
                    //247694762

                    //865626972066137*932325227571703589052759056660
                    //807045863723765884249181930731354559250322420

                    //86128360238355429915477315*619897519346469395847838386028680569
                    //53390756857135620581930758802845864836821837523429101300792235

                    //43171474259419373361224801864268585722148180*1274546860662536794379192230320448893
                    //55024066987516477905176240509111638094896888379559369190611653313979389862964740

                }
                answerMult[i][lengthFirst+1] ='\0';
                answerMult[i][0] = memory + ZERO_CHAR;
                memory =0;
            }

            int leadingZeros = 0;
            for(int i =0; i< strlen(finalAnswer)-1; i++ ){
                if(finalAnswer[i] == '0'){
                    leadingZeros++;
                }
                else{
                    break;
                }
            }

            // all singular line up, and tenth and so on.
            //size-1 is the place of singular?

            int size = strlen(finalAnswer) - leadingZeros;
            if(size < strlen(secondNumber)+1){
                size = strlen(secondNumber)+1;
            }

            //printf("%d  %s",size, answerMult[0]);


            //printf("answer start\n\n %s \n %s\n", answerMult[0], answerMult[lengthSecond-1]);

            //the first row under the dashes
            int spaceFirstRow = size - strlen(answerMult[lengthSecond-1]);
            //checking leading zeros.
            int firstRowLeadingZeros = 1;
            int lengthFirstRow = 0;
            for(int i = 0;i<strlen(answerMult[lengthSecond-1]);i++){
                if(firstRowLeadingZeros){
                    if(answerMult[lengthSecond-1][i] == '0'){
                        spaceFirstRow++;
                    }
                    else{
                        firstRowLeadingZeros = 0;
                        lengthFirstRow++;
                    }
                }
                else{
                    lengthFirstRow++;
                }
            }

            //if all zeroes we still should print one zero
            if(firstRowLeadingZeros){
                spaceFirstRow--;
                lengthFirstRow++;
            }

            int spaceSecondNumber = size - strlen(secondNumber)-1;
            int spaceDashes;
            int dashes;
            //this is not correct, it is also deteremend by first row under -----
            if(lengthFirstRow > strlen(secondNumber) +1){
                spaceDashes = spaceFirstRow;
                dashes = lengthFirstRow;

            }else{
                spaceDashes = spaceSecondNumber;
                dashes = strlen(secondNumber)+1;
            }

            int spaceFirstNumber = size - strlen(firstNumber);;
            while(spaceFirstNumber-- > 0){
                printf(" ");
            }
            printf("%s\n",firstNumber);


            while(spaceSecondNumber-- >0){
                printf(" ");
            }
            printf("%c%s\n",operator,secondNumber);

            while(spaceDashes-- >0){
                printf(" ");
            }
            while(dashes--){
                printf("-");
            }
            printf("\n");

            //printf("%d\n",size);
            int sizeForAnswer = size;
            for (int i = lengthSecond-1; i >= 0; i--) {
                int tempSize = size;
                tempSize-= strlen(answerMult[i]);
                int onlyZeros = 1;
                for(int k = 0; k<strlen(answerMult[i]);k++){
                    if(answerMult[i][k] == '0'){
                        tempSize++;
                    }
                    else{
                        onlyZeros =0;
                        break;
                    }
                }
                if(onlyZeros){ // leaves room for 0
                    tempSize--;
                }
                //printf("%d %d\n", size, tempSize);
                //printf("%s\n",answerMult[i]);
                while(tempSize-- > 0){
                    printf(" ");
                }
                size--;

                int ignoreZero = 1;
                for (int j = 0; j < lengthFirst+1; j++) {

                    if(ignoreZero){
                        if(answerMult[i][j] != '0'){
                            ignoreZero = 0;
                            printf("%c", answerMult[i][j]);
                        }
                        else{
                            //the && i!=0 is to fix the last one in:
                            //43171474259419373361224801864268585722148180*1274546860662536794379192230320448893
                            //55024066987516477905176240509111638094896888379559369190611653313979389862964740
                            if(j!=lengthFirst && i!=0 ){
                                //printf(" ");
                            }

                        }
                    } else {
                        printf("%c", answerMult[i][j]);
                    }

                    //printf("%c", answerMult[i][j]);

                }

                if(ignoreZero){ // all zeros
                    printf("0");
                }
                printf("\n");
            }

            //if second number only is 1 digit answer is dublicate
            if(strlen(secondNumber)>1){
                sizeForAnswer-=(strlen(finalAnswer) - leadingZeros);
                int sizeForAnswersSpaces = sizeForAnswer;
                while(sizeForAnswersSpaces-->0){
                    printf(" ");
                }

                for(int i=leadingZeros;i < strlen(finalAnswer);i++ ){
                    printf("-");
                }
                printf("\n");

                while(sizeForAnswer-->0){
                    printf(" ");
                }

                for(int i=leadingZeros;i < strlen(finalAnswer);i++ ){
                    printf("%c",finalAnswer[i]);
                }
                printf("\n");
            }



        }

    }
}