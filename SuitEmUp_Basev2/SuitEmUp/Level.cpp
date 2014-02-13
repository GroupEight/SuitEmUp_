//Level.cpp//

#include "Level.h"

#include <typeinfo>

Level::Level()
: m_xGravity(0.0f, 0.0f)
, m_xLevel(m_xGravity){
	//std::unique_ptr<Level_Wall> _walls(new Level_Wall(mTextures, mBWorld));
}

Level::~Level(){

}

bool Level::Load(){
	return false;
}