@echo off
setlocal
set "BUILD=build"

REM Configure (Release for single-config; MSVC uses --config below)
cmake -S . -B "%BUILD%" -DCMAKE_BUILD_TYPE=Release || exit /b 1

REM Build (Release)
cmake --build "%BUILD%" --config Release || exit /b 1

REM Run (works for MSVC and MinGW/Ninja layouts)
set "EXE=%BUILD%\app.exe"
if not exist "%EXE%" set "EXE=%BUILD%\Release\app.exe"

if not exist "%EXE%" (
  echo Could not find app.exe in "%BUILD%" or "%BUILD%\Release".
  exit /b 1
)

"%EXE%" %*
