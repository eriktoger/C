//
// URLify. replace all spaces with %20
//

//maybe not the quickest way, but I wanted to train on linked list and malloc
// another way is to move everything two steps everytime we encounter space
#include <memory.h>
#include <malloc.h>

typedef struct linkedList linkedList;
struct linkedList{

    char c;
    linkedList * next;

};

void url1(){
    char word[500];
    printf("Enter word 1:\n");
    fgets(word,500,stdin);

    linkedList *pFirst = malloc(sizeof(linkedList));
    pFirst->c = word[0];
    pFirst->next = NULL;
    linkedList *pLast = pFirst;

    for(int i=1; i<strlen(word);i++){
        linkedList *new = malloc(sizeof(linkedList));
        new->c = word[i];
        new->next = NULL;
        pLast->next = new;
        pLast = new;
    }

    linkedList *saveFirst = pFirst;
    while(pFirst){
        if(pFirst->c == ' '){

            linkedList *new1 = malloc(sizeof(linkedList));
            linkedList *new2 = malloc(sizeof(linkedList));

            pFirst->c = '%';

            new1->c = '2';
            new1->next = new2;

            new2->c = '0';
            new2->next = pFirst->next;


            pFirst->next = new1;

        }

        pFirst = pFirst->next;

    }

    pFirst = saveFirst;
    while(pFirst != NULL){
        printf("%c",pFirst->c);
        pFirst = pFirst->next;
    }

    pFirst = saveFirst;
    while(pFirst != NULL){
        linkedList * temp = pFirst;
        pFirst =pFirst->next;
        free(temp);
    }

}
//inspiration
//https://codedost.com/c/arraypointers-in-c/c-program-insert-element-array/
void url2(){
    char word[500];
    printf("Enter word 1:\n");
    fgets(word,500,stdin);

    int wordCounter = strlen(word)+1;
    for(int i=0;i<wordCounter;i++){
        if(word[i]== ' '){
            word[i] = '%';

            //moves from the back
            for(int j = wordCounter;j>i;j--){
                word[j+2] =word[j];
            }
            wordCounter+=2;
            word[i+1] = '2';
            word[i+2] = '0';
        }
        if(wordCounter>500){
            break;
        }
    }
    printf("%s",word);

}