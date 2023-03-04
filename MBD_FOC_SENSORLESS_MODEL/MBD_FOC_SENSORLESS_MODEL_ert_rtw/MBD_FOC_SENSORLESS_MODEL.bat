
set MATLAB=D:\Matlab2022b

cd .

if "%1"=="" ("D:\MATLAB~1\bin\win64\gmake"  -f MBD_FOC_SENSORLESS_MODEL.mk all) else ("D:\MATLAB~1\bin\win64\gmake"  -f MBD_FOC_SENSORLESS_MODEL.mk %1)
@if errorlevel 1 goto error_exit

exit /B 0

:error_exit
echo The make command returned an error of %errorlevel%
exit /B 1