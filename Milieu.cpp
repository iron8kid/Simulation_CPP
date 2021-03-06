#include "Milieu.h"
#include "VisiteurDeplacement.h"
#include <cstdlib>
#include <ctime>
#include <random>


bool testProba(int proba){
   // fonction pour retourner true avec une certaine probabilité
   // on génère un chiffre entre 0 et 99 et on retourne s'il est plus grand que
   // la probabilité moins 100
   // on retournerait vrai le pourcentage de fois indiquée comme paramètre
   return ( (rand() % 100) < proba);
}

const T    Milieu::white[] = { (T)255, (T)255, (T)255 };
const int      Milieu::DEATH_PROB=10;
const int      Milieu::CLONE_PROB=1;
const int      Milieu::NAISSANCE_PROB=1;

Milieu::Milieu( int _width, int _height ) : UImg( _width, _height, 1, 3 ),
                                            width(_width), height(_height)
{

   cout << "const Milieu" << endl;
   comportements = {new Gregaire(), new Kamikaze(), new Peureuse(4), new Prevoyante(), new MultiComportement()};
   cout << "comportemnts len" << comportements.size() << endl;
   std::srand( time(NULL) );
   visiteurDeplacement = new VisiteurDeplacement();

}


Milieu::~Milieu( void )
{
   for (const Comportement *comportement : comportements) {
    delete comportement;
   }
   delete visiteurDeplacement;
   cout << "dest Milieu" << endl;

}

std::vector<Bestiole>& Milieu::getListeBestioles( void )
{
   return listeBestioles;
}

void Milieu::step( void )
{

   cimg_forXY( *this, x, y ) fillC( x, y, 0, white[0], white[1], white[2] );
    auto it_end = listeBestioles.end();
    for ( auto it = listeBestioles.begin() ; it != it_end ; ++it )
   {
       (*it).action( *this );

       (*it).draw( *this );
       (*it).collision();
       if(testProba(CLONE_PROB))
       {
           cout <<"A lucky bestiole will be cloned" << endl;
           addMember(Bestiole((*it)));
       }
       if(it->getcollisionState() && testProba(DEATH_PROB/it->getProtection()))
       {
           cout <<"An unlucky bestiole will die" << endl;
           it->setMustDie(true);
       }

   } // for
   mort( );
   if (testProba(NAISSANCE_PROB))
      naissance(); // naissance avec une probabilité de 20%

}


int Milieu::nbVoisins( const Bestiole & b ) const
{

   int         nb = 0;


   for ( auto it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it )
      if ( !(b == *it) && b.jeTeVois(*it) )
         ++nb;

   return nb;

}


void Milieu::mort( void )
{
   listeBestioles.erase(
   std::remove_if(listeBestioles.begin(), listeBestioles.end(),
        [](const Bestiole & b) {return (b.estTropVieux() || b.getMustDie());}),
   listeBestioles.end());
}

void Milieu::naissance( void ){
   addMember( Bestiole(*this));
}

void Milieu::addMember( const Bestiole & b ){
    listeBestioles.push_back(b);
    listeBestioles.back().initCoords(width, height);
}