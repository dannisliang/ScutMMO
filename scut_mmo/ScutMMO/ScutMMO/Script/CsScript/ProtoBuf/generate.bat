@echo off

for /f "delims=" %%i in ('dir /b/a-d/s "%cd%\*.proto"') do (
  echo ����: %%i && Tools\protoc.exe --cpp_out="%cd%/" --proto_path "%cd%/" %%i 
  Tools\protogen.exe -i:"%%i" -o:"%%~dpni.cs" 
)

echo ������ɣ���������˳�
echo ���ʱ�� %date:~0,10% %time:~0,8%

pause>nul&exit
