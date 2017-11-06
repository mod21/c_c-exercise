#ifndef FIELDCOUNTER_H
#define FIELDCOUNTER_H

#include "Field.h"

//------------------------------------------------------------------------------
// The player can only enter here a limited number of times.
//
class FieldCounter : public Field
{
private:

  //----------------------------------------------------------------------------
  // Private copy constructor - Should not be used.
  //
  FieldCounter(FieldCounter &);

  //----------------------------------------------------------------------------
  // The amount of steps a player can take on this field.
  //
  int steps_;

public:

  //----------------------------------------------------------------------------
  // Creates a new instance.
  // @param steps The number of steps that can be taken.
  //
  FieldCounter(int steps);

  //----------------------------------------------------------------------------
  // Called when the player tries to enter a field.
  // @param player The current player.
  // @param position The position where the player is entering.
  // @param direction The direction the player is entering from.
  // @return Whether the player can enter here.
  //
  virtual bool onEnter(Player* player, CoordPair position,
    Direction* direction);

  //----------------------------------------------------------------------------
  // Called when the player tries to leave a field.
  // @param player The current player.
  // @param position The position the player is leaving to.
  // @param direction The direction the player is leaving to.
  // @return Whether the player can leave here.
  //
  virtual bool onLeave(Player* player, CoordPair position,
    Direction* direction);

  //----------------------------------------------------------------------------
  // Returns the symbol used to display this field.
  // @param player The current player.
  // @param player The position of the field.
  // @return A character.
  //
  virtual char getDisplaySymbol(Player* player, CoordPair position);

  //----------------------------------------------------------------------------
  // Deletes this instance.
  //
  ~FieldCounter();

  //----------------------------------------------------------------------------
  // The maximum number of steps that can be taken here.
  // @returns A positive whole number.
  //
  int getStepCount();

};

#endif
