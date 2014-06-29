#pragma once
//#define DEBUG_DRAW 1

// BWTA_DEBUG_DRAW can be set via cmake-gui
#if defined(BWTA_DEBUG_DRAW) && BWTA_DEBUG_DRAW == 0
#undef DEBUG_DRAW
#endif
//#define DEBUG_DRAW 1
//#define DRAW_COLOR 1
#include <iostream>
#include <boost/format.hpp>
#include <vector>
#include <map>
#include <list>

// standard includes
#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
#include <sstream>
// define the kernel
#include "VertexData.h"
#include "RectangleArray.h"
#include <BWAPI.h>
#include "BaseLocation.h"
#include "Polygon.h"

#ifdef DEBUG_DRAW
  #include <QtGui>
  #include <CGAL/Qt/GraphicsViewNavigation.h>
  #include <QLineF>
  #include <QRectF>
#endif
#define BWTA_FILE_VERSION 6

namespace BWTA
{
#define PI 3.1415926


    bool load_map();
    void load_data(std::string filename);
    bool load_resources();

    int str2int(std::string str);
    std::string int2str(int number);
    int max(int a, int b);
    int min(int a, int b);
    void log(const char* text, ...);
    void writeFile(const char* filename, const char* text, ...);


    double distance_to_border(Polygon& polygon, int width, int height);

    void calculate_walk_distances(const RectangleArray<bool>& read_map
                                  , const BWAPI::Position& start
                                  , int max_distance
                                  , RectangleArray<int>& distance_map);

    void calculate_walk_distances_area(const BWAPI::Position& start
                                       , int width
                                       , int height
                                       , int max_distance
                                       , RectangleArray<int>& distance_map);

    int get_set(std::vector<int>& a, int i);

    template <class _Tp1>
    _Tp1 get_set2(std::map<_Tp1, _Tp1>& a, _Tp1 i)
    {
        if (a.find(i) == a.end())
            a[i] = i;
        if (i == a[i])
            return i;
        a[i] = get_set2(a, a[i]);
        return a[i];
    }

    void calculate_connectivity();

    float max(float a, float b);
    float min(float a, float b);

    double max(double a, double b);
    double min(double a, double b);
    bool fileExists(std::string filename);
    int fileVersion(std::string filename);

    double AstarSearchDistance(BWAPI::TilePosition start, BWAPI::TilePosition end);
    std::pair<BWAPI::TilePosition, double> AstarSearchDistance(BWAPI::TilePosition start, std::set<BWAPI::TilePosition>& end);
    std::map<BWAPI::TilePosition, double> AstarSearchDistanceAll(BWAPI::TilePosition start, std::set<BWAPI::TilePosition>& end);
    std::vector<BWAPI::TilePosition> AstarSearchPath(BWAPI::TilePosition start, BWAPI::TilePosition end);
    std::vector<BWAPI::TilePosition> AstarSearchPath(BWAPI::TilePosition start, std::set<BWAPI::TilePosition> end);
}