#ifndef _G3ROTTABLE_
#define _G3ROTTABLE_ 1

// This code implementation is the intellectual property of
// the RD44 GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G3RotTable.hh,v 1.6 1999/07/20 14:16:27 lockman Exp $
// GEANT4 tag $Name: geant4-00-01-patch1 $
//
//
// Maps G3 rotation indices to G3toG4RotationMatrix*

#include <rw/tphdict.h>
class G3toG4RotationMatrix;

class G3RotTable {
private:
  RWTPtrHashDictionary<G4String, G3toG4RotationMatrix>* _Rot;
  void HashID(G4int rotid, G4String* _HID);
  void HashID(G4int rotid, G4String& _HID);
public:
  G3RotTable();
  ~G3RotTable();
  G3toG4RotationMatrix* get(G4int rotid);
  void put(G4int rotid, G3toG4RotationMatrix* rotpt);
};

extern G3RotTable G3Rot;
#endif