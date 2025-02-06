#include "CombatLevel.h"
#include "CameraManager.h"
#include "TrianglePointer.h"
#include "InputManager.h"

using namespace Input;

CombatLevel::CombatLevel()
{
	prefix = "Map/";
	tileSize = Vector2f(50.0f, 50.0f);
	rateDecorate = 30;
}

void CombatLevel::Start()
{
	GenerateMap();
	Super::Start();
	
	SUBJECT = Level::SpawnActor(TrianglePointer());
	SUBJECT->SetOriginAtMiddle();
	SUBJECT->SetPosition(Vector2f(window.getSize()) / 2.0f);


}

bool CombatLevel::Update()
{
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
	GenerateAllDecorates();
	GenerateAllWalls();
}

void CombatLevel::GenerateBackGround()
{
	MeshActor* _tile = Level::SpawnActor(MeshActor(RectangleShapeData(Vector2f(tileSize.x * 50, tileSize.y * 27), prefix + "Floor", PNG, true, IntRect(Vector2i(), Vector2i(tileSize.x * 50, tileSize.y * 27)))));
	//_tile->GetMesh()->GetShape()->GetDrawable()->setTextureRect(IntRect(Vector2i(), Vector2i(tileSize.x * 50, tileSize.y * 27)));
	//_tile->GetMesh()->GetShape()->GetTexture().setRepeated(true);
}

void CombatLevel::GenerateAllDecorates()
{
	MeshActor* _decorates;
	Vector2f _offset = Vector2f();
	vector<function<void()>> _callBacks =
	{
		[&]() {_decorates = GetGold(); },
		[&]() {_decorates = GetAcid(); },
		[&]() {_decorates = GetBarrel(); },
		[&]() {_decorates = GetChest(); },
		[&]() {_decorates = GetStone(); },
	};
	u_int _index = 0;
	for (u_int _row = 0; _row < 50; _row++)
	{
		for (u_int _column = 0; _column < 27; _column++)
		{
			_index = GetRandomNumberInRange(0, rateDecorate);
			if (_index < 5)
			{
				_offset.x = GetRandomNumberInRange(0, 40);
				_offset.y = GetRandomNumberInRange(0, 40);
				_callBacks[_index]();
				_decorates->SetPosition(Vector2f(_row * tileSize.x, _column * tileSize.y) + _offset);
			}
		}
	}
}

void CombatLevel::GenerateAllWalls()
{
	Vector2f _horizontalWallSize = Vector2f(86.0f, 84.0f);
	for (u_int _index = 0; _index < 8; _index++)
	{
		GenerateHorizontalWall(Vector2f(_index * (_horizontalWallSize.x - 1), 0.0f));
	}

	GenerateHome(Vector2f(350.0f, 100.0f));

	Vector2f _verticalWallSize = Vector2f(21.0f, 86.0f);
	Vector2f _startPos = Vector2f(657.0f, 0.0f);
	for (u_int _index = 0; _index < 5; _index++)
	{
		GenerateVerticalWall(Vector2f((_verticalWallSize.x) - 1 + _startPos.x, _index * _verticalWallSize.y));
	}

	_startPos = Vector2f(678.0f, 407.0f);
	for (u_int _index = 0; _index < 2; _index++)
	{
		GenerateHorizontalWall(Vector2f(_startPos.x + (_horizontalWallSize.x - 1) * _index, _startPos.y));
	}

	_startPos = Vector2f(848.0f, 406.0f);
	GenerateBreakWallRight(_startPos);


	_startPos = Vector2f(1301.0f, 406.0f);
	GenerateBreakWallLeft(_startPos);

	_startPos = Vector2f(1384.0f, 407.0f);
	for (u_int _index = 0; _index < 7; _index++)
	{
		GenerateHorizontalWall(Vector2f(_startPos.x + (_horizontalWallSize.x - 1) * _index, _startPos.y));
	}

	GenerateBreakHome(Vector2f(1650.0f, 525.0f));

	_startPos = Vector2f(657.0f, 700.0f);
	for (u_int _index = 0; _index < 4; _index++)
	{
		GenerateVerticalWall(Vector2f((_verticalWallSize.x - 1) + _startPos.x, _startPos.y + _index * _verticalWallSize.y));
	}
}

#pragma region GenerateWall
void CombatLevel::GenerateHorizontalWall(const Vector2f& _position)
{
	MeshActor* _wall = Level::SpawnActor(MeshActor(RectangleShapeData(Vector2f(86.0f, 84.0f), prefix + "map", PNG, false, IntRect(Vector2i(165, 24), Vector2i(86, 84)))));
	_wall->SetPosition(_position);
}

