//
// https://www.spoj.com/problems/ARITH/
//

// input output
// http://contest.felk.cvut.cz/00cerc/solved/arith.in
// http://contest.felk.cvut.cz/00cerc/solved/arith.out
#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
const int ZERO_INT = 48;
const char ZERO_CHAR = '0';
const char STRING_END = '\0';
const char SPACE = ' ';
const char DASH = '-';
const char PLUS = '+';
const char MINUS = '-';
const char MULTI = '*';
const int QUESTION_LIMIT = 1002;
const int FIRST_LIMIT = 501;
const int SECOND_LIMIT = 501;


void splitToFirstSecondOp(char *twoNumbersAndOp,char *firstNumber,char *secondNumber,char *operator);

void plus(char *firstNumber,char *secondNumber,char operator);
void calculatePlusAnswer(char *answerPlus,char const *firstNumber, char const *secondNumber, int *leadingDigit, int answerCounter, int firstCounter, int secondCounter);
void printPlusAnswer(char *answerPlus,char const *firstNumber, char const *secondNumber,int leadingDigit,char operator);

void minus(char *firstNumber,char *secondNumber,char operator);
void calculateMinusAnswer(char *answerMinus,char const *secondNumber, int diff);
void printMinusAnswer(char *answerMinus,char *firstNumber, char *secondNumber,int diff, char operator);

