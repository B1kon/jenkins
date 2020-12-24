#include "mc12705load_arm.h"

typedef unsigned int WORD32;
int main() asm ("main");
int main ()
{
    WORD32 Fill = 0x93939393;
    
    WORD32 Length = 0x3;
    WORD32 *AddrStore = (WORD32 *) 0xd100;

    for(int i = 0; i < Length; i++) {
        AddrStore[i] = Fill;
    }

    acl_hostSyncArray(1, AddrStore, Length, 0, 0);

    return 0;
}
