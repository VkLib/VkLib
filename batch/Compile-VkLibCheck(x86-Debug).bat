cd ..
mkdir "VkLibCheck/bin/x86/Debug"
copy ".\VkLib\bin\x86\Debug\VkLib.dll" "VkLibCheck/bin/x86/Debug/VkLib.dll"

C:/MinGW/Bin/g++.exe VkLibCheck/src/** ^
-g ^
-o ^
VkLibCheck/bin/x86/Debug/main.exe ^
VkLib/bin/x86/Debug/VkLib.lib

cd %~dp0