#include <stdio.h>

//
// https://www.spoj.com/problems/BUET19A/
//
void mod(){
    const int ROCK = 0;
    const int PAPER = 1;
    const int SCISSOR = 2;

    const char gonString[] ="GON\n";
    const char killuaString[] = "KILLUA\n";
    int testCases;
    scanf ("%d",&testCases);

    while(testCases--){
        int gon;
        scanf("%d",&gon);
        int killua;
        scanf("%d",&killua);
        gon = gon%3;
        killua = killua%3;

        if(gon == killua){
            printf("DRAW\n");
        }

        if(gon == ROCK && killua == PAPER){
            printf(killuaString);
        }

        if(gon == PAPER && killua == ROCK){
            printf(gonString);
        }

        if(gon == SCISSOR && killua == ROCK){
            printf(killuaString);
        }

        if(gon == ROCK && killua == SCISSOR){
            printf(gonString);
        }

        if(gon == PAPER && killua == SCISSOR){
            printf(killuaString);
        }

        if(gon == SCISSOR && killua == PAPER){
            printf(gonString);
        }

    }
}
