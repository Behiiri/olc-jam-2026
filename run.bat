@echo off
cd /D "%~dp0"

pushd bin
echo. & echo running: %cd%\main.exe
 .\main.exe
popd
