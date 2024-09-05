#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int generate_pythagorean_triplet(){

    for(int i=1;i<1000;i++){
        for(int j=1;j<1000;j++){
            for(int k=1;k<1000;k++){
                if(i*i + j*j == k*k && i+j+k == 1000){
                    printf("Pythagorean triplet: %d, %d, %d\n", i, j, k);
                    return i*j*k;
                }
            }
        }
    }

    return 1;


}


int main(void){

    int result = generate_pythagorean_triplet();
    printf("The result is: %d\n", result);
    
    //Pythagorean triplet: 200, 375, 425
    //The result is: 31875000

    return 0;
}