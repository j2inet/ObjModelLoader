#include <fstream>
#include <sstream>
#include "WaveFront.h"


std::vector<std::wstring> split_wstring(const std::wstring& str, wchar_t delimiter) {
    std::vector<std::wstring> tokens;
    std::wistringstream wss(str);
    std::wstring token;

    while (std::getline(wss, token, delimiter)) {
        if (!token.empty()) { // Skip empty tokens if needed
            tokens.push_back(token);
        }
    }
    return tokens;
}


std::shared_ptr<WFData> LoadWaveFrontModel(const std::wstring& filePath) {

	std::shared_ptr<WFData> wfData = std::make_shared<WFData>();
    int smoothingGroup = -1;


    std::wifstream file(filePath);
    if (!file) {
        return nullptr;
    }

    std::wstring line;
    while (std::getline(file, line)) {
        std::wistringstream iss(line);
        std::wstring token;
        iss >> token;

        if(token == L"#") {
            wfData->commentList.push_back(WFComment{ line.substr(2) });
            continue;
        }
        else if (token == L"v")
        {
            float x, y, z;
			iss >> x >> y >> z;
			WFVector3 vertex = { x, y, z };
            wfData->vertexList.push_back(vertex);
        }
        else if (token == L"vt")
        {
            float u, v;
            iss >> u >> v;
            WFVector2 texCoord = { u, v };
            wfData->texCoordList.push_back(texCoord);
        }
        else if (token == L"vn")
        {
            float x, y, z;
            WFVector3 normal;
            iss >> x >> y >> z;
            normal = { x, y, z };   
            wfData->normalList.push_back(normal);
        }
        else if (token == L"f")
        {
            std::wstring facetPart;
            WFFacet facet = {};
			facet.smoothingGroup = smoothingGroup;
            while(!iss.eof())
            {
                iss >> facetPart;
                auto parts = split_wstring(facetPart, L'/');
				WFFaceElement faceElement;
                if (parts.size() >= 1)
                    faceElement.vertexIndex = std::stoi(parts[0]) - 1; // OBJ indices are 1-based
                if (parts.size() >= 2 && !parts[1].empty())
                    faceElement.texCoordIndex = std::stoi(parts[1]) - 1;
                if (parts.size() == 3 && !parts[2].empty())
					faceElement.normalIndex = std::stoi(parts[2]) - 1;
				facet.vertexIndices.push_back(faceElement);
            }
            wfData->facetList.push_back(facet);
        }
        else if (token == L"usemtl")
        {
            std::wstring materialName;
			materialName = line.substr(7);
            wfData->namedElementList.push_back(WFNamedElement{ materialName, static_cast<int>(wfData->facetList.size()) });
        }
        else if (token == L"mtllib") {
            // Material library
            auto entryIndex = line.find(L"mtllib");
            wfData->materialFileName = line.substr(entryIndex + 7);
		}
		else if (token == L"o") {
            // Object name. We can ignore this. This is for the user. 
            std::wstring objectName;
			objectName = line.substr(2);
		}
        else if (token == L"s") {
            // Smoothing group. We can ignore this for now.
            std::wstring smoothingGroup;
			iss >> smoothingGroup;
			smoothingGroup = std::stoi(smoothingGroup);
		}
    }

    if(wfData->namedElementList.size() == 0)
    {
        wfData->namedElementList.push_back({L"Unnamed", 0});
    } else if (wfData->namedElementList[0].index>0)
    {
        wfData->namedElementList.insert(wfData->namedElementList.begin(), {L"Unname", 0});
    }

    return wfData;
}
