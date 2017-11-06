#ifndef FIELDQUICKSAND_H
#define FIELDQUICKSAND_H

#include "Field.h"

//------------------------------------------------------------------------------
// Takes additional steps when entered.
//
class FieldQuicksand : public Field
{
private:

  //----------------------------------------------------------------------------
  // Stores how many steps should be subtracted when being entered.
  //
  int malus_;

  //----------------------------------------------------------------------------
  // Default constructor - Should not be used.
  //
  FieldQuicksand() = delete;

  //----------------------------------------------------------------------------
  // Private copy constructor - Should not be used.
  //
  FieldQuicksand(FieldQuicksand &);

public:

  //----------------------------------------------------------------------------
  // copy Constructor
  // @param malus for subtract steps
  //
  FieldQuicksand(int malus);

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
  ~FieldQuicksand();
};

#endif
