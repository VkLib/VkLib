#include "VkLib.h"

#include <filesystem>

int32_t LoadGraph(const TCHAR* pFilePath) {
    constexpr int RESULT_LOAD_FAILED = -1;
    namespace fs = std::filesystem;

    if (!fs::exists(pFilePath)) {
        return LOAD_FAILED;
    }

    return TRUE;
}

int32_t DrawGraph(int32_t x, int32_t y, int32_t handle) {
    return TRUE;
}