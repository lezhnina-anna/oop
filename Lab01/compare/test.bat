rem %1 - �������� ������� ��������� ��������� ������ bat-����� (����� �� ����)
rem %~1 - �������� ������� ��������� ��������� ������ bat-����� � ��������� ����������� ������� (���� ��� ����)

rem ���������� PROGRAM ����� ������� ������ �������� ��������� ������ ����������� � �������
set PROGRAM="%~1"

rem ���������� ��� ������ ����� 
%PROGRAM% FirstEmpty.txt SecondEmpty.txt  > output.txt
if ERRORLEVEL 1 goto err
fc output.txt equal.txt 
if ERRORLEVEL 1 goto err

%PROGRAM% multiLine.txt theSameMultiLine.txt > output.txt
if ERRORLEVEL 1 goto err
fc output.txt equal.txt  
if ERRORLEVEL 1 goto err

%PROGRAM% multiLine.txt oneLine.txt > output.txt 
if ERRORLEVEL 1 goto err
fc output.txt notequal.txt  
if ERRORLEVEL 1 goto err

%PROGRAM% non-existing-file.txt FirstEmpty.txt > output.txt
if NOT ERRORLEVEL 1 goto err
fc output.txt err.txt  
if ERRORLEVEL 1 goto err

%PROGRAM% 1.txt 2.txt > output.txt
if ERRORLEVEL 1 goto err
fc output.txt out.txt  
if ERRORLEVEL 1 goto err 

%PROGRAM% 2.txt 1.txt > output.txt
if ERRORLEVEL 1 goto err
fc output.txt out.txt  
if ERRORLEVEL 1 goto err

echo Program testing succeeded
exit 0

:err
echo Program testing failed
exit 1