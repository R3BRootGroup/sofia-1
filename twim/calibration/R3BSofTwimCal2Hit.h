// -------------------------------------------------------------
// -----                                                   -----
// -----             R3BSofTwimCal2Hit                     -----
// -----    Created 30/11/19  by J.L. Rodriguez-Sanchez    -----
// -------------------------------------------------------------

#ifndef R3BSofTwimCal2Hit_H
#define R3BSofTwimCal2Hit_H

#include "FairTask.h"
#include "R3BSofTwimHitData.h"
#include "TH1F.h"
#include "TVectorD.h"
#include <TRandom.h>

class TClonesArray;
class R3BSofTwimHitPar;

class R3BSofTwimCal2Hit : public FairTask
{

  public:
    /** Default constructor **/
    R3BSofTwimCal2Hit();

    /** Standard constructor **/
    R3BSofTwimCal2Hit(const char* name, Int_t iVerbose = 1);

    /** Destructor **/
    virtual ~R3BSofTwimCal2Hit();

    /** Virtual method Exec **/
    virtual void Exec(Option_t* option);

    /** Virtual method Reset **/
    virtual void Reset();

    virtual void SetParContainers();

    // Fair specific
    /** Virtual method Init **/
    virtual InitStatus Init();

    /** Virtual method ReInit **/
    virtual InitStatus ReInit();

    /** Virtual method Finish **/
    virtual void Finish();

    /** Method to select online mode **/
    void SetOnline(Bool_t option) { fOnline = option; }
    void SetExpId(Int_t exp) { fExpId = exp; }

  private:
    void SetParameter();
    /** Private method Experiment s455 **/
    virtual void S455();
    /** Private method Experiment s467 **/
    virtual void S467();

    Bool_t fOnline; // Don't store data for online
    Int_t fExpId;

    Int_t fNumSec; // Number of sections
    Int_t fNumAnodes;
    Int_t fNumAnodesAngleFit;
    Int_t fNumParams;
    Float_t fZ0[4], fZ1[4], fZ2[4];
    Int_t StatusAnodes[4][16]; // Sections and anodes
    Double_t fPosAnodes[16];   // Position-Z of each anode
    TArrayF* CalZTofParams;
    TArrayF* CalZParams;
    TVectorD fPosZ;

    R3BSofTwimHitPar* fCal_Par;   /**< Parameter container. >*/
    TClonesArray* fTwimCalDataCA; /**< Array with Twim Cal-input data. >*/
    TClonesArray* fTwimHitDataCA; /**< Array with Twim Hit-output data. >*/
    TClonesArray* fHitItemsTofW;  /**< Array with tofw-hit items. */

    /** Private method TwimHitData **/
    //** Adds a TwimHitData to the detector
    R3BSofTwimHitData* AddHitData(UShort_t secID, Double_t theta, Double_t charge_z);
    R3BSofTwimHitData* AddHitData(UShort_t secID, Double_t theta, Double_t charge_z, Double_t ene_ave);

  public:
    // Class definition
    ClassDef(R3BSofTwimCal2Hit, 1)
};

#endif