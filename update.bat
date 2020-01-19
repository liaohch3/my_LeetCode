@echo off

set hour=%time:~,2%
if "%time:~,1%"==" " set hour=0%time:~1,1%

echo %date:~0,4%%date:~5,2%%date:~8,2%%hour%%time:~3,2%%time:~6,2%

git add .
git commit -m %date:~0,4%%date:~5,2%%date:~8,2%%hour%%time:~3,2%%time:~6,2%
git push origin master
pause