#pragma once

#include "./ResourceHolder.h"
#include "../../ResourceTypes.h"
#include "../../stdafx/stdafx.h"


class MusicHolder : public ResourceHolder<sf::Music, res::Music>
{
public:
	void load(res::Music id, const std::filesystem::path& filePath) override
	{
		std::unique_ptr<sf::Music> music = std::make_unique<sf::Music>();
		if (!music->openFromFile(filePath.string()))
		{
			std::cout << "Failed to load music: " + filePath.string() << std::endl;
			return;
		}
		std::cout << "Music loaded successfully: " + filePath.string() << std::endl;
		insert(id, std::move(music));
	}
};
