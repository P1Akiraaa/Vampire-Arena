#include "CombatLevel.h"

CombatLevel::CombatLevel()
{
	prefix = "Map/";
	tileSize = Vector2f(50.0f, 50.0f);
}

void CombatLevel::Start()
{
	Super::Start();
}

bool CombatLevel::Update()
{
	GenerateMap();
	Super::Update();

	return IsOver();
}

void CombatLevel::Stop()
{
	Super::Stop();
}



void CombatLevel::GenerateMap()
{
	GenerateBackGround();
	GenerateDecorates();
	GenerateAllWalls();
}

void CombatLevel::GenerateBackGround()
{
	// TODO check for isReapeted !!!!

	for (u_int _row = 0; _row < 50; _row++)
	{
		for (u_int _column = 0; _column < 27; _column++)
		{
			MeshActor* _tile = Level::SpawnActor(MeshActor(RectangleShapeData(tileSize, prefix + "Floor", PNG, true)));
			_tile->SetPosition(Vector2f(_row * tileSize.x, _column * tileSize.y));
		}
	}
}

void CombatLevel::GenerateDecorates()
{
}

void CombatLevel::GenerateAllWalls()
{
	Vector2f _horizontalWallSize = Vector2f(86.0f, 84.0f);
	for (u_int _index = 0; _index < 8; _index++)
	{
		GenerateHorizontalWall(Vector2f(_index * _horizontalWallSize.x, 0.0f));
	}

	GenerateHome(Vector2f(350.0f, 100.0f));

	Vector2f _verticalWallSize = Vector2f(21.0f, 86.0f);
	Vector2f _startPos = Vector2f(665.0f, 0.0f);
	for (u_int _index = 0; _index < 5; _index++)
	{
		GenerateVerticalWall(Vector2f(_verticalWallSize.x + _startPos.x, _index * _verticalWallSize.y));
	}

	_startPos = Vector2f(686.0f, 407.0f);
	for (u_int _index = 0; _index < 2; _index++)
	{
		GenerateHorizontalWall(Vector2f(_startPos.x + _horizontalWallSize.x * _index, _startPos.y));
	}

	_startPos = Vector2f(858.0f, 407.0f);
	GenerateBreakWallRight(_startPos);


	_startPos = Vector2f(1300.0f, 407.0f);
	GenerateBreakWallLeft(_startPos);

	_startPos = Vector2f(1384.0f, 407.0f);
	for (u_int _index = 0; _index < 7; _index++)
	{
		GenerateHorizontalWall(Vector2f(_startPos.x + _horizontalWallSize.x * _index, _startPos.y));
	}

	GenerateBreakHome(Vector2f(1650.0f, 525.0f));

	_startPos = Vector2f(665.0f, 700.0f);
	for (u_int _index = 0; _index < 4; _index++)
	{
		GenerateVerticalWall(Vector2f(_verticalWallSize.x + _startPos.x, _startPos.y + _index * _verticalWallSize.y));
	}
}


void CombatLevel::GenerateHorizontalWall(const Vector2f& _position)
{
	MeshActor* _wall = Level::SpawnActor(MeshActor(RectangleShapeData(Vector2f(86.0f, 84.0f), prefix + "map", PNG, false, IntRect(Vector2i(165, 24), Vector2i(86, 84)))));
	_wall->SetPosition(_position);
}

void CombatLevel::GenerateVerticalWall(const Vector2f& _position)
{
	MeshActor* _wall = Level::SpawnActor(MeshActor(RectangleShapeData(Vector2f(21.0f, 86.0f), prefix + "map", PNG, false, IntRect(Vector2i(316, 23), Vector2i(21, 86)))));
	_wall->SetPosition(_position);
}

void CombatLevel::GenerateBreakWallRight(const Vector2f& _position)
{
	MeshActor* _wall = Level::SpawnActor(MeshActor(RectangleShapeData(Vector2f(84.0f, 85.0f), prefix + "map", PNG, false, IntRect(Vector2i(187, 132), Vector2i(84, 85)))));
	_wall->SetPosition(_position);
}

void CombatLevel::GenerateBreakWallLeft(const Vector2f& _position)
{
	MeshActor* _wall = Level::SpawnActor(MeshActor(RectangleShapeData(Vector2f(84.0f, 85.0f), prefix + "map", PNG, false, IntRect(Vector2i(340, 132), Vector2i(84, 85)))));
	_wall->SetPosition(_position);
}

void CombatLevel::GenerateHome(const Vector2f& _position)
{
	MeshActor* _wall = Level::SpawnActor(MeshActor(RectangleShapeData(Vector2f(300.8f, 284.8f), prefix + "map", PNG, false, IntRect(Vector2i(209, 360), Vector2i(188, 178)))));
	_wall->SetPosition(_position);
}

void CombatLevel::GenerateBreakHome(const Vector2f& _position)
{
	MeshActor* _wall = Level::SpawnActor(MeshActor(RectangleShapeData(Vector2f(162.4f, 217.0f), prefix + "map", PNG, false, IntRect(Vector2i(444, 381), Vector2i(116, 155)))));
	_wall->SetPosition(_position);
}

