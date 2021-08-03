#include "../../VkLib/src/VkLib.h"

using namespace VkLib;

#include <stdio.h>

int main(void) {
    int32_t ret = 0;

    ret = VkLib_Init();

    if(ret != 0) {
        switch (ret)
        {
        case -2:
            printf("Vulkanに対応していないGPUを積んだPCで使用されています。\n");
            break;        
        default:
            break;
        }
        return -1;
    }

    while(ProcessMessage() == 0) {
        printf("oh\n");
    }

    VkLib_End();

    return 0;
}