@echo off
REM ------------------------------------
REM Script to build custom DLL mylib.dll
REM ------------------------------------

setlocal

call "C:\Program Files\Microsoft Visual Studio 8\VC\vcvarsall.bat"

cl -nologo -MD -Ox -DWIN32 -DWINDOWS -c -GF -Ob2 -DNDEBUG -I "%DBLDIR%csrc" power.c
lib -nologo -def:mylib.def -out:mylib.lib power.obj "%DBLDIR%lib\xclapi.obj"
link -nologo -opt:ref -dll -out:mylib.dll power.obj mylib.exp "%DBLDIR%lib\xclapi.obj" "%DBLDIR%lib\xclapif.obj"

REM This command only required if using Visual Studio 2005
mt -nologo -manifest mylib.dll.manifest  -outputresource:mylib.dll;2

endlocal

dbl -dXT power.dbl
dblink -d power

del mylib.dll.manifest
del mylib.exp
del mylib.lib
del power.obj
del power.dbo

dbs power

pause