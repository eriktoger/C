//
// https://www.spoj.com/problems/ONP/

// it is just a code from the pseudo-code from:
// https://brilliant.org/wiki/shunting-yard-algorithm/

#include <ctype.h>
#include <string.h>
#include <stdio.h>
int hasGreaterPrecedence(char current, char onStack);
void onp(){
    int testCases;
    scanf ("%d",&testCases);

    while(testCases--){
        char expression[401];
        char stack[401];
        int stackPointer = 0;

        scanf("%s", expression);

        int length = (int) strlen(expression) ;

        for(int i =0; i < length; i++){

            if( isalpha(expression[i])  ){
                printf("%c",expression[i]);
            }

            else if ( !(expression[i] == '(' || expression[i] == ')') ){
                // While there's an operator on the top of the stack with greater precedence:
                while(1){
                    //Pop operators from the stack onto the output queue
                    if(stackPointer > 0){
                        if (hasGreaterPrecedence(expression[i],
                                stack[stackPointer-1] ) ) {
                            printf("%c", stack[stackPointer-1]);
                            stackPointer--;
                        }
                        else{
                            break;
                        }
                    }
                    else{
                        break;
                    }
                }

                stack[stackPointer] = expression[i];
                stackPointer++;

            }
            else{ // must be ( or )
                if (expression[i] == '('){
                    stack[stackPointer] = expression[i];
                    stackPointer++;
                }
                else{
                    while(1){
                        if(stack[stackPointer-1] == '(' ){
                            stackPointer--;
                            break;
                        }
                        else{
                            printf("%c",stack[stackPointer-1] );
                            stackPointer--;
                        }
                    }
                }
            }

        }

        while(stackPointer > 0){
            printf("%c",stack[stackPointer]);
            stackPointer--;
        }
        printf("\n");

    }
}

int hasGreaterPrecedence(char current, char onStack){

    if(current == '+' || current == '-' ) {
        if (onStack == '+' || onStack == '-' || onStack == '('){
            return 0;
        }
        else {
            return 1;
        }
    }

    if(current == '/' || current == '*'){
        if(onStack == '+' || onStack == '-'){
            return 1;
        }
        else{
            return 0;
        }

    }

    if(current == '^'){
        if(onStack == '(' || onStack == '^'){
            return 0;
        }
        else{
            return 1;
        }
    }


    return 0;
}