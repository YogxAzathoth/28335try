cd .

if "%1"=="" ("D:\MATLAB~1\bin\win64\gmake"  -B -f PV_MPPT_C2000_Algorithm_try.mk all) else ("D:\MATLAB~1\bin\win64\gmake"  -B -f PV_MPPT_C2000_Algorithm_try.mk %1)
@if errorlevel 1 goto error_exit

exit 0

:error_exit
echo The make command returned an error of %errorlevel%
exit 1
