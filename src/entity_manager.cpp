#include "entity_manager.h"

EntityManager::EntityManager(){}

std::shared_ptr<Entity> EntityManager::addEntity(const std::string &tag){
    auto entity = std::make_shared<Entity>(m_totalEntities++, tag);
    m_toAdd.push_back(entity);
    return entity;
}

EntityVec& EntityManager::getEntities(){
    return m_entities;
}

EntityVec& EntityManager::getEntities(const std::string &tag){
    return m_entityMap[tag];
}

void EntityManager::update(){
    for (const auto &item: m_toAdd){
        m_entities.push_back(item);
        m_entityMap[item->tag()].push_back(item);
    }

    //remove entities that are not alive
    auto it = std::remove_if(m_entities.begin(), m_entities.end(), [](std::shared_ptr<Entity> entity){
        return !entity->isActive();
    });
    m_entities.erase(it, m_entities.end());
    m_toAdd.clear();
}