//
// https://www.spoj.com/problems/HS12MBR/
//

struct Coordinates {
    int xMin;
    int xMax;
    int yMin;
    int yMax;
};

void point(struct Coordinates *cords);
void circle(struct Coordinates *cords);
void line(struct Coordinates *cords);

void checkMax (struct Coordinates *cords,int xCord,int yCord);
void checkMin (struct Coordinates *cords,int xCord,int yCord);

void hs12mbr() {

    int testCases;
    scanf ("%d",&testCases);

    while(testCases--){
        int nrOfObjects;
        scanf ("%d",&nrOfObjects);

        struct Coordinates cords;
        cords.xMax = -1000;
        cords.xMin = 1000;
        cords.yMax = -1000;
        cords.yMin = 1000;


        while(nrOfObjects--){

            char typeOfObject;
            scanf(" %c", &typeOfObject);

            switch(typeOfObject){
                case 'p':
                    point(&cords);
                    break;
                case 'c':
                    circle(&cords);
                    break;
                case 'l':
                    line(&cords);
                    break;
                default:;
            }

        }

        printf("%d %d %d %d\n",
                cords.xMin, cords.yMin, cords.xMax,cords.yMax);
    }

}

void point(struct Coordinates *cords){

    int xCord;
    int yCord;
    scanf ("%d",&xCord);
    scanf ("%d",&yCord);

    checkMax(cords, xCord,yCord);
    checkMin(cords, xCord,yCord);

}

void circle(struct Coordinates *cords){
    int xCord;
    int yCord;
    int radie;
    scanf ("%d",&xCord);
    scanf ("%d",&yCord);
    scanf ("%d",&radie);

    checkMax(cords, xCord + radie, yCord + radie);
    checkMin(cords, xCord - radie, yCord - radie);
}

void line (struct Coordinates *cords){
    int x1Cord;
    int y1Cord;
    scanf ("%d",&x1Cord);
    scanf ("%d",&y1Cord);

    checkMax(cords, x1Cord, y1Cord);
    checkMin(cords, x1Cord, y1Cord);

    int x2Cord;
    int y2Cord;
    scanf ("%d",&x2Cord);
    scanf ("%d",&y2Cord);

    checkMax(cords, x2Cord,y2Cord);
    checkMin(cords, x2Cord,y2Cord);
}

void checkMax (struct Coordinates *cords,int xCord,int yCord){
    if(cords->xMax < xCord ){
        cords->xMax = xCord;
    }

    if(cords->yMax < yCord  ){
        cords->yMax = yCord;
    }
}

void checkMin (struct Coordinates *cords,int xCord,int yCord){

    if(cords->xMin > xCord ){
        cords->xMin = xCord;
    }

    if(cords->yMin > yCord ){
        cords->yMin = yCord;
    }

}

