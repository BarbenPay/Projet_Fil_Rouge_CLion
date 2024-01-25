main.out: main.o Regroupement.o fichier_Log.o Decoupage.o Analyse.o Menu.o
	gcc -o main.out main.o Regroupement.o fichier_Log.o Decoupage.o Analyse.o Menu.o

main.o: main.c Regroupement/Regroupement.h Log/logFile.h Découpage/Decoupage.h
	gcc -c main.c -o main.o

Regroupement.o: Regroupement/Regroupement.c Regroupement/Regroupement.h Log/logFile.h
	gcc -c Regroupement/Regroupement.c -o Regroupement.o

fichier_Log.o: Log/logFile.c Log/logFile.h
	gcc -c Log/fichier_Log.c -o fichier_Log.o

Decoupage.o: Découpage/Decoupage.c Découpage/Decoupage.h Log/logFile.h
	gcc -c Découpage/Decoupage.c -o Decoupage.o

Analyse.o: Analyse_Phrase/Analyse.c Analyse_Phrase/Analyse.h
	gcc -c Analyse_Phrase/Analyse.c -o Analyse.o

Menu.o: Menu/menu.c Menu/menu.h
	gcc -c Menu/menu.c -o Menu.o

clean:
	rm -rf *.o