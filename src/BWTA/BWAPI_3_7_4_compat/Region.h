#pragma once

#include <BWAPI.h>
#include <set>

#include "Polygon.h"


namespace BWTA
{
  class Chokepoint;
  class BaseLocation;
  class Region
  {
  public:
    virtual const Polygon& getPolygon() const=0;
    virtual const BWAPI::Position& getCenter() const=0;
    virtual const std::set<BWTA::Chokepoint*>& getChokepoints() const=0;
    virtual const std::set<BaseLocation*>& getBaseLocations() const=0;
    virtual bool isReachable(Region* region) const=0;
    virtual const std::set<Region*>& getReachableRegions() const=0;
  };
}