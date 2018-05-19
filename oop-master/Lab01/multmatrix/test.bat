rem %1 - значение первого аргумента командной строки bat-файла (какой он есть)
rem %~1 - значение первого аргумента командной строки bat-файла с удалением обрамл€ющих кавычек (если они были)

rem ѕеременна€ PROGRAM будет хранить первый аргумент командной строки заключЄнный в кавычки
set PROGRAM="%~1"
 
rem корректные входные данные
%PROGRAM% input.txt identityMatrix.txt > output.txt 
if ERRORLEVEL 1 goto err
fc output.txt CorrectOutput.txt
if ERRORLEVEL 1 goto err

%PROGRAM% doubleNum.txt identityMatrix.txt > output.txt 
if ERRORLEVEL 1 goto err
fc output.txt doubleNumOutput.txt
if ERRORLEVEL 1 goto err

rem некорректные входные данные
%PROGRAM% input.txt InvalidInput.txt > output.txt
if NOT ERRORLEVEL 1 goto err
fc output.txt InvalidOutput.txt
if ERRORLEVEL 1 goto err

rem неправильное количество аргументов 
%PROGRAM% input.txt > output.txt  
if NOT ERRORLEVEL 1 goto err
fc output.txt arg_err.txt 
if ERRORLEVEL 1 goto err

rem несуществующий входной файл
%PROGRAM% non-existing-file.txt input.txt > output.txt
if NOT ERRORLEVEL 1 goto err
fc output.txt FileError.txt
if ERRORLEVEL 1 goto err

echo Program testing succeeded
exit 0

:err
echo Program testing failed
exit 1