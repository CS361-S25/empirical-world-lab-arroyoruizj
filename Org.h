#ifndef ORG_H
#define ORG_H

#include "emp/math/Random.hpp"
#include "emp/tools/string_utils.hpp"

class Organism {
    private:
        double points;
        int species;
        emp::Ptr<emp::Random> random;

    public:

        Organism(emp::Ptr<emp::Random> _random, double _points=0.0, int _species=0) {
            
            points = _points;
            random = _random;
            species = _species;

        }
        

    void SetPoints(double _in) {
        
        points = _in;
    
    }

    void AddPoints(double _in) {
        
        points += _in;
    
    }


    void Process(double add_points) {
        
        points = points + add_points;
       
    }

    int GetSpecies () {

        return species;

    }

    emp::Ptr<Organism> CheckReproduction() {

        if (species == 1) {

            if (points >= 1000) {

                emp::Ptr<Organism> offspring = new Organism(random, 0.0, species);
                points = points - 1000;
                return offspring;
    
            }

        } else if (species == 2) {

            if (points >= 900) {

                emp::Ptr<Organism> offspring = new Organism(random, 0.0, species);
                points = points - 900;
                return offspring;
    
            }
        }
        
        return nullptr;

    }

};
#endif