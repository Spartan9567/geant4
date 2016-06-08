// This code implementation is the intellectual property of
// the RD44 GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4VVisCommand.hh,v 1.3 1999/05/10 14:04:05 johna Exp $
// GEANT4 tag $Name: geant4-00-01 $

// Base class for visualization commands - John Allison  9th August 1998
// It is really a messenger - we have one command per messenger.

#ifndef G4VVISCOMMAND_HH
#define G4VVISCOMMAND_HH

#include "G4UImessenger.hh"

class G4VisManager;
class G4UIcommand;
class G4UIcmdWithAString;

class G4VVisCommand: public G4UImessenger {
public:
  // Uses compiler defaults for copy constructor and assignment.
  G4VVisCommand ();
  virtual ~G4VVisCommand ();
  static void SetVisManager (G4VisManager*);
protected:
  static G4VisManager* fpVisManager;
  // Commands which need to be accessed by other messengers...
  static G4UIcmdWithAString* fpCommandSceneNotifyHandlers;
  static G4UIcmdWithAString* fpCommandSceneRemove;
  static G4UIcmdWithAString* fpCommandSceneSelect;
  static G4UIcmdWithAString* fpCommandSceneHandlerAttach;
  static G4UIcmdWithAString* fpCommandSceneHandlerRemove;
  static G4UIcmdWithAString* fpCommandSceneHandlerSelect;
  static G4UIcommand*        fpCommandViewerCreate;
  static G4UIcmdWithAString* fpCommandViewerRemove;
  static G4UIcmdWithAString* fpCommandViewerSelect;
};

#include "G4VVisCommand.icc"

#endif