#pragma once

#include "../../stdafx/stdafx.h"
#include "./ResourceHolder.h"
#include "../../ResourceTypes.h"

class TextureHolder : public ResourceHolder<sf::Texture, res::Texture>
{
public:
	void load(res::Texture id, const std::filesystem::path& filePath) override
	{
		std::unique_ptr<sf::Texture> texture = std::make_unique<sf::Texture>();
		if (!texture->loadFromFile(filePath.string()))
		{
			std::cout << "Failed to load texture: " + filePath.string() << std::endl;
			return;
		}
		std::cout << "Texture loaded succesfully: " + filePath.string() << std::endl;
		insert(id, std::move(texture));
	}
};
