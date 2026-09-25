@echo off
cd /D "%~dp0"

pushd bin
start devenv /debugexe main.exe
popd
