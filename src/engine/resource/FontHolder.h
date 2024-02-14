#pragma once

#include "../../stdafx/stdafx.h"

#include "./ResourceHolder.h"

// #include "ResourceTypes.h"

class FontHolder : public ResourceHolder<sf::Font, res::Font>
{
public:
	void load(res::Font id, const std::filesystem::path& filePath) override
	{
		std::unique_ptr<sf::Font> font = std::make_unique<sf::Font>();
		if (!font->loadFromFile(filePath.string()))
		{
			std::cout << "Failed to load font: " + filePath.string() << std::endl;
			return;
		}
		std::cout << "Font loaded successfully: " + filePath.string() << std::endl;
		insert(id, std::move(font));
	}
};
