@echo off
REM Batch file to compile the Grocery Store Management project
REM Requires MinGW or Visual Studio C++ compiler installed

cd /d %~dp0

echo Compiling Grocery Store Management System...
echo.

REM For MinGW (if g++ is in PATH):
REM Uncomment below and comment the cl.exe lines

REM g++ -c Source\Product.cpp -o Source\Product.o
REM g++ -c Source\Customer.cpp -o Source\Customer.o
REM g++ -c Source\Supplier.cpp -o Source\Supplier.o
REM g++ -c Source\Sale.cpp -o Source\Sale.o
REM g++ -c Source\FileManager.cpp -o Source\FileManager.o
REM g++ -c Source\GroceryStore.cpp -o Source\GroceryStore.o
REM g++ -c Source\main.cpp -o Source\main.o
REM g++ Source\*.o -o Executable\Project.exe

REM For Visual Studio C++ Compiler (cl.exe):
REM Requires Visual Studio Build Tools or Visual Studio installed

cd Source
cl /EHsc /std:c++17 /Fo..\Temp\ ^
   Product.cpp ^
   Customer.cpp ^
   Supplier.cpp ^
   Sale.cpp ^
   FileManager.cpp ^
   GroceryStore.cpp ^
   main.cpp ^
   /Fe..\Executable\Project.exe

if %ERRORLEVEL% EQU 0 (
    echo.
    echo Compilation successful!
    echo Executable created at: ..\Executable\Project.exe
    cd ..
) else (
    echo.
    echo Compilation failed! Please check the errors above.
    cd ..
    pause
)
