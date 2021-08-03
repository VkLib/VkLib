#include "../../VkLib/src/VkLib.h"

using namespace VkLib;

#include <stdio.h>

#define str(val) #val

int main(void) {
    int32_t ret = 0;

    ret = VkLib_Init();

    if(ret != 0) {
        printf("%s(): %d", str(VkLib_Init),ret);
    }

    while(ProcessMessage() == 0) {
        
    }

    VkLib_End();

    return 0;
}