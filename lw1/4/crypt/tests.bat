@echo off

REM ���� � ����� ��������� ���������� ����� 1-� �������� ��������� ������
SET MyProgram="%~1"

if %MyProgram%=="" (
    echo Please specify path to program
    exit /B 1
)

REM ����������� ����������� ����������
echo Testing with invalid arguments count
%MyProgram% >nul && goto err
echo Test 1 passed

REM �������� �� ������������ ����������
echo Check correct arguments file
%MyProgram% crypt input.txt "%TEMP%\output.txt" 256>nul && goto err
echo Test 2 passed

REM �������� �� ���������� � ������������
echo Check Encode and Dencode right boundary key
%MyProgram% crypt input.txt "%TEMP%\encode.txt" 255 || goto err
%MyProgram% decrypt "%TEMP%\encode.txt" "%TEMP%\output.txt" 255 || goto err
fc input.txt "%TEMP%\output.txt">nul || goto err
echo Test 3 passed

REM �������� �� ���������� � ������������
echo Check Encode and Dencode left boundary key
%MyProgram% crypt input.txt "%TEMP%\encode.txt" 0 || goto err
%MyProgram% decrypt "%TEMP%\encode.txt" "%TEMP%\output.txt" 0 || goto err
fc input.txt "%TEMP%\output.txt">nul || goto err
echo Test 4 passed

REM �������� �� ���������� � ������������ bmp �����
echo Check Encode and Dencode bmp file
%MyProgram% crypt test.bmp "%TEMP%\test.crypt" 156 || goto err
%MyProgram% decrypt "%TEMP%\test.crypt" "%TEMP%\test.bmp" 156 || goto err
fc test.bmp "%TEMP%\test.bmp">nul || goto err
echo Test 5 passed

REM �������� �� ���������� � ������������ exe �����
echo Check Encode and Dencode exe file
%MyProgram% crypt "D:\OOP\lw1\4\crypt\x64\Debug\crypt.exe" "%TEMP%\crypt.crypted" 12 || goto err
%MyProgram% decrypt "%TEMP%\crypt.crypted" "%TEMP%\crypt1.exe" 12 || goto err
fc "D:\OOP\lw1\4\crypt\x64\Debug\crypt.exe" "%TEMP%\crypt1.exe">nul || goto err
echo Test 6 passed

REM �������� ���� ��� ����� ��� 255 �������� . ���� �� �������� �����.

REM ����� ������ �������
echo All tests passed successfully
exit /B 0

REM ���� �������� � ������ ������
:err
echo Test failed
exit /B 1
