#include "predator.h"

// REFACTOR THIS
void Predator::move(Creature* grid[][MAX_COL])
{
    srand(unsigned(time(nullptr)));

    Vector<Location> eat;

    eat = grid[_loc._row][_loc._col]->find_this_creature(grid, PREY);

    if(!eat.empty()) // if was able to eat
    {
        int randIndex = rand() % eat.size();
        // eating a random prey adjecent to it
        move_to(grid, eat.at(randIndex));
        // setting flag to true so it doesnt keep moving
        // whenever it eats, reset starve steps
        _moved = true;
        _steps++;
        // if it eats reset starve counter
        starve_steps = 0;
    }
    else
    {
        // each time it moves without eating add 1 to
        // starve counter
        Creature::move(grid);
        starve_steps++;
        // dies after X amount of steps without eating
        if(starve_steps == STEPS_TIL_DIE)
            kill(grid);
    }
}

void Predator::breed(Creature* grid[][MAX_COL])
{
    Creature::breed(grid);
}

void Predator::print(ostream &outs) const
{
    outs << "X";
}
