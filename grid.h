#ifndef GRID_H
#define GRID_H

#include "predator.h"
#include "prey.h"
#include "wall.h"

using namespace std;

class Grid
{
public:
    Grid();

    // calls move, breed, kill
    void step() {move(); breed(); /*kill();*/}

    void move(); // moves the creature
    void breed(); // multiplies the creature
    void kill(); // kills the creature itself

    friend ostream& operator <<(ostream& outs, const Grid& g);

private:
    void fill_grid();
    void reset_moved();

    Creature* _grid[MAX_ROW][MAX_COL];
};

#endif // GRID_H
