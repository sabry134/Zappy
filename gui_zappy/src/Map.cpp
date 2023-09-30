/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** Map
*/

#include "Map.hpp"

Map::Map( int winW, int winH, int sizeX, int sizeY) : _mapRender(sf::Quads, 0)
{
    this->_winHeight = winH;
    this->_winWidth = winW;
    this->_sizeX = sizeX;
    this->_sizeY = sizeY;
    this->_tileSize = sf::Vector2u(32, 32);
    this->_zoom = 2;
    this->pos = sf::Vector2i(0, 0);
    for (unsigned int i = 0; i < _sizeY; i++)
        for (unsigned int j = 0; j < _sizeX; j++) {
            Tile tmp;
            tmp.x = i;
            tmp.y = j;
            tmp.DERAUMERE = 0;
            tmp.FOOD = 0;
            tmp.LINEMATE = 0;
            tmp.MENDIANE = 0;
            tmp.PHIRAS = 0;
            tmp.SIBUR = 0;
            tmp.THYSTAME = 0;
            this->_map.push_back(tmp);
        }
    this->_mapRender.resize(sizeX * sizeY * 4);
    if (!_tileset.loadFromFile("gui_zappy/assets/GrassText.png"))
        throw std::exception();
}

Map::~Map()
{
}

int Map::resizeMap(int sizeX, int sizeY)
{
    this->_sizeX = sizeX;
    this->_sizeY = sizeY;
    this->_mapRender.resize(sizeX * sizeY * 4);
    this->_map.clear();
    for (unsigned int i = 0; i < _sizeY; i++)
        for (unsigned int j = 0; j < _sizeX; j++) {
            Tile tmp;
            tmp.x = i;
            tmp.y = j;
            tmp.DERAUMERE = 0;
            tmp.FOOD = 0;
            tmp.LINEMATE = 0;
            tmp.MENDIANE = 0;
            tmp.PHIRAS = 0;
            tmp.SIBUR = 0;
            tmp.THYSTAME = 0;
            this->_map.push_back(tmp);
        }
    return 0;
}

bool Map::updateMap()
{
    for (unsigned int i = 0; i < _sizeX; i++)
        for (unsigned int j = 0; j < _sizeY; j++) {
            this->_map.at(i + j * _sizeX).PLAYER.clear();
        }
    for (auto it = this->getTeam().begin(); it != this->getTeam().end(); it++) {
        for (auto player = (*it).getPlayerList().begin(); player != (*it).getPlayerList().end(); player++) {
            this->_map.at((*player).getPos().x + (*player).getPos().y * this->_sizeX).PLAYER.push_back(*player);
        }
    }
    int i = 0;
    for (auto it = _boradcastList.begin() ; it != _boradcastList.end(); it++) {
        if (_boradcastList.at(i).getScaleNb() < 60)
            _boradcastList.at(i).scaleCircle();
        else
            _boradcastList.erase(it);
        i++;
    }
    return true;
}



bool Map::updateTexture()
{
    for (unsigned int i = 0; i < _sizeX; i++)
        for (unsigned int j = 0; j < _sizeY; j++) {
            int curr = chooseText(i, j);
            int tu = curr % (this->_tileset.getSize().x / _tileSize.x);
            int tv = curr / (this->_tileset.getSize().x / _tileSize.x);
            sf::Vertex *quad = &this->_mapRender[(i + j * _sizeX) * 4];
            quad[0].position = sf::Vector2f(i * _tileSize.x * this->_zoom + this->pos.x, j * _tileSize.y * this->_zoom  + this->pos.y);
            quad[1].position = sf::Vector2f((i + 1) * _tileSize.x * this->_zoom + this->pos.x, j * _tileSize.y * this->_zoom + this->pos.y);
            quad[2].position = sf::Vector2f((i + 1) * _tileSize.x * this->_zoom + this->pos.x,  (j + 1) * _tileSize.y * this->_zoom + this->pos.y);
            quad[3].position = sf::Vector2f(i * _tileSize.x * this->_zoom + this->pos.x, (j + 1) * _tileSize.y * this->_zoom + this->pos.y);
            // on définit ses quatre coordonnées de texture
            quad[0].texCoords = sf::Vector2f(tu * _tileSize.x, tv * _tileSize.y);
            quad[1].texCoords = sf::Vector2f((tu + 1) * _tileSize.x, tv * _tileSize.y);
            quad[2].texCoords = sf::Vector2f((tu + 1) * _tileSize.x, (tv + 1) * _tileSize.y);
            quad[3].texCoords = sf::Vector2f(tu * _tileSize.x, (tv + 1) * _tileSize.y);
            if (curr >= 1 && curr <= 4) {
                for (int x = 0; x < this->team.size();x++) {
                    for (int y = 0; y < this->team.at(x).getPlayerList().size(); y++) {
                        if (this->team.at(x).getPlayerList().at(y).getPos() == sf::Vector2u(i, j)) {
                            quad[0].color = this->team.at(x).getTeamColor();
                            quad[1].color = this->team.at(x).getTeamColor();
                            quad[2].color = this->team.at(x).getTeamColor();
                            quad[3].color = this->team.at(x).getTeamColor();
                        }
                    }
                }
            } else {
                quad[0].color = sf::Color::White;
                quad[1].color = sf::Color::White;
                quad[2].color = sf::Color::White;
                quad[3].color = sf::Color::White;
            }
        }
    return true;
}

