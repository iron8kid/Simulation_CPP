#ifndef _NAGEOIRE
#define _NAGEOIRE

class Nageoire
{

private :
   static const double     MAX_VITESSE_NAGEOIRE;
   double            vitesseNageoire;


public :
	Nageoire( void );
	Nageoire( double temp );
	double getVitesseNageoire( void ) const;

};

#endif