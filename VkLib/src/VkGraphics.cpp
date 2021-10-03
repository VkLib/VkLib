#include "VkLib.h"

#include <filesystem>

namespace {

}

int32_t LoadGraph(const TCHAR* pFilePath) {

    namespace fs = std::filesystem;
    constexpr int RESULT_LOAD_FAILED = -1;

    if (!fs::exists(pFilePath)) {
        return RESULT_LOAD_FAILED;
    }

    return TRUE;
}

int32_t DrawGraph(int32_t x, int32_t y, int32_t handle) {
    return TRUE;
}