//
// https://www.spoj.com/problems/HS12HDPW/
//

#include <string.h>
#include <math.h>
//qwe345 rf3Arg
//XSBSRasdew9873465hkldsfsalndfvnfq489uqovkLKJHaeDaae555Sk5asdpASD
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

void hs12hdpw(){

    int testCases;
    scanf ("%d",&testCases);
    int binary[7];

    while(testCases--){
        int code[200];
        int codeCounter = 0;
        int nrOfTuples;
        scanf ("%d",&nrOfTuples);
        while(nrOfTuples--){

            char tuple[20];
            scanf("%s",&tuple);
            //printf(tuple);
            //printf("\n");
            int len = strlen(tuple);
            int blue = 0;
            int green = 0;

            for(int i = 0; i < len;i++){
                int temp = tuple[i];
                decToBinary(temp,binary);

                double doubleI = (double) i;
                int power = (int) pow(2.0, doubleI);

                for(int b =0;b < 7;b++ ){
                    //printf("%d",binary[b]);
                }
                //printf("\n");


                // blue just jumps to the left is seems
                blue+=binary[  (6-i) ] * power;
                //printf("blue: %d \t",(6-i) );


                if(  i < 3 ){
                    green += binary[ (6-i-3) ] * power;
                    //printf("green: %d \n",(6-i-3));
                }
                else{
                    green += binary[ (6-i+3)] * power;
                    //printf("green: %d \n",(6-i+3));
                }
            }
            //printf("%d ",blue);
            //printf("%d \n",green);
            code[codeCounter] = blue;
            codeCounter++;
            code[codeCounter] = green;
            codeCounter++;
        }



        char word[65];
        scanf("%s",&word);
        //printf(word);
        //printf("\n");
        int newCodeCounter = 0;
        while(newCodeCounter < codeCounter){
            printf("%c",word[code[newCodeCounter]]);
            newCodeCounter++;
        }
        printf("\n");

    }
}

