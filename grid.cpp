#include "grid.h"

Grid::Grid()
{
    fill_grid();
}

void Grid::move()
{
    // resetting moved flag to false for all objects
    reset_moved();

    for(int i = 0; i < MAX_ROW; i++)
    {
        for(int j = 0; j < MAX_COL; j++)
        {
            if(_grid[i][j] != nullptr)
            {
                // Predator moves before prey
                if(_grid[i][j]->get_type() == PREDATOR)
                {
                    if(_grid[i][j]->is_moved() == false)
                        _grid[i][j]->move(_grid);
                }
                // checking if prey(2) and if it has moved already
                else if(_grid[i][j]->get_type() == PREY)
                {
                    if(_grid[i][j]->is_moved() == false)
                        _grid[i][j]->move(_grid);
                }
            }
        }
    }
}

void Grid::breed()
{
    for(int i = 0; i < MAX_ROW; i++)
    {
        for(int j = 0; j < MAX_COL; j++)
        {
            if(_grid[i][j] != nullptr)
            {
                // checking if prey(2) and if it has moved already
                if(_grid[i][j]->get_type() == PREY)
                {
                    // ensures steps are always less than how much to breed
                    assert(_grid[i][j]->steps() <= BREED_FOR_PREY);
                    if(_grid[i][j]->steps() == BREED_FOR_PREY)
                        _grid[i][j]->breed(_grid);
                }
                if(_grid[i][j]->get_type() == PREDATOR)
                {
                    assert(_grid[i][j]->steps() <= BREED_FOR_PREDATOR);
                    if(_grid[i][j]->steps() == BREED_FOR_PREDATOR)
                        _grid[i][j]->breed(_grid);
                }
            }
        }
    }
}

void Grid::kill()
{
    for(int i = 0; i < MAX_ROW; i++)
    {
        for(int j = 0; j < MAX_COL; j++)
        {
            if(_grid[i][j] != nullptr)
                _grid[i][j]->kill(_grid);
        }
    }
}

ostream& operator <<(ostream &outs, const Grid &g)
{
    for(int i = 0; i < MAX_ROW; i++)
    {
        for(int j = 0; j < MAX_COL; j++)
        {
            if(g._grid[i][j] ==  nullptr)
                outs << "| |";
            else
                outs << "|" << *(g._grid[i][j]) << "|";
        }
        outs << endl;
    }
    return outs;
}

void Grid::fill_grid()
{
    for(int i = 0; i < MAX_ROW; i++)
    {
        for(int j = 0; j < MAX_COL; j++)
        {
            if(i == 0)
                _grid[i][j] = new Wall;
            else if(j == 0)
                _grid[i][j] = new Wall;
            else if(i == MAX_ROW -1)
                _grid[i][j] = new Wall;
            else if(j == MAX_COL -1)
                _grid[i][j] = new Wall;
            else
                _grid[i][j] = nullptr;
        }
    }

    srand(unsigned(time(nullptr)));

    for(int i = 0; i < 100; i++)
    {
        // -3 so it wont put a creature in the walls
        int x = rand() % (MAX_ROW - 3) + 1;
        int y = rand() % (MAX_COL - 3) + 1;
        if(_grid[x][y] == nullptr)
            _grid[x][y] = new Prey(x,y);
    }

    for(int i = 0; i < 5; i++)
    {
        int x = rand() % (MAX_ROW - 3) + 1;
        int y = rand() % (MAX_COL - 3) + 1;
        if(_grid[x][y] == nullptr)
            _grid[x][y] = new Predator(x,y);
    }
}

void Grid::reset_moved()
{
    for(int i = 0; i < MAX_ROW; i++)
    {
        for(int j = 0; j < MAX_COL; j++)
        {
            if(_grid[i][j] != nullptr)
            {
                _grid[i][j]->set_moved(false);
            }
        }
    }
}
