//8 way set: 16 byte block size, 64 sets

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>

double miss = 0.0;
double hit = 0.0;

//Extract k bits from p position in integer num
int extractBits(int num, int k, int p){

    return (((1 << k) - 1) & (num >> (p - 1)));

}

int main(){

    int arr[100] = {103,13,40,49,48,20,42,114,102,38,60,66,127,79,84,10,13,8,103,86,29,54,23,1,21,42,62,61,8,106,53,93,61,85,105,39,43,26,121,98,60,80,65,35,73,19,6,58,44,33,60,12,40,18,80,60,22,121,11,71,108,98,33,66,94,96,113,119,5,46,15,26,81,82,59,61,38,69,57,79,43,12,82,67,28,107,43,123,28,37,4,58,122,62,64,36,20,88,0,113};
    int cache[8][8] = {0};

    //Set each cache position to -1 to signal empty
    for(int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            cache[i][j] = -1;
        }
    }

    //Line* n;
    int t,s,d;

    for (int i = 0; i < 100; i++ ){

        //Set tag
        t = extractBits(arr[i],3,5);

        //Set set number
        s = extractBits(arr[i],3,2);

        //Set data
        d = extractBits(arr[i],1,1);

        //Insert in cache
        if (cache[s][t] == -1){
            miss++;
            cache[s][t] = d;
        }
        else {
            hit++;
        }
    }

    //Print results
    printf("Misses: %.0f\n",miss);
    printf("Hits: %.0f\n", hit);

    double ratio = (hit / (hit + miss)) * 100;

    printf("Hit ratio: %.1f%%\n", ratio);

    return 0;
}