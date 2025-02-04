#include "Torch.h"
#include "Level.h"

Torch::Torch() : MeshActor()
{
	prefix = "Map/";

	vector<pair<Vector2i, Vector2i>> _stoneData =
	{
		make_pair(Vector2i(173, 272), Vector2i(17, 33)),
		make_pair(Vector2i(212, 270), Vector2i(20, 36)),
		make_pair(Vector2i(251, 266), Vector2i(18, 37)),
	};
	pair<Vector2i, Vector2i> _stone = _stoneData[GetRandomNumberInRange(0, CAST(int, _stoneData.size() - 1))];
	torch = Level::SpawnActor(MeshActor(RectangleShapeData(CAST(Vector2f, _stone.second), prefix + "decorates", PNG, false, IntRect(_stone.first, _stone.second))));

	//torch->AddChild();
}