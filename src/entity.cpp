#include "entity.h"

Entity::Entity():m_alive(true), m_id(0), m_tag(""){}

Entity::Entity(size_t id, std::string tag): m_id(id), m_tag(tag), m_alive(true) {}

const std::string& Entity::tag() const {
    return m_tag;
}

bool Entity::isActive() const {
    return m_alive;
}

size_t Entity::getId() const {
    return m_id;
}

template <typename T>
T& Entity::get(){
    return std::get<T>(m_components);
}

template <typename T>
const T& Entity::get() const{
    return std::get<T>(m_components);
}

template<typename T, typename... TArgs>
T& Entity::add(TArgs&&... margs){
    auto & component = get<T>();
    component = T(std::forward<TArgs>(margs)...);
    component.exists = true;
    return component;
}

template<typename T>
bool Entity::has() const{
    return get<T>().exists;
}

template <typename T>
void Entity::remove(){
    get<T>() = T();
}

void Entity::destroy(){
    m_alive = false;
}