#pragma once

#include "common.h"
#include "components.h"

using CComponents = std::tuple<CTransform, CScore, CShape, CCollision, CLifeSpan, CInput>;

class Entity{
    std::string m_tag;
    bool m_alive;
    size_t m_id;
    CComponents m_components;
    
    Entity();
    Entity(size_t id, std::string tag = "");

public:
    const std::string &tag() const;
    bool isActive() const;
    size_t getId() const;
    void destroy();

    template <typename T>
    T& get();

    template <typename T>
    const T& get() const;

    template <typename T, typename... TArgs>
    T& add(TArgs&&... margs);

    template <typename T>
    bool has() const;

    template <typename T>
    void remove();

    friend class EntityManager;
};