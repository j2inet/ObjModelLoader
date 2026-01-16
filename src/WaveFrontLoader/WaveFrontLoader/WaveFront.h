#pragma once
#include <memory>
#include <vector>
#include <string>
#include <map>


struct WFVector3 {
public:
	float x;
	float y;
	float z;
};

struct WFVector2 {
	public:
	float u;
	float v;
};



struct WFNamedElement {
	public:
		std::wstring name;
		int index = -1;
};

struct WFComment {
	public:
		std::wstring text;
};

struct WFFaceElement {
public:
	int vertexIndex = -1;
	int texCoordIndex = -1;
	int normalIndex = -1;
};

struct WFFacet {
	public:
		std::wstring materialName = L"";
		std::vector<WFFaceElement> vertexIndices = {};
		int smoothingGroup = -1;
};

struct WFVertex {
public:
	WFVector3 position;
	WFVector3 normal = {0,0};
	WFVector2 texCoord = { 0, 0 };

	void setNormal(WFVector3 normal) 
	{
		this->normal = normal;
		hasNormal = true;
	}

	void setTexCoord(WFVector2 texCoord)
	{
		this->texCoord = texCoord;
		hasTexCoord = true;
	}

	bool hasNormal = false;
	bool hasTexCoord = false;
};


struct  WFData {
public:
	std::vector<WFComment> commentList;
	std::vector<WFNamedElement> namedElementList;
	std::vector<WFVector3> vertexList;
	std::vector<WFVector2> texCoordList;
	std::vector<WFVector3> normalList;
	std::vector<WFFacet> facetList;
	std::wstring materialFileName = L"";
};

std::shared_ptr<WFData> LoadWaveFrontModel(const std::wstring& filePath);