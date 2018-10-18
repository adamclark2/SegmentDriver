#include <stdio.h>

#include "7seg-driver.c"
#include "fakeDisplay.c"

int main(int argc, char* argv[]){
    sevenSeg_init();

    if(argc > 1){
        printf("Displaying %s\n", argv[1]);
        displayMultiple(argv[1]);
    }else{
        // Display an 8 (manually)
        display(seg_A | seg_B | seg_C | seg_D | seg_E | seg_F | seg_G );

        printf("\n\n********************************\nLETTERS:\n");

        display(sevenSeg_char_to_7char('A'));
        display(sevenSeg_char_to_7char('B'));
        display(sevenSeg_char_to_7char('C'));
        display(sevenSeg_char_to_7char('D'));
        display(sevenSeg_char_to_7char('E'));
        display(sevenSeg_char_to_7char('F'));

        display(sevenSeg_char_to_7char('H'));

        printf("\n\n********************************\nNUMBERS:\n");
        for(int i = 48; i < (48 + 10);i++){
            display(sevenSeg_char_to_7char((char) i));
        }

        printf("\n\n********************************\nHi:\n");
        display(sevenSeg_char_to_7char('H'));
        display(sevenSeg_char_to_7char('1'));

        printf("\n\n********************************\nHi Display Multiple:\n");
        displayMultiple("H1");
    }
}