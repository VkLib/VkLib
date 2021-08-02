typedef int int32_t;

namespace VkLib {
    /**
     * @brief 真
     */
    #define TRUE 1

    /**
     * @brief 偽
     */
    #define FALSE 0

    constexpr int VK_SUCCESS = 0;

    constexpr int VK_IMAGE_NUM = 65535;
    /**
     * @brief VkLib Initilize
     * 
     * @return int32_t (0: SUCCESS, other: ERRORCODE)
     */
    int32_t VkLib_Init();

    /**
     * @brief 
     * 
     * @return int32_t 
     */
    int32_t ProcessMessage();

    /**
     * @brief VkLib Finalize
     * 
     * @return int32_t (0: SUCCESS, other: ERRORCODE)
     */
    int32_t VkLib_End();

    /**
     * @brief Set the Out Application Log Valid Flag object
     * 
     * @param flag 
     * @return int32_t 
     */
    int32_t SetOutApplicationLogValidFlag(int32_t flag);
}