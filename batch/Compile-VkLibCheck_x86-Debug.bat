chcp 65001

set FILENAME_VKLIB=VkLib.dll
set FILENAME_LIBSTDCPP=libstdc++-6.dll
set FILENAME_LIBSTDC=libstdc_s_dw2-1.dll
set FILENAME_GLFW=glfw3.dll

set FOLDER_OUTPUT=VkLibCheck/bin/x86/Debug

cd ..
mkdir "VkLibCheck/bin/x86/Debug"
copy ".\VkLib\bin\x86\Debug\%FILENAME_VKLIB%" "%FOLDER_OUTPUT%/%FILENAME_VKLIB%"
copy "C:\MinGW\bin\%FILENAME_LIBSTDCPP%" "%FOLDER_OUTPUT%/%FILENAME_LIBSTDCPP%"
copy "C:\MinGW\bin\%FILENAME_LIBSTDC%" "%FOLDER_OUTPUT%/%FILENAME_LIBSTDC%"
copy "C:\GLFW\glfw-3.3.4\lib-mingw\%FILENAME_GLFW%" "%FOLDER_OUTPUT%/%FILENAME_GLFW%"

C:/MinGW/Bin/g++.exe VkLibCheck/src/** ^
-g ^
-o ^
VkLibCheck/bin/x86/Debug/main.exe ^
VkLib/bin/x86/Debug/VkLib.lib

cd %~dp0