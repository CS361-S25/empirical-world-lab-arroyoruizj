#ifndef WORLD_H
#define WORLD_H

#include "emp/Evolve/World.hpp"
#include "emp/math/random_utils.hpp"
#include "emp/math/Random.hpp"

#include "Org.h"

class OrgWorld : public emp::World<Organism> {

    emp::Random &random;
    emp::Ptr<emp::Random> random_ptr;

    public:

    OrgWorld(emp::Random &_random) : emp::World<Organism>(_random), random(_random) {

        random_ptr.New(_random);

    }

    ~OrgWorld() {

    }

  void Update() {

    // First, let the base World class handle its updates
    emp::World<Organism>::Update();

    emp::vector<size_t> schedule = emp::GetPermutation(random, GetSize());

        for (int i : schedule) {

            if (!IsOccupied(i)) {

                continue; 

            }

            // Get a pointer to the organism at this location
            Organism* organism = pop[i];

            // Call the Process method of the organism
            organism->Process(100);

            MoveOrganism(i);

        }

    // d. Create another schedule for checking reproduction after everyone has received points
    emp::vector<size_t> repro_schedule = emp::GetPermutation(random, GetSize());

        // Loop through the reproduction schedule
        for (size_t i : repro_schedule) {

            if (IsOccupied(i)) {

                // e. Check if the organism reproduces
                emp::Ptr<Organism> offspring = pop[i]->CheckReproduction();

                if (offspring) {

                    DoBirth(*offspring, i); // Add the offspring to the population
                
                }
            }
        }
    }

    emp::Ptr<Organism> ExtractOrganism(size_t location) {

        if (!IsOccupied(location)) {
            return nullptr; // Or handle this case as appropriate
        }

        emp::Ptr<Organism> organism = pop[location];
        pop[location] = nullptr;
        return organism;
    }

    void MoveOrganism(size_t old_location) {

        if (!IsOccupied(old_location)) {

            return;

        }

        emp::Ptr<Organism> organism = ExtractOrganism(old_location);

        if (organism) {

            emp::WorldPosition new_location = GetRandomNeighborPos(old_location);
            // Only move if the new location is not occupied
            if (!IsOccupied(new_location)) {

                AddOrgAt(organism, new_location);

            } 

            else {
                // If the new location is occupied, you might want to handle this
                // differently, e.g., put the organism back in its original spot
                AddOrgAt(organism, old_location);

            }
        }
    }
    
};

#endif