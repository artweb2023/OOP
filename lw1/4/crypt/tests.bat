@echo off

REM Путь к вашей программе передается через 1-й аргумент командной строки
SET MyProgram="%~1"

if %MyProgram%=="" (
    echo Please specify path to program
    exit /B 1
)

REM Некорректое количеством аргументов
echo Testing with invalid arguments count
%MyProgram% >nul && goto err
echo Test 1 passed

REM Проверка на корректность аргументов
echo Check correct arguments file
%MyProgram% crypt input.txt "%TEMP%\output.txt" 256>nul && goto err
echo Test 2 passed

REM Проверка на шифрование и дешифрование
echo Check Encode and Dencode right boundary key
%MyProgram% crypt input.txt "%TEMP%\encode.txt" 255 || goto err
%MyProgram% decrypt "%TEMP%\encode.txt" "%TEMP%\output.txt" 255 || goto err
fc input.txt "%TEMP%\output.txt">nul || goto err
echo Test 3 passed

REM Проверка на шифрование и дешифрование
echo Check Encode and Dencode left boundary key
%MyProgram% crypt input.txt "%TEMP%\encode.txt" 0 || goto err
%MyProgram% decrypt "%TEMP%\encode.txt" "%TEMP%\output.txt" 0 || goto err
fc input.txt "%TEMP%\output.txt">nul || goto err
echo Test 4 passed

REM Тесты прошли успешно
echo All tests passed successfully
exit /B 0

REM Сюда попадаем в случае ошибки
:err
echo Test failed
exit /B 1
