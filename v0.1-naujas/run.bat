@echo off
if not exist build mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build . --config Release
if exist .\v1.0.exe (.\v1.0.exe %*) else (.\Release\v1.0.exe %*)
pause
