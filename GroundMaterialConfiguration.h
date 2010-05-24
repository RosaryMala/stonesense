#pragma once

#include "dfhack/depends/tinyxml/tinyxml.h"
#include <map>

typedef struct OverridingMaterial{
	int gameID;
	t_SpriteWithOffset sprite;
}OverridingMaterial;

class TerrainMaterialConfiguration
{
public:
	vector<t_SpriteWithOffset> defaultSprite;
	int gameID;
	vector<map<int,t_SpriteWithOffset> > overridingMaterials;
	
	TerrainMaterialConfiguration();
	~TerrainMaterialConfiguration(){}
};

class TerrainConfiguration
{
public:
	vector<TerrainMaterialConfiguration*> terrainMaterials;
	vector<t_SpriteWithOffset> defaultSprite;
	TerrainConfiguration();
	~TerrainConfiguration();	
};

bool addSingleTerrainConfig( TiXmlElement* elemRoot);
//void LoadGroundMaterialConfiguration( );
//void TranslateGroundMaterialNames();

//extern bool GroundMaterialNamesTranslatedFromGame;
//extern vector<GroundMaterialConfiguration*> groundTypes;

void flushTerrainConfig(vector<TerrainConfiguration*>& config);
void DumpInorganicMaterialNamesToDisk();