@echo off

REM Путь к вашей программе передается через 1-й аргумент командной строки
SET MyProgram="%~1"

if %MyProgram%=="" (
    echo Please specify path to program
    exit /B 1
)

REM Некорректое количеством аргументов
echo Testing with invalid arguments count
%MyProgram% > nul && goto err
echo Test 1 passed

REM Некорректое значением байта  // тест написан не корректно
echo Testing with invalid byte value
%MyProgram% 256 2 L > nul && goto err
echo Test 2 passed

REM Корректные аргументы
echo Testing with valid arguments
%MyProgram% 17 2 L > "%TEMP%\output.txt" || goto err
fc result.txt "%TEMP%\output.txt">nul|| goto err
echo Test 3 passed

REM Проверка пограничного значения справа
echo Testing with right boundary value
%MyProgram% 1 1 R > "%TEMP%\output.txt" || goto err
fc result2.txt "%TEMP%\output.txt">nul|| goto err
echo Test 4 passed

REM Проверка пограничного значения слева
echo Testing with left boundary value
%MyProgram% 255 1 L > "%TEMP%\output.txt" || goto err
fc result1.txt "%TEMP%\output.txt">nul|| goto err
echo Test 5 passed


REM Тесты прошли успешно
echo All tests passed successfully
exit /B 0

REM Сюда попадаем в случае ошибки
:err
echo Test failed
exit /B 1