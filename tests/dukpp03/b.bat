cmake -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Debug
mingw32-make
if %ERRORLEVEL% EQU 0 (
"../../bin/dukpp-03-tests-debug.exe"
)