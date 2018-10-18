#include "7seg-driver.c"
#include <stdlib.h>
#include <string.h>

char** get_segment(seg_char segs){
    // Not the best code... It works

    int size = 12;
    char** retVal = malloc(sizeof(char*) * size);
    for(int i = 0; i < size;i++){
        retVal[i] = malloc(sizeof(char) * 7);
    }

    if((segs & seg_A) != 0x0){
        sprintf(retVal[0]," #### ");
    }else{
        sprintf(retVal[0],"      ");
    }

    if(((segs & seg_F) != 0x0) && ((segs & seg_B) != 0x0)){
        sprintf(retVal[1],"#    #");
        sprintf(retVal[2],"#    #");
        sprintf(retVal[3],"#    #");
        sprintf(retVal[4],"#    #");
    } else if((segs & seg_F) != 0x0){
        sprintf(retVal[1],"#     ");
        sprintf(retVal[2],"#     ");
        sprintf(retVal[3],"#     ");
        sprintf(retVal[4],"#     ");
    }else if((segs & seg_B) != 0x0){
        sprintf(retVal[1],"     #");
        sprintf(retVal[2],"     #");
        sprintf(retVal[3],"     #");
        sprintf(retVal[4],"     #");
    }else{
        sprintf(retVal[1],"      ");
        sprintf(retVal[2],"      ");
        sprintf(retVal[3],"      ");
        sprintf(retVal[4],"      ");
    }

    if((segs & seg_G) != 0x0){
        sprintf(retVal[6]," #### ");
    }else{
        sprintf(retVal[6],"      ");
    }

    if(((segs & seg_E) != 0x0) && ((segs & seg_C) != 0x0)){
        sprintf(retVal[7],"#    #");
        sprintf(retVal[8],"#    #");
        sprintf(retVal[9],"#    #");
        sprintf(retVal[10],"#    #");
    } else if((segs & seg_E) != 0x0){
        sprintf(retVal[7],"#     ");
        sprintf(retVal[8],"#     ");
        sprintf(retVal[9],"#     ");
        sprintf(retVal[10],"#     ");
    }else if((segs & seg_C) != 0x0){
        sprintf(retVal[7],"     #");
        sprintf(retVal[8],"     #");
        sprintf(retVal[9],"     #");
        sprintf(retVal[10],"     #");
    }else{
        sprintf(retVal[7],"      ");
        sprintf(retVal[8],"      ");
        sprintf(retVal[9],"      ");
        sprintf(retVal[10],"      ");
    }

    if((segs & seg_D) != 0x0){
        sprintf(retVal[11]," #### ");
    }else{
        sprintf(retVal[11],"      ");
    }

    return retVal;
}

void printSegP(char** seg){
    for(int i = 0; i < 12;i++){
        printf("\t%s\n", seg[i]);
    }
}

void display(char c){
    char** val = get_segment(c);
    printSegP(val);
}

void displayMultiple(char* str){
    char*** vals = malloc(sizeof(char**) * strlen(str));
    char** last;
    for(int i = 0; str[i] != (char) 0;i++){
        char c = str[i];
        vals[i] = get_segment(sevenSeg_char_to_7char(c));
    }

    for(int i = 0; i < 12;i++){
        printf("\t");
        for(int z = 0; z < strlen(str);z++){
            printf("%s  ", vals[z][i]);
        }
        printf("\n");
    }
}