void CombatLevel::GenerateDoor(const Vector2f& _position)
{
	MeshActor* _wall = Level::SpawnActor(MeshActor(RectangleShapeData(Vector2f(120.0f, 146.0f), prefix + "map", PNG, false, IntRect(Vector2i(48, 396), Vector2i(120, 146)))));
	_wall->SetPosition(_position);
}


// TODO Make RandomSpawnLocate
void CombatLevel::GenerateGold()
{
	vector<pair<Vector2i, Vector2i>> _stoneData =
	{
		make_pair(Vector2i(24, 182), Vector2i(53, 36)),
		make_pair(Vector2i(100, 174), Vector2i(95, 44)),
		make_pair(Vector2i(214, 166), Vector2i(87, 52)),
	};
	pair<Vector2i, Vector2i> _stone = _stoneData[GetRandomNumberInRange(0, CAST(int, _stoneData.size() - 1))];
	MeshActor* _wall = Level::SpawnActor(MeshActor(RectangleShapeData(CAST(Vector2f, _stone.second), prefix + "decorates", PNG, false, IntRect(_stone.first, _stone.second))));
	_wall->SetPosition(Vector2f());
}

void CombatLevel::GenerateAcid()
{
	vector<pair<Vector2i, Vector2i>> _stoneData =
	{
		make_pair(Vector2i(323, 192), Vector2i(66, 28)),
		make_pair(Vector2i(413, 195), Vector2i(69, 24)),
		make_pair(Vector2i(509, 193), Vector2i(79, 26)),
	};

	pair<Vector2i, Vector2i> _stone = _stoneData[GetRandomNumberInRange(0, CAST(int, _stoneData.size() - 1))];

	MeshActor* _wall = Level::SpawnActor(MeshActor(RectangleShapeData(CAST(Vector2f, _stone.second), prefix + "decorates", PNG, false, IntRect(_stone.first, _stone.second))));
	_wall->SetPosition(Vector2f());
}

void CombatLevel::GenerateBarrel()
{
	vector<pair<Vector2i, Vector2i>> _stoneData =
	{
		make_pair(Vector2i(90, 109), Vector2i(43, 34)),
		make_pair(Vector2i(153, 102), Vector2i(31, 38)),
	};

	pair<Vector2i, Vector2i> _stone = _stoneData[GetRandomNumberInRange(0, CAST(int, _stoneData.size() - 1))];

	MeshActor* _wall = Level::SpawnActor(MeshActor(RectangleShapeData(CAST(Vector2f, _stone.second), prefix + "decorates", PNG, false, IntRect(_stone.first, _stone.second))));
	_wall->SetPosition(Vector2f());
}

void CombatLevel::GenerateChest()
{
	vector<pair<Vector2i, Vector2i>> _stoneData =
	{
		make_pair(Vector2i(209, 108), Vector2i(43, 34)),
		make_pair(Vector2i(278, 115), Vector2i(32, 26)),
		make_pair(Vector2i(338, 109), Vector2i(44, 34)),
		make_pair(Vector2i(403, 110), Vector2i(38, 33)),
		make_pair(Vector2i(465, 113), Vector2i(44, 30)),
		make_pair(Vector2i(537, 109), Vector2i(28, 34)),
	};

	pair<Vector2i, Vector2i> _stone = _stoneData[GetRandomNumberInRange(0, CAST(int, _stoneData.size() - 1))];

	MeshActor* _wall = Level::SpawnActor(MeshActor(RectangleShapeData(CAST(Vector2f, _stone.second), prefix + "decorates", PNG, false, IntRect(_stone.first, _stone.second))));
	_wall->SetPosition(Vector2f());
}

void CombatLevel::GenerateStone()
{
	vector<pair<Vector2i, Vector2i>> _stoneData =
	{
		make_pair(Vector2i(286, 59), Vector2i(23, 20)),
		make_pair(Vector2i(329, 56), Vector2i(30, 22)),
		make_pair(Vector2i(379, 57), Vector2i(18, 21)),
		make_pair(Vector2i(417, 57), Vector2i(21, 21)),
		make_pair(Vector2i(456, 54), Vector2i(22, 24)),
	};

	pair<Vector2i, Vector2i> _stone = _stoneData[GetRandomNumberInRange(0, CAST(int, _stoneData.size() - 1))];

	MeshActor* _wall = Level::SpawnActor(MeshActor(RectangleShapeData(CAST(Vector2f,_stone.second), prefix + "decorates", PNG, false, IntRect(_stone.first, _stone.second))));
	_wall->SetPosition(Vector2f());
}

// TODO Add FireAnimation
void CombatLevel::GenerateTorch()
{
	vector<pair<Vector2i, Vector2i>> _stoneData =
	{
		make_pair(Vector2i(173, 272), Vector2i(17, 33)),
		make_pair(Vector2i(212, 270), Vector2i(20, 36)),
		make_pair(Vector2i(251, 266), Vector2i(18, 37)),
	};
	pair<Vector2i, Vector2i> _stone = _stoneData[GetRandomNumberInRange(0, CAST(int, _stoneData.size() - 1))];
	MeshActor* _wall = Level::SpawnActor(MeshActor(RectangleShapeData(CAST(Vector2f, _stone.second), prefix + "decorates", PNG, false, IntRect(_stone.first, _stone.second))));
	_wall->SetPosition(Vector2f());


}
