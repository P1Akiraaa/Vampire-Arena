#include "CombatLevel.h"

CombatLevel::CombatLevel(Character* _player, Character* _enemy)
{
	backGround = Level::SpawnActor(MeshActor(RectangleShapeData(Vector2f(1920, 1080), "Arena", PNG)));
	player = Level::SpawnActor(Character(RectangleShapeData(Vector2f(300.0f, 300.0f), "Player"), CharacterData("Thomas")));
	player->SetPosition(Vector2f(100.0f, 223.5f));
	enemy = Level::SpawnActor(Character(RectangleShapeData(Vector2f(300.0f, 300.0f), "Enemy"), CharacterData("Laurent")));
	enemy->SetPosition(Vector2f(1785.0f, 223.5f));
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