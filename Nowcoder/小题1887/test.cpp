#include <stdio.h>
int main() { 
    int i, n = 0;
    float x = 1, y1 = 2.1 / 1.9, y2 = 1.9 / 2.1;
    for ( i = 1; i < 22; i++)
        x = x * y1;
    while ( x != 1.0 ) {
        x = x * y2; n++;    
    }
    printf( "%d\n", n );
    return 0; 
}