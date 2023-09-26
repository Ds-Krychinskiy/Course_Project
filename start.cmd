g++ -IC:\SFML-2.6.0\include -c .\main.cpp -o main.o  
g++ -LC:\SFML-2.6.0\lib .\main.o -o app.exe -lmingw32 -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-network -lsfml-system
pause