int arith() {

    //should thos be a function?
    char testCaseString[6];//testcases is said to be 1000
    scanf("%s", testCaseString);
    long testCases = strtol(testCaseString,NULL,10);

    while (testCases--) {
        char twoNumbersAndOp[QUESTION_LIMIT];

        scanf("%s", twoNumbersAndOp);

        char firstNumber[FIRST_LIMIT];
        char secondNumber[SECOND_LIMIT];
        char operator = '.';

        splitToFirstSecondOp(&twoNumbersAndOp[0],&firstNumber[0],&secondNumber[0],&operator);

        switch(operator){
            case '+':
                plus(&firstNumber[0],&secondNumber[0],operator);
                break;
            case '-':
                minus(&firstNumber[0],&secondNumber[0],operator);
                break;
            case '*':
                //multi();
                break;
            default: break;
        }

        if (operator == '+') {


        } else if (operator == '-') {


        } else { // operator == *

            int lengthFirst = strlen(firstNumber);
            int lengthSecond = strlen(secondNumber);
            char answerMult[lengthSecond+1][lengthFirst +2]; // last is used for \0

            int memory = 0;

            int lastPlace = lengthFirst + lengthSecond ;

            //99999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999980000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001
            //99999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999980000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001
            char finalAnswer [lastPlace+1];

            finalAnswer[lastPlace] = '\0';

            for(int i =0; i<lastPlace;i++){
                finalAnswer[i]= '0';
            }

            for (int i = lengthSecond -1; i >= 0; i--) {

                int second = secondNumber[i];
                for (int j = lengthFirst-1; j >= 0; j--) {
                    int tempAnswer = (firstNumber[j] - ZERO_INT) * (second - ZERO_INT);
                    //printf("%d %d \n",(firstNumber[j] - ZERO_INT),(second - ZERO_INT));


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
                    answerMult[i][j+1] = tempAnswer % 10 + ZERO_INT;
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
                answerMult[i][0] = memory + ZERO_INT;
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

    return 0;
}

void splitToFirstSecondOp(char *twoNumbersAndOp,char *firstNumber,char *secondNumber,char *operator){

    int charFound = 0;
    int firstCounter = 0;
    int secondCounter = 0;
    for (int i = 0; i < strlen(twoNumbersAndOp); i++) {

        if ( twoNumbersAndOp[i] == PLUS || twoNumbersAndOp[i] == MINUS
            || twoNumbersAndOp[i] == MULTI) {
            *operator = twoNumbersAndOp[i];
            charFound = 1;
        } else {
            if (charFound) {
                secondNumber[secondCounter] = twoNumbersAndOp[i];
                (secondCounter)++;
            } else {
                firstNumber[firstCounter] = twoNumbersAndOp[i];
                (firstCounter)++;
            }

        }
    }

    firstNumber[firstCounter] = STRING_END;
    secondNumber[secondCounter] = STRING_END;
}

void plus(char *firstNumber,char *secondNumber,char operator){

    //setting up anserCounter and answerPlus
    int answerCounter = strlen(firstNumber) > strlen(secondNumber) ? (int) strlen(firstNumber) : (int) strlen(secondNumber);
    answerCounter++; // one for \0
    answerCounter++; // and one if its bigger eg 99+9 = 108
    char answerPlus[answerCounter];
    answerCounter--;
    answerPlus[answerCounter] = STRING_END;
    answerCounter--;
    //start with zero in the reminder
    answerPlus[answerCounter] = ZERO_CHAR;

    int firstCounter = (int) strlen(firstNumber) - 1;
    int secondCounter = (int) strlen(secondNumber) - 1;

    int leadingDigit = 1;

    calculatePlusAnswer(&answerPlus[0],&firstNumber[0], &secondNumber[0],
            &leadingDigit,answerCounter,firstCounter,secondCounter);

    printPlusAnswer(&answerPlus[0],&firstNumber[0], &secondNumber[0],leadingDigit,operator);

}

void calculatePlusAnswer(char *answerPlus,char const *firstNumber, char const *secondNumber, int *leadingDigit, int answerCounter, int firstCounter, int secondCounter){
    while (firstCounter >= 0 || secondCounter >= 0) {
        int first = ZERO_INT;
        if (firstCounter >= 0) {
            first = (firstNumber)[firstCounter];
            firstCounter--;
        }

        int second = ZERO_INT;
        if (secondCounter >= 0) {
            second = (secondNumber)[secondCounter];
            secondCounter--;
        }

        int tempAnswer = (first - ZERO_INT) + (second - ZERO_INT) + (answerPlus[answerCounter] - ZERO_INT);
        answerPlus[answerCounter] = (char) (tempAnswer % 10 + ZERO_INT);
        answerPlus[answerCounter - 1] = (char) (tempAnswer / 10 + ZERO_INT);
        *leadingDigit = tempAnswer / 10;
        answerCounter--;
    }
}

void printPlusAnswer(char *answerPlus,char const *firstNumber, char const *secondNumber,int leadingDigit,char operator){

        int nrOfdashes = 0;
    if ((strlen(answerPlus) - 1 + leadingDigit) > (strlen(secondNumber) + 1)) {
        nrOfdashes = (int) (strlen(answerPlus) - 1 + leadingDigit);
    } else {
        nrOfdashes =(int) (strlen(secondNumber) + 1);
    }

    char dashesArray[nrOfdashes + 1];
    for (int i = 0; i < nrOfdashes; i++) {
        dashesArray[i] = '-';
    }

    dashesArray[nrOfdashes] = '\0';

    int spacesFN = (int) (nrOfdashes - strlen(firstNumber)) ;
    while (spacesFN--) {
        printf(" ");
    }

    printf("%s\n", firstNumber);

    int spacesOSN = (int) (nrOfdashes - strlen(secondNumber) - 1);
    while (spacesOSN--) {
        printf(" ");
    }

    printf("%c%s\n", operator, secondNumber);


    printf("%s\n", dashesArray);

    int spacesANS = (int) (nrOfdashes - strlen(answerPlus) + 1 - leadingDigit);

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
}

void minus(char *firstNumber,char *secondNumber,char operator){
    char answerMinus[strlen(firstNumber) + 1];
    int firstCounter = (int) strlen(firstNumber) - 1;
    int secondCounter = (int) strlen(secondNumber) - 1;
    int answerCounter = firstCounter;

    for (int i = 0; i < strlen(firstNumber); i++) {
        answerMinus[i] = firstNumber[i];
    }
    answerMinus[answerCounter + 1] = '\0';

    int diff = firstCounter - secondCounter;
    calculateMinusAnswer(&answerMinus[0],&secondNumber[0],diff);

    printMinusAnswer(&answerMinus[0],&firstNumber[0],&secondNumber[0],diff,operator);
}

void calculateMinusAnswer(char *answerMinus,char const *secondNumber, int diff){
    for (int i = (int) strlen(answerMinus) - 1; i >= 0; i--) {
        if (i - diff >= 0) {
            answerMinus[i] -= (secondNumber[i - diff] - ZERO_INT);

            if (answerMinus[i] < ZERO_INT) {
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
}
//should I create printFirst, print opSecond, printAnswer?
void printMinusAnswer(char *answerMinus,char *firstNumber, char *secondNumber,int diff,char operator){
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

    int answerLength =(int) strlen(answerMinus);

    int minusAnswerLeadingZeros = 1;
    for(int i = 0; i< strlen(answerMinus);i++ ){
        if (answerMinus[i] == '0'){
            answerLength--;

        }
        else{
            minusAnswerLeadingZeros = 0;
            break;
        }
    }

    if(minusAnswerLeadingZeros){ //only zeros
        answerLength++;
    }

    int lengthMinus =
            answerLength > (strlen(secondNumber) + 1) ? answerLength : (int) (strlen(secondNumber) + 1);
    int diff2 = (int) (lengthMinus - strlen(answerMinus)) ;

    int spaceDashes = (int) (strlen(firstNumber)- lengthMinus);
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
}