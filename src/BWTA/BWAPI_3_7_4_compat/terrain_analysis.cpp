#include "Color.h"
#include "VertexData.h"
#include "BWTAfunctions.h"
#include <BWAPI.h>
#include "BWTA.h"
#include "RegionImpl.h"
#include "ChokepointImpl.h"
#include "BaseLocationImpl.h"
#include "BWTA_Result.h"
#include "MapData.h"
#include "Heap.h"


#ifdef DEBUG_DRAW
  #include <QtGui>
  #include <CGAL/Qt/GraphicsViewNavigation.h>
  #include <QLineF>
  #include <QRectF>
#endif


using namespace std;

namespace BWTA
{
    void readMap()
    {
        MapData::mapWidth = BWAPI::Broodwar->mapWidth();
        MapData::mapHeight = BWAPI::Broodwar->mapHeight();
        load_map();
        load_resources();
        MapData::hash = BWAPI::Broodwar->mapHash();
        MapData::startLocations = BWAPI::Broodwar->getStartLocations();
    }

    bool analyze()
    {
        char buf[1000];
        sprintf_s(buf, "bwapi-data/BWTA/%s.bwta", BWAPI::Broodwar->mapHash().c_str());
        std::string filename(buf);
        if (fileExists(filename) && fileVersion(filename) == BWTA_FILE_VERSION) {
            //      log("Recognized map, loading map data...");
            load_data(filename);
            //      log("Loaded map data.");

            return true;
        }

        // it needs to be analyzed
        /*log("Analyzing new map...");
        time_t t1=clock();
        analyze_map();
        time_t t2=clock();
        double seconds = (t2-t1)*1.0/CLOCKS_PER_SEC;
        log("running time: %f",seconds);
        log("Analyzed map.");
        save_data(filename);
        log("Saved map data.");*/

        return false;
    }
}