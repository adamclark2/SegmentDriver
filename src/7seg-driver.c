#ifndef segseven
#define segseven

#include <stdint.h>
#include <stdio.h>

#define seg_A 1
#define seg_B 2
#define seg_C 4
#define seg_D 8
#define seg_E 16
#define seg_F 32
#define seg_G 64

typedef uint16_t seg_char;

uint16_t sevenseg_lookup_table[2][20];

void sevenSeg_init(){

    // Thanks wikipedia
    // https://en.wikipedia.org/wiki/Seven-segment_display
    int i = 0;
    sevenseg_lookup_table[0][i++] = 0x77; // A
    sevenseg_lookup_table[0][i++] = 0x7C; // B
    sevenseg_lookup_table[0][i++] = 0x39; // C
    sevenseg_lookup_table[0][i++] = 0x5E; // D
    sevenseg_lookup_table[0][i++] = 0x79; // E
    sevenseg_lookup_table[0][i++] = 0x71; // E
    sevenseg_lookup_table[0][i++] = 0x47; // F

    // H wasn't on wiki table
    sevenseg_lookup_table[0][7] = seg_F | seg_B | seg_G | seg_E | seg_C; // H

    i = 0;
    sevenseg_lookup_table[1][i++] = 0x3f; // 0
    sevenseg_lookup_table[1][i++] = 0x06; // 1
    sevenseg_lookup_table[1][i++] = 0x5B; // 2
    sevenseg_lookup_table[1][i++] = 0x4F; // 3
    sevenseg_lookup_table[1][i++] = 0x66; // 4
    sevenseg_lookup_table[1][i++] = 0x6D; // 5
    sevenseg_lookup_table[1][i++] = 0x7D; // 6
    sevenseg_lookup_table[1][i++] = 0x07; // 7
    sevenseg_lookup_table[1][i++] = 0x7F; // 8
    sevenseg_lookup_table[1][i++] = 0x6F; // 9
}

seg_char sevenSeg_char_to_7char(char c){
    if(c == 32){
        return 0x00;
    }

    if(c >= 65){
        return sevenseg_lookup_table[0][(c - 65) % 20];
    }else{
        return sevenseg_lookup_table[1][(c - 48) % 20];
    }
    
}

#endif