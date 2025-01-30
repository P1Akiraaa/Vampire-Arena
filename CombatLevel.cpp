#include "CombatLevel.h"

CombatLevel::CombatLevel()
{
	player = nullptr;
	enemy = nullptr;
	round = 1;

	backGround = Level::SpawnActor(MeshActor(RectangleShapeData(Vector2f(1920, 1080), "Arena", PNG)));
	CharacterData _data1 = CharacterData("Thomas");
	player = Level::SpawnActor(Player(RectangleShapeData(Vector2f(300.0f, 300.0f), "Player"), _data1));
	player->SetPosition(Vector2f(100.0f, 223.5f));
	CharacterData _data2 = CharacterData("TrouDuc");
	enemy = Level::SpawnActor(Enemy(RectangleShapeData(Vector2f(300.0f, 300.0f), "Enemy"), _data2));
	enemy->SetPosition(Vector2f(1785.0f, 223.5f));
	enemy->SetScale(Vector2f(-1.0f, 1.0f));
}

CombatLevel::CombatLevel(Player* _player, Enemy* _enemy)
{
	backGround = Level::SpawnActor(MeshActor(RectangleShapeData(Vector2f(1920, 1080), "Arena", PNG)));
	player = _player;
	enemy = _enemy;
	round = 1;
}

void CombatLevel::Round()
{
}

void CombatLevel::Start()
{
	Super::Start();


	const float _sideStartX = 100.0f;
	float _sideStartY = 105.0f;
	const Vector2f& _meshSize = Vector2f(300.0f, 400.0f);
	const Vector2f& _spaceBetween = Vector2f(1400.0f, 20.0f);
	player->StartAnim();
	enemy->StartAnim();

	for (u_int _index = 0; _index < 2; _index++)
	{
		MeshActor* _sideButton = Level::SpawnActor(MeshActor(RectangleShapeData(Vector2f(300.0f, 40.0f), "Default")));
		_sideButton->SetPosition(Vector2f(_sideStartX + _index * _spaceBetween.x, _sideStartY + 400.0f + _spaceBetween.y));

		MeshActor* _sideButton2 = Level::SpawnActor(MeshActor(RectangleShapeData(Vector2f(300.0f, 200.0f), "Default")));
		_sideButton2->SetPosition(Vector2f(_sideStartX + _index * _spaceBetween.x, _sideButton->GetPosition().y + _sideButton->GetMesh()->GetShape()->GetDrawable()->getGlobalBounds().size.y + _spaceBetween.y));
	}
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