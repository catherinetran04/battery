#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "batt.h"

int set_batt_from_ports(batt_t *batt) {
//If BATT_VOLTAGE_PORT is negative, then no fields are changed 
// 1 is returned to indicate an error. 
    if (BATT_VOLTAGE_PORT < 0){    return 1;    } 

// sets fields based on the voltage value and converting to percent
// Returns 0 on a successful execution with no errors. 
    else {
        batt->mlvolts = BATT_VOLTAGE_PORT / 2;
        if (BATT_VOLTAGE_PORT > 7600){    batt->percent = 100;    } 
        else if ( BATT_VOLTAGE_PORT < 6000) {    batt->percent = 0;    } 
        else {    batt->percent = (batt->mlvolts - 3000) / 8;    }

        if (BATT_STATUS_PORT & (1 << 4)){    batt->mode = 1;    } 
        else {    batt->mode = 2;    }

        return 0;
    }
}


int set_display_from_batt(batt_t batt, int *display) { 
// completely resets all bits in it on successfully completing.  
    for (int i = 0; i < 32; i++){    *display = *display & ~(1 << i);    }
    if (batt.mode == 2){
        // sets digits to light up for voltage, rounding up the last value
        int base = 10, place = 3;
        for (int i = 1; i <= 3; i++) {
            int num = (batt.mlvolts / base) % 10;
            if (i == 1 && (batt.mlvolts % 10 >= 5)) { num++;}
            if (num == 0) {    *display = *display | (0b0111111 << place);  } 
            else if (num == 1) {    *display = *display | (0b0000110 << place);    } 
            else if (num == 2) {    *display = *display | (0b1011011 << place);    } 
            else if (num == 3) {    *display = *display | (0b1001111 << place);    } 
            else if (num == 4) {    *display = *display | (0b1100110 << place);    } 
            else if (num == 5) {    *display = *display | (0b1101101 << place);    } 
            else if (num == 6) {    *display = *display | (0b1111101 << place);    } 
            else if (num == 7) {    *display = *display | (0b0000111 << place);    } 
            else if (num == 8) {    *display = *display | (0b1111111 << place);    } 
            else if (num == 9) {    *display = *display | (0b1101111 << place);    } 
            place = place + 7;
            base = base * 10;
        }
        // volts sign & decimal
        *display = *display | (1 << 1) | (1 << 2);

    } else {
        // sets digits to light up for percent
        int base = 1, place = 3, term = 0;
        for (int i = 1; i <= 3; i++) {
            if (batt.percent/base == 0 && i > 1){    term = 1;    }
            int num = (batt.percent/base) % 10;
            if (num == 0 && term == 0) {    *display = *display | (0b0111111 << place);    } 
            else if (num == 1) {    *display = *display | (0b0000110 << place);    } 
            else if (num == 2) {    *display = *display | (0b1011011 << place);    } 
            else if (num == 3) {    *display = *display | (0b1001111 << place);    } 
            else if (num == 4) {    *display = *display | (0b1100110 << place);    } 
            else if (num == 5) {    *display = *display | (0b1101101 << place);    } 
            else if (num == 6) {    *display = *display | (0b1111101 << place);    } 
            else if (num == 7) {    *display = *display | (0b0000111 << place);    } 
            else if (num == 8) {    *display = *display | (0b1111111 << place);    } 
            else if (num == 9) {    *display = *display | (0b1101111 << place);    } 
            place = place + 7;
            base = base * 10;
        }
        // percentage sign & no decimal
        *display = *display | (1 << 0);
    }

    // In both modes, places bars in the level display as indicated
    if (batt.percent >= 5)  {    *display = *display | (1 << 24);    } 
    if (batt.percent >= 30) {    *display = *display | (1 << 25);    } 
    if (batt.percent >= 50) {    *display = *display | (1 << 26);    } 
    if (batt.percent >= 70) {    *display = *display | (1 << 27);    } 
    if (batt.percent >= 90) {    *display = *display | (1 << 28);    }
return 0;
}


int batt_update() {

// If functions succeed, modifies BATT_DISPLAY_PORT to show current battery level.
batt_t batt;
if (set_batt_from_ports( &batt ) != 1) {
    set_display_from_batt( batt, &BATT_DISPLAY_PORT);
    return 0;
}

// if error indicated, does NOT change the display. 
return 1;
}
