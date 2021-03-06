#ifndef FIELDHOLE_H
#define FIELDHOLE_H

#include "Field.h"

//------------------------------------------------------------------------------
// The player gets teleported to the spawn when stepping here.
//
class FieldHole : public Field
{
private:

  //----------------------------------------------------------------------------
  // Private copy constructor - Should not be used.
  //
  FieldHole(FieldHole &);

public:

  //----------------------------------------------------------------------------
  // Creates a new instance.
  //
  FieldHole();

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
  // Deletes this instance.
  //
  ~FieldHole();
};

#endif
