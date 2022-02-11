#ifndef CREATURE_H
#define CREATURE_H

#include <iostream>
#include <iomanip>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include "constants.h"
#include "../../!includes/Vector/vector.h"

using namespace std;

struct Location
{
    Location() = default;
    Location(int row, int col) : _row{row}, _col{col} {}

    int _row = 0;
    int _col = 0;

    friend ostream& operator <<(ostream& outs, const Location& l)
    {
        outs << "row: " << l._row << endl;
        outs << "col: " << l._col << endl;
        return outs;
    }
};

class Creature
{
public:
    Creature() : _loc(0,0), _moved{false} {}
    Creature(int row, int col) : _loc(row, col), _moved{false} {}

    // big three?

    virtual void move(Creature* grid[][MAX_COL]);
    virtual void breed(Creature* grid[][MAX_COL]);

    virtual void print(ostream& outs) const;
    virtual int get_type() const {return _type;}

    // allows derived classes to inherit method and dynamically bind the dervied method
    virtual Creature* new_derived(int row, int col) {return new Creature(row, col);}

    // moves the creature to those coordinates/location
    void move_to(Creature* grid[][MAX_COL], Location new_loc);
    // gives vector of blank locations around this creature
    Vector<Location> find_blank(Creature* grid[][MAX_COL]);
    // find same type around this creature
    Vector<Location> find_this_creature(Creature* grid[][MAX_COL], int type);
    // find other/different types around this creature
    Vector<Location> find_not_this_creature(Creature *grid[][MAX_COL], int type);

    // kill this creature
    void kill(Creature *grid[][MAX_COL]);

    void set_moved(int moved) {_moved = moved;}
    int is_moved() {return _moved;}
    int steps() {return _steps;}

    friend ostream& operator <<(ostream& outs, const Creature& c);

protected:
    Location _loc;
    bool _moved = false;
    int _steps = 0;
private:
    int _type = 0;
};

#endif // CREATURE_H
