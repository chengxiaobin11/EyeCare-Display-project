@echo off  
setlocal enabledelayedexpansion  
  

set "EXTENSIONS=m51 obj lst plg lnp __i __b LIB"  
  
del /S *.B0*
del /S *.B1*
del /S *.B2*
del /S *.H0*
del /S *.H1*
del /S *.H2*

for %%e in (%EXTENSIONS%) do (  
    echo Deleting files with extension %%e ...  
    for /r %%f in (*.%%e) do (  
        echo Deleting: %%f  
        del "%%f"  
    )  
)  

for /r %%F in (*) do (  
    set "filename=%%~nF"  
    set "extension=%%~xF"  
      
    if "!extension!"=="" (  
        echo Deleting: %%F  
        del "%%F"  
    )  
) 
  
endlocal