//
// ********************************************************************
// * DISCLAIMER                                                       *
// *                                                                  *
// * The following disclaimer summarizes all the specific disclaimers *
// * of contributors to this software. The specific disclaimers,which *
// * govern, are listed with their locations in:                      *
// *   http://cern.ch/geant4/license                                  *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.                                                             *
// *                                                                  *
// * This  code  implementation is the  intellectual property  of the *
// * GEANT4 collaboration.                                            *
// * By copying,  distributing  or modifying the Program (or any work *
// * based  on  the Program)  you indicate  your  acceptance of  this *
// * statement, and all its terms.                                    *
// ********************************************************************
//

// MomoN02PhysicsList.cc 

//  generated by Geant4 Physics Editor at   Thu Mar 14 10:39:12 JST 2002

#include "MomoN02PhysicsList.hh"

#include "globals.hh"
#include "G4ParticleDefinition.hh"
#include "G4ParticleWithCuts.hh"
#include "G4ProcessManager.hh"
#include "G4ProcessVector.hh"
#include "G4ParticleTypes.hh"
#include "G4ParticleTable.hh"
#include "G4ShortLivedConstructor.hh"
#include "G4Material.hh"
#include "G4MaterialTable.hh"

#include "G4ios.hh"

MomoN02PhysicsList::MomoN02PhysicsList():  G4VUserPhysicsList()
{
// Here used the default cut value you have typed in

  defaultCutValue = 1.0*cm;
  SetVerboseLevel(1);
}

MomoN02PhysicsList::~MomoN02PhysicsList()
{}

void MomoN02PhysicsList::ConstructParticle()
{
// Here are constructed all particles you have chosen

  ConstructBosons();
  ConstructLeptons();
  ConstructMesons();
  ConstructBaryons();
  ConstructAllShortLiveds();
}

// In this method, static member functions should be called for ALL particles to be used.

void MomoN02PhysicsList::ConstructBosons()
{
  G4ChargedGeantino::ChargedGeantinoDefinition();
  G4Gamma::GammaDefinition();
  G4Geantino::GeantinoDefinition();
}
void MomoN02PhysicsList::ConstructLeptons()
{
  G4Electron::ElectronDefinition();
  G4Positron::PositronDefinition();
  G4MuonPlus::MuonPlusDefinition();
  G4MuonMinus::MuonMinusDefinition();
  G4NeutrinoE::NeutrinoEDefinition();
  G4AntiNeutrinoE::AntiNeutrinoEDefinition();
  G4NeutrinoMu::NeutrinoMuDefinition();
  G4AntiNeutrinoMu::AntiNeutrinoMuDefinition();
}
void MomoN02PhysicsList::ConstructMesons()
{
  G4PionPlus::PionPlusDefinition();
  G4PionMinus::PionMinusDefinition();
  G4PionZero::PionZeroDefinition();
  G4Eta::EtaDefinition();
  G4KaonPlus::KaonPlusDefinition();
  G4KaonMinus::KaonMinusDefinition();
  G4KaonZero::KaonZeroDefinition();
  G4AntiKaonZero::AntiKaonZeroDefinition();
  G4KaonZeroLong::KaonZeroLongDefinition();
  G4KaonZeroShort::KaonZeroShortDefinition();
}
void MomoN02PhysicsList::ConstructBaryons()
{
  G4Proton::ProtonDefinition();
  G4AntiProton::AntiProtonDefinition();
  G4Neutron::NeutronDefinition();
  G4AntiNeutron::AntiNeutronDefinition();
}
void MomoN02PhysicsList::ConstructAllShortLiveds()
{
// Here are contructed all short liveds

}
void MomoN02PhysicsList::ConstructProcess()
{
// Transportation, electromagnetic and general processes 

  AddTransportation();
  ConstructEM();
  ConstructGeneral();
}
// Here are respective header files for chosen processes

#include "G4GammaConversion.hh"
#include "G4ComptonScattering.hh"
#include "G4PhotoElectricEffect.hh"
#include "G4MultipleScattering.hh"
#include "G4eIonisation.hh"
#include "G4eBremsstrahlung.hh"
#include "G4eplusAnnihilation.hh"
#include "G4MuBremsstrahlung.hh"
#include "G4MuPairProduction.hh"
#include "G4MuIonisation.hh"

// The next two processes are always included.

