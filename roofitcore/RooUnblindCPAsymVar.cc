/*****************************************************************************
 * Project: BaBar detector at the SLAC PEP-II B-factory
 * Package: RooFitCore
 *    File: $Id: RooUnblindCPAsymVar.cc,v 1.5 2001/04/20 01:51:39 verkerke Exp $
 * Authors:
 *   DK, David Kirkby, Stanford University, kirkby@hep.stanford.edu
 *   WV, Wouter Verkerke, UC Santa Barbara, verkerke@slac.stanford.edu
 * History:
 *   07-Mar-2001 WV Created initial version
 *
 * Copyright (C) 2001 University of California
 *****************************************************************************/

#include "RooFitCore/RooUnblindCPAsymVar.hh"
#include "RooFitCore/RooArgSet.hh"


ClassImp(RooUnblindCPAsymVar)
;


RooUnblindCPAsymVar::RooUnblindCPAsymVar() : _blindEngine("") 
{
}


RooUnblindCPAsymVar::RooUnblindCPAsymVar(const char *name, const char *title,
					     const char *blindString, RooAbsReal& cpasym)
  : RooDerivedReal(name,title), _blindEngine(blindString), _asym("asym","CP Asymmetry",this,cpasym) 
{  
}


RooUnblindCPAsymVar::RooUnblindCPAsymVar(const RooUnblindCPAsymVar& other, const char* name) : 
  RooDerivedReal(other, name), _blindEngine(other._blindEngine), _asym("asym",this,other._asym)
{
}


RooUnblindCPAsymVar::~RooUnblindCPAsymVar() 
{
}


Double_t RooUnblindCPAsymVar::evaluate() const
{
  return _blindEngine.UnHideAsym(_asym);
}


Bool_t RooUnblindCPAsymVar::isValid() const
{
  return isValid(getVal()) ;
}


Bool_t RooUnblindCPAsymVar::isValid(Double_t value, Bool_t verbose) const
{
  return kTRUE ;
}


void RooUnblindCPAsymVar::printToStream(ostream& os, PrintOption opt, TString indent) const
{
  // Print current value and definition of formula
  os << indent << "RooUnblindCPAsymVar: " << GetName() << " : (value hidden) asym=" 
     << _asym.arg().GetName() ;
  if(!_unit.IsNull()) os << ' ' << _unit;
  printAttribList(os) ;
  os << endl ;
} 


Bool_t RooUnblindCPAsymVar::readFromStream(istream& is, Bool_t compact, Bool_t verbose)
{
  cout << "RooUnblindCPAsymVar::readFromStream(" << GetName() << "): not allowed" << endl ;
  return kTRUE ;
}


void RooUnblindCPAsymVar::writeToStream(ostream& os, Bool_t compact) const
{
  cout << "RooUnblindCPAsymVar::writeToStream(" << GetName() << "): not allowed" << endl ;
}



