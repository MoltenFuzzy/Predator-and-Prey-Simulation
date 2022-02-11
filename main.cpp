/*
 * Author: Kent Phan
 * Project: Predator and Prey
 * Purpose: A simulation of a predator clearing the prey
            population and the prey multiplying.
            This cycle continues forever, but the random positions
            may allow one side to wipe out another.
*/

#include <iostream>
#include "grid.h"

using namespace std;

int main()
{
    Grid g;
    int count = 0;
    while(true)
    {
        cout << "Generation: " << count << endl << endl;
        cout << g << endl;
        g.step();
        cin.get();
        count++;
    }
    return 0;
}
