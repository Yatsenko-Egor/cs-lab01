p1.exe < test1.txt > result1.txt 2>NUL
fc /N test1-expected.txt result1.txt 
pause