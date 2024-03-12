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

REM �������� ���� ����� ������
echo empty file
%MyProgram% empty1.txt empty2.txt>nul && goto err
echo Test 2 passed

REM �������� ����������
echo Testing result
%MyProgram% matrix1.txt  matrix2.txt > "%TEMP%\output.txt" || goto err
fc result.txt "%TEMP%\output.txt">nul|| goto err
echo Test 3 passed

REM �������� �� ��������� ������ � �����
echo Check correct data in file
%MyProgram% matrix2.txt matrix3.txt nul && goto err
echo Test 4 passed

REM ����� ������ �������
echo All tests passed successfully
exit /B 0

REM ���� �������� � ������ ������
:err
echo Test failed
exit /B 1
