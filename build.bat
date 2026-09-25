@echo off
setlocal enabledelayedexpansion
cd /D "%~dp0"

for /F "tokens=1-4 delims=:.," %%a in ("%time%") do (
   set /A "start=(((%%a*60)+1%%b %% 100)*60+1%%c %% 100)*100+1%%d %% 100"
)

if not exist build\build.ninja (
    echo Initializing CMake...
    cmake -G "Ninja" -B build
)

if "%1" == "cmake" (
    cmake -G "Ninja" -B build
    goto exit
)

if "%1" == "rebuild" (
    cmake --build build --clean-first
    goto exit
)

echo ----------------------------------------------
echo Compiling
ninja -C build
echo Build completed.

:show_stats
for /F "tokens=1-4 delims=:.," %%a in ("%time%") do (
   set /A "end=(((%%a*60)+1%%b %% 100)*60+1%%c %% 100)*100+1%%d %% 100"
)

set /A elapsed=end-start
if !elapsed! lss 0 set /A elapsed+=24*60*60*100

set /A hh=elapsed/(60*60*100), rest=elapsed%%(60*60*100), mm=rest/(60*100), rest%%=60*100, ss=rest/100, cc=rest%%100

if %ss% lss 10 set ss=0%ss%
if %cc% lss 10 set cc=0%cc%

echo.
echo ----------------------------------------------
echo Build time: %hh%h %mm%m %ss%.%cc%s
echo ----------------------------------------------

:exit
endlocal
