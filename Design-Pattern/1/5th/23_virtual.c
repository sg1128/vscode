#include <stdio.h>
//c
struct AAA {
    int a;
    char b;
    double c;
};

// 0x123456
//  빅엔디안: [0x12][0x34][0x56]
//리틀엔디안: [0x56][0x34][0x12]

struct BBB {
    char a;
    double b;
    int c;
} __attribute__((aligned(1), packed));

int main()
{
    printf("%ld\n", sizeof(struct AAA));
    printf("%ld\n", sizeof(struct BBB));
}