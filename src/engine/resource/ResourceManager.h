#pragma once

#include "../../stdafx/stdafx.h"
#include "./TextureHolder.h"
#include "./FontHolder.h"
#include "./MapHolder.h"
#include "./SoundBufferHolder.h"
#include "./MusicHolder.h"

// Singleton for accessing resources in all classes. Loads everything in it's constructor, in the first time it accessed.
// Maybe not the most efficient, but for this small game it's probably gonna be enough
// Everytime we want to add a new asset we have to append it's methods.
class ResourceManager
{
public:

	static ResourceManager& getInstance()
	{
		static ResourceManager s_Instance;
		return s_Instance;
	}
	
	ResourceManager(ResourceManager const&) = delete;
	void operator=(ResourceManager const&) = delete;

	const sf::Texture& getTexture(res::Texture id) const;
	const sf::Font& getFont(res::Font id) const;
	// const tmx::Map& getMap(res::Map id) const;
	sf::SoundBuffer& getSoundBuffer(res::Sound id) const;
	sf::Music& getMusic(res::Music id) const;

private:
	ResourceManager();

	void loadTextures();
	void loadFonts();
	void loadMaps();
	void loadSounds();
	void loadMusic();

	// Holders for each type
	TextureHolder m_TextureHolder;
	FontHolder m_FontHolder;
	MapHolder m_MapHolder;
	MusicHolder m_MusicHolder;
	SoundBufferHolder m_SoundBufferHolder;
};

