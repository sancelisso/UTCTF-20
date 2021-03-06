#include <stdio.h>
#include <string.h>

unsigned char check[] = {0x3, 0x12, 0x1a, 0x17, 0xa, 0xec, 0xf2, 0x14, 0xe, 0x5, 0x3, 0x1d, 0x19, 0xe, 0x2, 0xa, 0x1f, 0x7, 0xc, 0x1, 0x17, 0x6, 0xc, 0xa, 0x19, 0x13, 0xa, 0x16, 0x1c, 0x18, 0x8, 0x7, 0x1a, 0x3, 0x1d, 0x1c, 0x11, 0xb, 0xf3, 0x87, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x5};
int MAX_SIZE = 64;

int reverse(char* reverse_me) {
    for(int i = 0; i < MAX_SIZE; i++) {
        reverse_me[i] += 5;
    }
    for(int i = 0; i < MAX_SIZE-1; i++) {
        reverse_me[i] ^= reverse_me[i+1];
    }
    for(int i = 0; i < MAX_SIZE; i++) {
        if(check[i] != (unsigned char)reverse_me[i]) {
					  printf("%d\n", i);
            return 0;
        }
    }
    return 1;
}

int main() {
    char * flag = "utflag{machine_agnostic_ir_is_wonderful}";
    char buf[MAX_SIZE];
    for(int i = 0; i < MAX_SIZE; i++) {
        buf[i] = 0;
    }
    strcpy(buf, flag);
    printf("%d\n", reverse(buf));
    for(int i = 0; i < MAX_SIZE; i++) {
        printf("%hhx ", buf[i]);
    }
		printf("\n");
    for(int i = 0; i < MAX_SIZE; i++) {
        printf("%hhx ", check[i]);
    }
    return 0;
}


