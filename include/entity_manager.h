#pragma once
#include "common.h"
#include "entity.h"

using EntityVec = std::vector<std::shared_ptr<Entity>>;
using EntityMap = std::map<std::string, EntityVec>;

class EntityManager{
    EntityVec m_entities;
    EntityVec m_toAdd;
    EntityMap m_entityMap;
    size_t m_totalEntities{0};

public:
    EntityManager();
    
    std::shared_ptr<Entity> addEntity(const std::string &tag);
    void update();
    EntityVec& getEntities();
    EntityVec& getEntities(const std::string& tag);
};