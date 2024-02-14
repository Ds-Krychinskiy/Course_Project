#pragma once
#include "./ResourceHolder.h"
#include "../../ResourceTypes.h"
#include "../../stdafx/stdafx.h"

class SoundBufferHolder : public ResourceHolder<sf::SoundBuffer, res::Sound>
{
public:
	void load(res::Sound id, const std::filesystem::path& filePath) override
	{
		std::unique_ptr<sf::SoundBuffer> sound = std::make_unique<sf::SoundBuffer>();
		if (!sound->loadFromFile(filePath.string()))
		{
			std::cout << "Failed to parse tiled map: " + filePath.string() << std::endl;
			return;
		}
		std::cout << "Sound loaded succesfully: " + filePath.string() << std::endl;
		insert(id, std::move(sound));
	}
};
