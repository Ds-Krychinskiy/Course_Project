#pragma once

#include "../../stdafx/stdafx.h"
#include "./ResourceHolder.h"
#include "../../ResourceTypes.h"

class MapHolder : public ResourceHolder<tmx::Map, res::Map>
{
public:
	void load(res::Map id, const std::filesystem::path& filePath) override
	{
		std::unique_ptr<tmx::Map> map = std::make_unique<tmx::Map>();
		if (!map->load(filePath.string()))
		{
			std::cout << "Failed to parse tiled map: " + filePath.string() << std::endl;
			return;
		}
		std::cout <<  "Map loaded succesfully: " + filePath.string() << std::endl;
		insert(id, std::move(map));
	}
};