#include "G4hIonisation.hh"
#include "G4MultipleScattering.hh"
void MomoN02PhysicsList::ConstructEM()
{
  theParticleIterator->reset();
  while( (*theParticleIterator)() ){
    G4ParticleDefinition* particle = theParticleIterator->value();
    G4ProcessManager* pmanager = particle->GetProcessManager();
    G4String particleName = particle->GetParticleName();

// The next processes are always added.

    if ((!particle->IsShortLived()) &&
         (particle->GetPDGCharge() != 0.0 )&&
           (particle->GetParticleName() != "e-") &&
           (particle->GetParticleName() != "e+") &&
           (particle->GetParticleName() != "mu-") &&
           (particle->GetParticleName() != "mu+") &&
           (particle->GetParticleName() != "chargedgeantino")){
      pmanager->AddProcess(new G4MultipleScattering(), -1, 1, 1);
      pmanager->AddProcess(new G4hIonisation(), -1, 2, 2);
    }
// Each if clause corresponds to a row in the PhysicsTable

    if (particleName == "gamma") {
      pmanager->AddProcess(new G4GammaConversion(),ordInActive,ordInActive,ordDefault);
    }
    if (particleName == "gamma") {
      pmanager->AddProcess(new G4ComptonScattering(),ordInActive,ordInActive,ordDefault);
    }
    if (particleName == "gamma") {
      pmanager->AddProcess(new G4PhotoElectricEffect(),ordInActive,ordInActive,ordDefault);
    }
    if (particleName == "e-") {
      pmanager->AddProcess(new G4MultipleScattering(),ordInActive,1,1);
    }
    if (particleName == "e-") {
      pmanager->AddProcess(new G4eIonisation(),ordInActive,2,2);
    }
    if (particleName == "e-") {
      pmanager->AddProcess(new G4eBremsstrahlung(),ordInActive,ordInActive,3);
    }
    if (particleName == "e+") {
      pmanager->AddProcess(new G4eIonisation(),ordInActive,2,2);
    }
    if (particleName == "e+") {
      pmanager->AddProcess(new G4eBremsstrahlung(),ordInActive,ordInActive,3);
    }
    if (particleName == "e+") {
      pmanager->AddProcess(new G4eplusAnnihilation(),ordDefault,ordInActive,4);
    }
    if (particleName == "e+") {
      pmanager->AddProcess(new G4MultipleScattering(),ordInActive,1,1);
    }
    if (particleName == "mu+") {
      pmanager->AddProcess(new G4MultipleScattering(),ordInActive,1,1);
    }
    if (particleName == "mu+") {
      pmanager->AddProcess(new G4MuBremsstrahlung(),ordInActive,ordInActive,3);
    }
    if (particleName == "mu+") {
      pmanager->AddProcess(new G4MuPairProduction(),ordInActive,ordInActive,4);
    }
    if (particleName == "mu+") {
      pmanager->AddProcess(new G4MuIonisation(),ordInActive,2,2);
    }
    if (particleName == "mu-") {
      pmanager->AddProcess(new G4MultipleScattering(),ordInActive,1,1);
    }
    if (particleName == "mu-") {
      pmanager->AddProcess(new G4MuBremsstrahlung(),ordInActive,ordInActive,3);
    }
    if (particleName == "mu-") {
      pmanager->AddProcess(new G4MuIonisation(),ordInActive,2,2);
    }
    if (particleName == "mu-") {
      pmanager->AddProcess(new G4MuPairProduction(),ordInActive,ordInActive,4);
    }
  }
}

#include "G4Decay.hh"

void MomoN02PhysicsList::ConstructGeneral()
{
  G4Decay* theDecayProcess = new G4Decay();
  theParticleIterator->reset();
  while( (*theParticleIterator)() ){
    G4ParticleDefinition* particle = theParticleIterator->value();
    G4ProcessManager* pmanager = particle->GetProcessManager();
    if (theDecayProcess->IsApplicable(*particle)) {
      pmanager ->AddProcess(theDecayProcess);
      pmanager ->SetProcessOrdering(theDecayProcess, idxPostStep);
      pmanager ->SetProcessOrdering(theDecayProcess, idxAtRest);
    }
  }
}

void MomoN02PhysicsList::SetCuts()
{
// defaultCutValue you have typed in is used

  if (verboseLevel >1){
    G4cout << "MomoN02PhysicsList::SetCuts:";
  }
  SetCutsWithDefault();
}
