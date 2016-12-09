@echo off

for /f "delims=" %%i in ('dir /b/a-d/s "%cd%\*.proto"') do (
  echo 编译: %%i && Tools\protoc.exe --cpp_out="%cd%/" --proto_path "%cd%/" %%i 
  Tools\protogen.exe -i:"%%i" -o:"%%~dpni.cs" 
)

echo 操作完成，按任意键退出
echo 完成时间 %date:~0,10% %time:~0,8%

pause>nul&exit
