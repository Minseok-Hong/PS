#include <stdio.h>
 
int main(void){
    int number;
    int count = 0;
    int A, B, C , Add;
    scanf("%d", &number);
    Add = number;
    while (Add != number || count==0){
        A = Add / 10;
        B = Add % 10;
        C = (A + B) % 10;
        A = B; B = C;
        Add = A * 10 + B;
        count++;
    }
 
    printf("%d\n", count);
 
}