CPP_FLAGS = -Wall  -std=c++11

main : main.cpp Aquarium.o Bestiole.o Milieu.o Comportement.o Gregaire.o Kamikaze.o Peureuse.o Prevoyante.o VisiteurDeplacement.o Oeil.o
	g++ $(CPP_FLAGS) -o main main.cpp Aquarium.o Bestiole.o Milieu.o Comportement.o Gregaire.o Kamikaze.o Peureuse.o Prevoyante.o VisiteurDeplacement.o Oeil.o -I . -lX11 -lpthread

Aquarium.o : Aquarium.h Aquarium.cpp Milieu.h
	g++ $(CPP_FLAGS) -c Aquarium.cpp -I .

Bestiole.o : Bestiole.h Bestiole.cpp Capteurs/Oeil.h
	g++ $(CPP_FLAGS) -c Bestiole.cpp -I .

Milieu.o : Milieu.h Milieu.cpp Bestiole.h Visiteur.h # Comportements/Comportement.h Comportements/Gregaire.h Comportements/Kamikaze.h Comportements/Peureuse.h Comportements/Prevoyante.h
	g++ $(CPP_FLAGS) -c Milieu.cpp -I .

Comportement.o : Comportements/Comportement.h Comportements/Comportement.cpp
	g++ $(CPP_FLAGS) -c Comportements/Comportement.cpp -I .	

Gregaire.o : Comportements/Gregaire.h Comportements/Gregaire.cpp Comportements/Comportement.h Visiteur.h
	g++ $(CPP_FLAGS) -c Comportements/Gregaire.cpp -I .	

Kamikaze.o : Comportements/Kamikaze.h Comportements/Kamikaze.cpp Comportements/Comportement.h Visiteur.h
	g++ $(CPP_FLAGS) -c Comportements/Kamikaze.cpp -I .	

Peureuse.o : Comportements/Peureuse.h Comportements/Peureuse.cpp Comportements/Comportement.h Visiteur.h
	g++ $(CPP_FLAGS) -c Comportements/Peureuse.cpp -I .

Prevoyante.o : Comportements/Prevoyante.h Comportements/Prevoyante.cpp Comportements/Comportement.h Visiteur.h
	g++ $(CPP_FLAGS) -c Comportements/Prevoyante.cpp -I .	

VisiteurDeplacement.o : VisiteurDeplacement.cpp VisiteurDeplacement.h #Comportements/Kamikaze.h Comportements/Gregaire.h Comportements/Prevoyante.h Comportements/Peureuse.h Bestiole.h
	g++ $(CPP_FLAGS) -c VisiteurDeplacement.cpp -I .

Oeil.o : Capteurs/Oeil.cpp Capteurs/Oeil.h
	g++ $(CPP_FLAGS) -c Capteurs/Oeil.cpp -I .

clean :
	rm *.o main

