#pragma once
#include "Level.h"
#include "Player.h"
#include "Enemy.h"
#include "Game.h"

class CombatLevel : public Game
{
	string prefix;

	Vector2f tileSize;

public:
	CombatLevel();

public:
	virtual void Start() override;
	virtual bool Update() override;
	virtual void Stop() override;

private:
	void GenerateMap();
	void GenerateBackGround();
	void GenerateAllDecorates();
	void GenerateAllWalls();

#pragma region GenerateWall
	void GenerateHorizontalWall(const Vector2f& _position = Vector2f());
	void GenerateVerticalWall(const Vector2f& _position = Vector2f());
	void GenerateBreakWallRight(const Vector2f& _position = Vector2f());
	void GenerateBreakWallLeft(const Vector2f& _position = Vector2f());
#pragma endregion

#pragma region GenerateBuild
	void GenerateHome(const Vector2f& _position = Vector2f());
	void GenerateBreakHome(const Vector2f& _position = Vector2f());
	void GenerateDoor(const Vector2f& _position = Vector2f());
#pragma endregion

#pragma region GenerateDecorate
	void GenerateGold(const pair<Vector2f, Vector2f>& _location);
	void GenerateAcid(const pair<Vector2f, Vector2f>& _location);
	void GenerateBarrel(const pair<Vector2f, Vector2f>& _location);
	void GenerateChest(const pair<Vector2f, Vector2f>& _location);
	void GenerateStone(const pair<Vector2f, Vector2f>& _location);
#pragma endregion

#pragma region GenerateTorch
	void GenerateTorch();
#pragma endregion

	Vector2f GetRandomPosition(const pair<Vector2f, Vector2f>& _location);
};