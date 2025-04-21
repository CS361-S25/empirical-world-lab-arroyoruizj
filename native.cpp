#include <iostream>

#include "Org.h"
#include "emp/base/vector.hpp"
#include "emp/math/random_utils.hpp"
#include "emp/math/Random.hpp"

#include "World.h"

// This is the main function for the NATIVE version of this project.

int main(int argc, char* argv[]) {

  emp::Random random(444);
  OrgWorld world(random);

  Organism* new_org = new Organism(&random, 1.2);
  world.Inject(*new_org);
  world.Resize(10, 10);

  std::cout << "Number of organisms: " << world.GetNumOrgs() << std::endl;

  for (int i = 0; i < 10; i++) {

    world.Update();

  }

}
