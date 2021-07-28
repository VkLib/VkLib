#include <cstdint>


namespace VkLib {
    constexpr int VK_SUCCESS = 0;

    constexpr int VK_IMAGE_NUM = 65535;
    /**
     * @brief VkLib Initilize
     * 
     * @return int32_t (0: SUCCESS, other: ERRORCODE)
     */
    int32_t VkLib_Init();

    /**
     * @brief VkLib Finalize
     * 
     * @return int32_t (0: SUCCESS, other: ERRORCODE)
     */
    int32_t VkLib_End();
}