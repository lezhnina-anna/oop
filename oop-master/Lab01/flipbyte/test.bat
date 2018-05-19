rem %1 - значение первого аргумента командной строки bat-файла (какой он есть)
rem %~1 - значение первого аргумента командной строки bat-файла с удалением обрамл€ющих кавычек (если они были)

rem ѕеременна€ PROGRAM будет хранить первый аргумент командной строки заключЄнный в кавычки
set PROGRAM="%~1"

rem сравниваем два пустых файла
%PROGRAM% 6 > output.txt  
if ERRORLEVEL 1 goto err
fc output.txt 96.txt 
if ERRORLEVEL 1 goto err

%PROGRAM% -5 > output.txt 
if NOT ERRORLEVEL 1 goto err
fc output.txt err.txt
if ERRORLEVEL 1 goto err

%PROGRAM% 256 > output.txt
if NOT ERRORLEVEL 1 goto err
fc output.txt err.txt
if ERRORLEVEL 1 goto err

%PROGRAM% 2 3 4 > output.txt
if NOT ERRORLEVEL 1 goto err
fc output.txt arg_err.txt
if ERRORLEVEL 1 goto err

echo Program testing succeeded
exit 0

:err
echo Program testing failed
exit 1