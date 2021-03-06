#include "Carapace.h"
#include <random>

const double      Carapace::MAX_PROTECTION = 50;
const double      Carapace::MAX_RALENTISSEMENT = 1.2;
Carapace::Carapace( void ) // Initialisation avec paramètres aléatoires.
{
	protection = (double)(rand()) / (1+(double)(RAND_MAX/(MAX_PROTECTION-1)));
	ralentissement = (double)(rand()) / (1+(double)(RAND_MAX/(MAX_RALENTISSEMENT-1)));

}

Carapace::Carapace( double temp ) // Initialisation avec paramètres normaux (sans changements).
{
	protection = 1.;
	ralentissement = 1.;

}


double Carapace::getRalentissement( void ) const
{
	return ralentissement;
}

double Carapace::getProtection( void ) const
{
	return protection;
}