bwapi-bwta-map-analyzer
=======================

### Standalone BWTA based Brood War map(terrain) analyzer (BWAPI v3.7.4 compatible)

##### This project provides two utilities / tools:
1. bwtaMapAnalyzerV1_0.exe - a standalone BWAPI Client based map analyzer, which spits a .bwta file as a result after running.
2. stripped BWTA source code that doesn't support terrain analysis (this is done by 1), but supports everything else. It doesn't depend
on CGAL, boost, tinyxml, etc.

##### Why are the above tools needed?
BWTA hasn't been maintained for about two years already and it's no longer compatible with the new BWAPI version
and even worse - (because of its dependencies) with the newer C++ compilers.
The aim of this project is to provide means for bot developers to use BWTA with newer C++ compilers and after some more work -
with the new BWAPI version.

##### How to use?
1. In case for a particular map a previously generated .bwta file is not available, one needs to run *ONCE* bwtaMapAnalyzerV1_0.exe as
a BWAPI Client along with BWAPI v3.7.4 in order to generate a .bwta file.
2. A bot that utilizes the stripped down version of BWTA can then run normally with BWAPI using the pregenerated .bwta file.

###### For ideas and suggestions, please reply to the forum topic at: http://www.broodwarai.com/forums/viewtopic.php?f=9&t=1223
