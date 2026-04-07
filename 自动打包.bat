@echo off

::要压缩的文件后缀
set "FILE_TO_COMPRESS=uvproj uvopt bak WK3 SearchResults PS PRI PR PO PFI IMD IMB IAD IAB Bak Uv2 Opt"

::设置压缩后的文件名
set ZIP_DESTINATION="SourceInsight_And_Keil.zip"

for %%e in (%FILE_TO_COMPRESS%) do (
    echo Compress files with extension %%e ...  
    for %%f in (*.%%e) do (  
    	::将该路径改为你的电脑上7z.exe的路径
        "D:\7z\7z.exe" a -tzip -r %ZIP_DESTINATION% "%%f"
    )  
)

set /p DELETE_INPUT="是否删除原文件(Y/N,默认N)"

if /i %DELETE_INPUT%==Y (
	
	for %%e in (%FILE_TO_COMPRESS%) do (
    echo Deleting files with extension %%e ...  
	
    for %%f in (*.%%e) do (
        echo Deleting: %%f  
        del "%%f"  
    )  
	)  
)
