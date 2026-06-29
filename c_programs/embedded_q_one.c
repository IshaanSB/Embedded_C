/*
Problem: Write a function in Embedded C that takes a 32-bit unsigned integer, clears bits 8 to 15 (inclusive), and swaps the upper 16 bits with the lower 16 bits.Constraints: No loops allowed. Must execute 
in $O(1)$ time complexity.
*/

#include<stdio.h>
#include<stdint.h>

uint32_t bitwise(uint32_t num);


int main(){


uint32_t num = 0xFF00FFFF;
    
printf("Original: 0x%08X\n", num);
    
uint32_t result = bitwise(num);
    
printf("Expected: 0xFFFFFF00\n");
printf("Actual:   0x%08X\n", result);

// Verification check
if (result == 0xFFFFFF00) {
    printf("SUCCESS!\n");
} 
else {
    printf("FAILED!\n");
}



return 0;
}

uint32_t bitwise(uint32_t num){

uint32_t temp= num;
uint32_t modifier=0xFF00FFFF;
num=num&modifier;

num=num^(num<<8);
temp=temp^(0xFF);
num=num^temp;

return num;



}
