menu.out: menu.o
	gcc -o menu.out menu.o

menu.o: menu.c
	gcc -c menu.c -o menu.o

main.out: main.o Regroupement.o fichier_Log.o Decoupage.o Analyse.o
	gcc -o main.out main.o Regroupement.o fichier_Log.o Decoupage.o Analyse.o

main.o: main.c Regroupement/Regroupement.h Log/fichier_Log.h Découpage/Decoupage.h
	gcc -c main.c -o main.o

Regroupement.o: Regroupement/Regroupement.c Regroupement/Regroupement.h Log/fichier_Log.h
	gcc -c Regroupement/Regroupement.c -o Regroupement.o

fichier_Log.o: Log/fichier_Log.c Log/fichier_Log.h
	gcc -c Log/fichier_Log.c -o fichier_Log.o

Decoupage.o: Découpage/Decoupage.c Découpage/Decoupage.h Log/fichier_Log.h
	gcc -c Découpage/Decoupage.c -o Decoupage.o
	
Analyse.o: Analyse_Phrase/Analyse.c Analyse_Phrase/Analyse.h
	gcc -c Analyse_Phrase/Analyse.c -o Analyse.o

clean:
	rm -rf *.o
