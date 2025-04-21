#ifndef ORG_H
#define ORG_H

#include "emp/math/Random.hpp"
#include "emp/tools/string_utils.hpp"

class Organism {
    private:
        double points;
        emp::Ptr<emp::Random> random;

    public:
    Organism(emp::Ptr<emp::Random> _random, double _points=0.0) :
        points(_points), random(_random) {;}

    void SetPoints(double _in) {points = _in;}
    void AddPoints(double _in) {points += _in;}


    void Process(double add_points) {
        
        points = points + add_points;
        std::cout << "Processing" << std::endl; //feel free to get rid of this
       
    }

    emp::Ptr<Organism> CheckReproduction() {

        if (points >= 1000) {

            emp::Ptr<Organism> offspring = new Organism(random, 0.0);
            points = points - 1000;
            return offspring;

        }

        else {

            return nullptr;
        }
    }

};
#endif