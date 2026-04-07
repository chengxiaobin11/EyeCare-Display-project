@REM ".\Tool\build\link.bat" "$K" !P @L
@set PATH="%1C51\bin";%PATH%
@"Tool\build\auto_link.exe" --uv "%2" --target "%3" --opt 3 --sort --hex2bin ".\HexToBin.exe"

if exist .\Output\%3\%3_WithChkSum.bin del .\Output\RL6432\%3_WithChkSum.bin
.\AddCheckSum.exe .\Output\RL6432\%3.bin  .\Output\RL6432\%3_WithChkSum.bin BANK1 .\Output\RL6432\HDR.bin HdrBank14
if exist .\Output\RL6432\%3.bin del .\Output\RL6432\%3.bin