void CombatLevel::GenerateVerticalWall(const Vector2f& _position)
{
	MeshActor* _wall = Level::SpawnActor(MeshActor(RectangleShapeData(Vector2f(27.3f, 111.8f), prefix + "map", PNG, false, IntRect(Vector2i(316, 23), Vector2i(21, 86)))));
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
#pragma endregion

#pragma region GenerateBuild
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
#pragma endregion

#pragma region GenerateDecorate
void CombatLevel::GenerateGold(const pair<Vector2f, Vector2f>& _location)
{
	vector<pair<Vector2i, Vector2i>> _stoneData =
	{
		make_pair(Vector2i(24, 182), Vector2i(53, 36)),
		make_pair(Vector2i(100, 174), Vector2i(95, 44)),
		make_pair(Vector2i(214, 166), Vector2i(87, 52)),
	};
	pair<Vector2i, Vector2i> _stone = _stoneData[GetRandomNumberInRange(0, CAST(int, _stoneData.size() - 1))];
	MeshActor* _wall = Level::SpawnActor(MeshActor(RectangleShapeData(CAST(Vector2f, _stone.second), prefix + "decorates", PNG, false, IntRect(_stone.first, _stone.second))));
	_wall->SetPosition(GetRandomPosition(_location));
}

void CombatLevel::GenerateAcid(const pair<Vector2f, Vector2f>& _location)
{
	vector<pair<Vector2i, Vector2i>> _stoneData =
	{
		make_pair(Vector2i(323, 192), Vector2i(66, 28)),
		make_pair(Vector2i(413, 195), Vector2i(69, 24)),
		make_pair(Vector2i(509, 193), Vector2i(79, 26)),
	};

	pair<Vector2i, Vector2i> _stone = _stoneData[GetRandomNumberInRange(0, CAST(int, _stoneData.size() - 1))];

	MeshActor* _wall = Level::SpawnActor(MeshActor(RectangleShapeData(CAST(Vector2f, _stone.second), prefix + "decorates", PNG, false, IntRect(_stone.first, _stone.second))));
	_wall->SetPosition(GetRandomPosition(_location));
}

void CombatLevel::GenerateBarrel(const pair<Vector2f, Vector2f>& _location)
{
	vector<pair<Vector2i, Vector2i>> _stoneData =
	{
		make_pair(Vector2i(90, 109), Vector2i(43, 34)),
		make_pair(Vector2i(153, 102), Vector2i(31, 38)),
	};

	pair<Vector2i, Vector2i> _stone = _stoneData[GetRandomNumberInRange(0, CAST(int, _stoneData.size() - 1))];

	MeshActor* _wall = Level::SpawnActor(MeshActor(RectangleShapeData(CAST(Vector2f, _stone.second), prefix + "decorates", PNG, false, IntRect(_stone.first, _stone.second))));
	_wall->SetPosition(GetRandomPosition(_location));
}

void CombatLevel::GenerateChest(const pair<Vector2f, Vector2f>& _location)
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
	_wall->SetPosition(GetRandomPosition(_location));
}

void CombatLevel::GenerateStone(const pair<Vector2f, Vector2f>& _location)
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

	MeshActor* _wall = Level::SpawnActor(MeshActor(RectangleShapeData(CAST(Vector2f, _stone.second), prefix + "decorates", PNG, false, IntRect(_stone.first, _stone.second))));
	_wall->SetPosition(GetRandomPosition(_location));
}
#pragma endregion

#pragma region GetDecorate
MeshActor* CombatLevel::GetGold() const
{
	vector<pair<Vector2i, Vector2i>> _stoneData =
	{
		make_pair(Vector2i(24, 182), Vector2i(53, 36)),
		make_pair(Vector2i(100, 174), Vector2i(95, 44)),
		make_pair(Vector2i(214, 166), Vector2i(87, 52)),
	};
	pair<Vector2i, Vector2i> _stone = _stoneData[GetRandomNumberInRange(0, CAST(int, _stoneData.size() - 1))];
	return Level::SpawnActor(MeshActor(RectangleShapeData(CAST(Vector2f, _stone.second), prefix + "decorates", PNG, false, IntRect(_stone.first, _stone.second))));
}

MeshActor* CombatLevel::GetAcid() const
{
	vector<pair<Vector2i, Vector2i>> _stoneData =
	{
		make_pair(Vector2i(323, 192), Vector2i(66, 28)),
		make_pair(Vector2i(413, 195), Vector2i(69, 24)),
		make_pair(Vector2i(509, 193), Vector2i(79, 26)),
	};

	pair<Vector2i, Vector2i> _stone = _stoneData[GetRandomNumberInRange(0, CAST(int, _stoneData.size() - 1))];

	return Level::SpawnActor(MeshActor(RectangleShapeData(CAST(Vector2f, _stone.second), prefix + "decorates", PNG, false, IntRect(_stone.first, _stone.second))));
}

MeshActor* CombatLevel::GetBarrel() const
{
	vector<pair<Vector2i, Vector2i>> _stoneData =
	{
		make_pair(Vector2i(90, 109), Vector2i(43, 34)),
		make_pair(Vector2i(153, 102), Vector2i(31, 38)),
	};

	pair<Vector2i, Vector2i> _stone = _stoneData[GetRandomNumberInRange(0, CAST(int, _stoneData.size() - 1))];

	return Level::SpawnActor(MeshActor(RectangleShapeData(CAST(Vector2f, _stone.second), prefix + "decorates", PNG, false, IntRect(_stone.first, _stone.second))));
}

MeshActor* CombatLevel::GetChest() const
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

	return Level::SpawnActor(MeshActor(RectangleShapeData(CAST(Vector2f, _stone.second), prefix + "decorates", PNG, false, IntRect(_stone.first, _stone.second))));
}

MeshActor* CombatLevel::GetStone() const
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

	return Level::SpawnActor(MeshActor(RectangleShapeData(CAST(Vector2f, _stone.second), prefix + "decorates", PNG, false, IntRect(_stone.first, _stone.second))));
}
#pragma endregion

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

Vector2f CombatLevel::GetRandomPosition(const pair<Vector2f, Vector2f>& _location)
{
	const float _x = GetRandomNumberInRange(_location.first.x, _location.second.x);
	const float _y = GetRandomNumberInRange(_location.first.y, _location.second.y);
	return Vector2f(_x, _y);
}