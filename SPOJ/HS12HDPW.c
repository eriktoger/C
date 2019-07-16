//
// https://www.spoj.com/problems/HS12HDPW/
// but i should also solve it with shifting?

#include <string.h>
#include <stdio.h>
//qwe345 rf3Arg
//XSBSRasdew9873465hkldsfsalndfvnfq489uqovkLKJHaeDaae555Sk5asdpASD
void decToBinary(int n,int *binary);
void decoding (int *code, int *codeCounter);

void hs12hdpw(){

    int testCases;
    scanf ("%d",&testCases);

    while(testCases--){
        int code[200];
        int codeCounter = 0;
        int nrOfTuples;
        scanf ("%d",&nrOfTuples);

        while(nrOfTuples--){
            decoding(code, &codeCounter);
        }

        char word[65];
        scanf("%s",&word);

        int newCodeCounter = 0;
        while(newCodeCounter < codeCounter){
            printf("%c",word[code[newCodeCounter]]);
            newCodeCounter++;
        }
        printf("\n");

    }
}

void decToBinary(int n,int *binary)
{
    // array to store binary number
    for(int i =0; i < 7;i++){
        binary[i] =0;
    }

    // counter for binary array
    int i = 6;

    while (n > 0) {
        // storing remainder in binary array
        binary[i] = n % 2;
        n = n / 2;
        i--;
    }

}

void decoding (int *code,int *codeCounter){
    int binary[7];
    char tuple[20];
    scanf("%s",&tuple);

    int len = strlen(tuple);
    int blue = 0;
    int green = 0;
    int power= 1;

    for(int i = 0; i < len;i++){
        int temp = tuple[i];

        decToBinary(temp,binary);

        blue+=binary[  (6-i) ] * power;


        if(  i < 3 ){
            green += binary[ (6-i-3) ] * power;
        }
        else{
            green += binary[ (6-i+3)] * power;

        }
        power = power << 1;
    }

    code[*codeCounter] = blue;
    (*codeCounter)++;
    code[*codeCounter] = green;
    (*codeCounter)++;
}
