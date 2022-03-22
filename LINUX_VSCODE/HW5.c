#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("20181498 박선균\n");
    system("find ~ -name \"*.log\" -exec rm -i {} \\;");
    return 0;
}