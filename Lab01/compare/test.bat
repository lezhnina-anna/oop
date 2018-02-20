rem %1 - �������� ������� ��������� ��������� ������ bat-����� (����� �� ����)
rem %~1 - �������� ������� ��������� ��������� ������ bat-����� � ��������� ����������� ������� (���� ��� ����)

rem ���������� PROGRAM ����� ������� ������ �������� ��������� ������ ����������� � �������
set PROGRAM="%~1"

rem ���������� ��� ������ �����
%PROGRAM% FirstEmpty.txt SecondEmpty.txt 
if ERRORLEVEL 1 goto err

%PROGRAM% multiLine.txt theSameMultiLine.txt 
if ERRORLEVEL 1 goto err

%PROGRAM% multiLine.txt oneLine.txt 
if NOT ERRORLEVEL 1 goto err

%PROGRAM% non-existing-file.txt FirstEmpty.txt 
if NOT ERRORLEVEL 1 goto err

echo Program testing succeeded
exit 0

:err
echo Program testing failed
exit 1