void Map::moveMap(int lateral, int vertical)
{
    this->pos.x += lateral;
    this->pos.y += vertical;  
}

void Map::setTile(Tile t)
{
    this->_map.at(t.x + t.y * this->_sizeX).DERAUMERE = t.DERAUMERE;
    this->_map.at(t.x + t.y * this->_sizeX).FOOD = t.FOOD;
    this->_map.at(t.x + t.y * this->_sizeX).LINEMATE = t.LINEMATE;
    this->_map.at(t.x + t.y * this->_sizeX).MENDIANE = t.MENDIANE;
    this->_map.at(t.x + t.y * this->_sizeX).PHIRAS = t.PHIRAS;
    this->_map.at(t.x + t.y * this->_sizeX).SIBUR = t.SIBUR;
    this->_map.at(t.x + t.y * this->_sizeX).THYSTAME = t.THYSTAME;
}

void Map::addEgg(int x, int y, int id)
{
    this->_map.at(x + y * this->_sizeX).EGG.push_back(Egg(id, sf::Vector2u(x, y)));
    this->_eggList.push_back(Egg(id, sf::Vector2u(x, y)));
}

void Map::removeEgg(int id, int x, int y)
{
    this->_map.at(x + y * this->_sizeX).EGG.pop_back();
}

void Map::zoom(bool zoomin)
{
    if (zoomin)
        this->_zoom += 0.1;
    else
        this->_zoom -= 0.1;
}

void Map::addTeam(Team t)
{
    this->team.push_back(t);
}

sf::Vector2u Map::getSize()
{
    return sf::Vector2u(this->_sizeX, this->_sizeY);
}

std::vector<Team>& Map::getTeam()
{
    return this->team;
}

sf::Vector2u Map::getTileSize()
{
    return this->_tileSize;
}

std::vector<Broadcast> Map::getBroadcastList()
{
    return this->_boradcastList;
}

float Map::getZomm()
{
    return this->_zoom;
}

struct Tile &Map::getTileInfo(sf::Vector2i mousePos)
{
    for (int x = 0; x < this->_sizeX; x++)
        for (int y = 0; y < this->_sizeY; y++) {
            sf::Vertex *quad = &this->_mapRender[(x + y * _sizeX) * 4];
            if (quad[0].position.x <= mousePos.x && quad[0].position.y  <= mousePos.y && quad[2].position.x  >= mousePos.x && quad[2].position.y >= mousePos.y)
                return this->_map.at(x + y * _sizeX);
        }
    throw std::exception();
}

std::vector<Egg> Map::getEggList()
{
    return this->_eggList;
}

std::vector<Incantation> &Map::getIncantationList()
{
    return this->_incantationList;
}

int Map::chooseText(unsigned int i,unsigned int j)
{
    Tile t = this->_map.at(i + j * this->_sizeX);
    if (t.PLAYER.empty()) {
        if (t.EGG.empty()) {
            if (t.FOOD < 1 && t.LINEMATE < 1)
                return 0;
            if (t.FOOD > t.LINEMATE * 2)
                return 6;
            else 
                return 5;
        } else {
            return 7;
        }
    } else {
        Orientation o = t.PLAYER.front().getOrientation();
        if (o == Orientation::EAST)
            return 1;
        if (o == Orientation::NORTH)
            return 4;
        if (o == Orientation::WEST)
            return 3;
        if (o == Orientation::SOUTH)
            return 2;
    }
    return 0;
}
