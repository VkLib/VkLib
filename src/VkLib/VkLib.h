
namespace VkLib {
    constexpr int VK_SUCCESS = 0;

    constexpr int VK_IMAGE_NUM = 65535;
    /**
     * @brief VkLib Initilize
     * 
     * @return int (0: SUCCESS, other: ERRORCODE)
     */
    int Initialize();

    /**
     * @brief VkLib Finalize
     * 
     * @return int (0: SUCCESS, other: ERRORCODE)
     */
    int Finalize();
}