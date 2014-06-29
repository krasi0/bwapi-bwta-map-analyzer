#pragma once
#include <BWAPI.h>
#include <set>

#include "Polygon.h"
#include "Region.h"
#include "BaseLocation.h"


namespace BWTA
{
  class Chokepoint;
  class RegionImpl : public Region
  {
  public:
    RegionImpl();
    RegionImpl(Polygon &poly);
    virtual const Polygon& getPolygon() const;
    virtual const BWAPI::Position& getCenter() const;
    virtual const std::set<Chokepoint*>& getChokepoints() const;
    virtual const std::set<BaseLocation*>& getBaseLocations() const;
    virtual bool isReachable(Region* region) const;
    virtual const std::set<Region*>& getReachableRegions() const;
    Polygon _polygon;
    BWAPI::Position _center;
    std::set<Chokepoint*> _chokepoints;
    std::set<BaseLocation*> baseLocations;
    std::set<Region*> reachableRegions;
  };
}