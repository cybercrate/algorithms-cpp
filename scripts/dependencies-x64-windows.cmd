mkdir ..\lib
cd ..\lib
git clone https://github.com/wingmann/wing-concepts

cd %HOMEPATH%\vcpkg

vcpkg install gtest:x64-windows
