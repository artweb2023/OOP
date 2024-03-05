@echo off

REM ���� � ����� ��������� ���������� ����� 1-� �������� ��������� ������
SET MyProgram="%~1"

if %MyProgram%=="" (
    echo Please specify path to program
    exit /B 1
)

REM ����������� ����������� ����������
echo Testing with invalid arguments count
%MyProgram% > nul && goto err
echo Test 1 passed

REM ����������� ��������� �����  // ���� ������� �� ���������
echo Testing with invalid byte value
%MyProgram% 256 2 L > nul && goto err
echo Test 2 passed

REM ���������� ���������
echo Testing with valid arguments
%MyProgram% 17 2 L > "%TEMP%\output.txt" || goto err
fc result.txt "%TEMP%\output.txt">nul|| goto err
echo Test 3 passed

REM �������� ������������ �������� ������
echo Testing with right boundary value
%MyProgram% 1 1 R > "%TEMP%\output.txt" || goto err
fc result2.txt "%TEMP%\output.txt">nul|| goto err
echo Test 4 passed

REM �������� ������������ �������� �����
echo Testing with left boundary value
%MyProgram% 255 1 L > "%TEMP%\output.txt" || goto err
fc result1.txt "%TEMP%\output.txt">nul|| goto err
echo Test 5 passed


REM ����� ������ �������
echo All tests passed successfully
exit /B 0

REM ���� �������� � ������ ������
:err
echo Test failed
exit /B 1