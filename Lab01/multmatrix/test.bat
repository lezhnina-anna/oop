rem %1 - �������� ������� ��������� ��������� ������ bat-����� (����� �� ����)
rem %~1 - �������� ������� ��������� ��������� ������ bat-����� � ��������� ����������� ������� (���� ��� ����)

rem ���������� PROGRAM ����� ������� ������ �������� ��������� ������ ����������� � �������
set PROGRAM="%~1"
 
rem ���������� ������� ������
%PROGRAM% input.txt identityMatrix.txt > output.txt 
if ERRORLEVEL 1 goto err
fc output.txt CorrectOutput.txt
if ERRORLEVEL 1 goto err

%PROGRAM% doubleNum.txt identityMatrix.txt > output.txt 
if ERRORLEVEL 1 goto err
fc output.txt doubleNumOutput.txt
if ERRORLEVEL 1 goto err

rem ������������ ������� ������
%PROGRAM% input.txt InvalidInput.txt > output.txt
if NOT ERRORLEVEL 1 goto err
fc output.txt InvalidOutput.txt
if ERRORLEVEL 1 goto err

rem ������������ ���������� ���������� 
%PROGRAM% input.txt > output.txt  
if NOT ERRORLEVEL 1 goto err
fc output.txt arg_err.txt 
if ERRORLEVEL 1 goto err

rem �������������� ������� ����
%PROGRAM% non-existing-file.txt input.txt > output.txt
if NOT ERRORLEVEL 1 goto err
fc output.txt FileError.txt
if ERRORLEVEL 1 goto err

echo Program testing succeeded
exit 0

:err
echo Program testing failed
exit 1