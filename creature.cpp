#include "creature.h"

void Creature::move(Creature* grid[][MAX_COL])
{
    srand(unsigned(time(nullptr)));

    Vector<Location> blanks;

    blanks = grid[_loc._row][_loc._col]->find_blank(grid);

    // if given vector has no locations available it will stop
    if(!blanks.empty())
    {
        int randIndex = rand() % blanks.size();
        // moving to a random blank location within the vector
        move_to(grid, blanks.at(randIndex));
        // setting flag to true so it doesnt keep moving
        _moved = true;
        _steps++;
    }
}


void Creature::breed(Creature* grid[][MAX_COL])
{
    srand(unsigned(time(nullptr)));

    Vector<Location> blanks;

    blanks = grid[_loc._row][_loc._col]->find_blank(grid);

    // if given vector has no locations available it will stop
    if(!blanks.empty())
    {
        int randIndex = rand() % blanks.size();

        int breedhere_row = blanks.at(randIndex)._row;
        int breedhere_col = blanks.at(randIndex)._col;

        // derived class will inherit breed(), derived classes predator and prey
        // dynamically binds the derived class's method to return a new subclass
        grid[breedhere_row][breedhere_col] = new_derived(breedhere_row, breedhere_col);

    }
     // reseting amount stepped whether it bred or not
    _steps = 0;
}

void Creature::print(ostream &outs) const
{
    outs << "C";
}

void Creature::move_to(Creature* grid[][MAX_COL], Location new_loc)
{
    grid[new_loc._row][new_loc._col] = this;
    grid[_loc._row][_loc._col] = nullptr;
    _loc = new_loc;
}

Vector<Location> Creature::find_blank(Creature* grid[][MAX_COL])
{
    Vector<Location> blanks;

    // checking adjacent cells
    if(grid[_loc._row+1][_loc._col] == nullptr)
        blanks.push_back(Location(_loc._row+1, _loc._col));
    if(grid[_loc._row][_loc._col+1] == nullptr)
        blanks.push_back(Location(_loc._row, _loc._col+1));
    if(grid[_loc._row-1][_loc._col] == nullptr)
        blanks.push_back(Location(_loc._row-1, _loc._col));
    if(grid[_loc._row][_loc._col-1] == nullptr)
        blanks.push_back(Location(_loc._row, _loc._col-1));

    return blanks;
}

Vector<Location> Creature::find_this_creature(Creature *grid[][MAX_COL], int type)
{
    Vector<Location> these_creatures;

    // checking adjacent cells
    if((grid[_loc._row+1][_loc._col] != nullptr) &&
            (grid[_loc._row+1][_loc._col]->get_type() == type))
        these_creatures.push_back(Location(_loc._row+1, _loc._col));
    if((grid[_loc._row][_loc._col+1] != nullptr) &&
            (grid[_loc._row][_loc._col+1]->get_type() == type))
        these_creatures.push_back(Location(_loc._row, _loc._col+1));
    if((grid[_loc._row-1][_loc._col] != nullptr) &&
            (grid[_loc._row-1][_loc._col]->get_type() == type))
        these_creatures.push_back(Location(_loc._row-1, _loc._col));
    if((grid[_loc._row][_loc._col-1] != nullptr) &&
            (grid[_loc._row][_loc._col-1]->get_type() == type))
        these_creatures.push_back(Location(_loc._row, _loc._col-1));

    return these_creatures;
}

Vector<Location> Creature::find_not_this_creature(Creature *grid[][MAX_COL], int type)
{
    Vector<Location> not_these_creatures;

    // Maybe add && not nullptr and wall?
    if((grid[_loc._row+1][_loc._col] != nullptr) &&
            (grid[_loc._row+1][_loc._col]->get_type() != type))
        not_these_creatures.push_back(Location(_loc._row+1, _loc._col));
    if((grid[_loc._row][_loc._col+1] != nullptr) &&
            (grid[_loc._row][_loc._col+1]->get_type() != type))
        not_these_creatures.push_back(Location(_loc._row, _loc._col+1));
    if((grid[_loc._row-1][_loc._col] != nullptr) &&
            (grid[_loc._row-1][_loc._col]->get_type() != type))
        not_these_creatures.push_back(Location(_loc._row-1, _loc._col));
    if((grid[_loc._row][_loc._col-1] != nullptr) &&
            (grid[_loc._row][_loc._col-1]->get_type() != type))
        not_these_creatures.push_back(Location(_loc._row, _loc._col-1));

    return not_these_creatures;
}

void Creature::kill(Creature *grid[][MAX_COL])
{
    grid[_loc._row][_loc._col] = nullptr;
    delete this;
}

ostream& operator <<(ostream &outs, const Creature &c)
{
    c.print(outs);
    return outs;
}
