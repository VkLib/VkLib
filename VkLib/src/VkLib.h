typedef int int32_t;
typedef char TCHAR;

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

    /**
     * @if ja-JP
     * @brief VkLib 初期化処理
     * 
     * @return int32_t 0: 成功, その他: エラーコード
     * @endif
     * 
     * 
     * @if en-US
     * @brief VkLib Initilize
     * 
     * @return int32_t 0: SUCCESS, other: ERRORCODE
     * @endif
     */
    int32_t VkLib_Init();

    /**
     * @brief VkLib Finalize
     * 
     * @return int32_t 0: SUCCESS, other: ERRORCODE
     */
    int32_t VkLib_End();

    /**
     * @brief Execute process message
     * 
     * @return int32_t 0: SUCCESS, other: FAILED
     */
    int32_t ProcessMessage();

    /**
     * @brief Set the Window Title object
     * 
     * @param pTitle タイトル
     * @return int32_t 0: SUCCESS, other: FAILED
     */
    int32_t SetWindowTitle(const TCHAR* pTitle);

    /**
     * @brief Set the Out Application Log Valid Flag object
     * 
     * @param flag 
     * @return int32_t 0: SUCCESS, other: FAILED
     */
    int32_t SetOutApplicationLogValidFlag(int32_t flag);
}