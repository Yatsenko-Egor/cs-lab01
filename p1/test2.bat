p1.exe < test2.txt > result2.txt 2>NUL
fc /N test2-expected.txt result2.txt 
pause