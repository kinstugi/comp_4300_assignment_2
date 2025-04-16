#pragma once
#include "common.h"

class Component{
public:
    bool exists {false};
    virtual ~Component(){}
};

class CCollision: public Component{
public:
    float radius{0};

    CCollision(): radius(0) {
        exists = false;
    }
    CCollision( float r ): radius(r) {}
};

class CInput: public Component
{
public:
	bool up{ false };
	bool down{ false };
	bool left{ false };
	bool right{ false };
	bool leftMouse{ false };
	bool rightMouse{ false };
	CInput() {
        exists = false;
    }
};

class CLifeSpan: public Component
{
public:
	int remaining{ 0 };		//total = 100,remaining 100	->alive for 30 frames->remaining 70 
	int total{ 0 };			//(ie.substract 1 every frame for int remaining ) Amount of lifespan remaining on the entity
	CLifeSpan(){
        exists = false;
    }                            
	CLifeSpan(int total): remaining(total), total(total) {}
};

class CScore: public Component
{
public:
	int score;
    CScore(): score(0){
        exists = false;
    }
	CScore(int s): score(s) {}
};

class CShape: public Component
{
public:
    sf::CircleShape circle;
    
    CShape(){
        exists = false;
    }
    CShape(float radius, int points, const sf::Color &fillColor, const sf::Color &outlineColor, float thickness = 1.0f)
    : circle(radius, points)
    {
        circle.setFillColor(fillColor);
        circle.setOutlineColor(outlineColor);
        circle.setOutlineThickness(thickness);
    }
};

class CTransform: public Component
{
public:
    Vec2 pos{0, 0};
    Vec2 speed{0, 0};
    float angle{0};

    CTransform() {
        exists = false;
    }
    CTransform(const Vec2 &pos_in, const Vec2 &speed_in, float angle_in): pos(pos_in), speed(speed_in), angle(angle_in){}
};