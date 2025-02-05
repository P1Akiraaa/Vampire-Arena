#include "HorizontalBox.h"
#include "Level.h"
#include "HUD.h"

HorizontalBox::HorizontalBox(const BoxData& _data) : Box(_data)
{
	
}

void HorizontalBox::Update()
{
	Super::Update();

	const float _totalSizeX = GetSize().x;
	const u_int& _totalElement = GetElementCount();
	const float _spaceX = (_totalSizeX - data.spaceBetween * (_totalElement - 1)) / _totalElement;
	float _allElementsSize = 0.0f;
	for (Widget* _widget : widgets)
	{
		const float _sizeX = _widget->GetSize().x;
		const float _newScale = _sizeX / _spaceX;
		_widget->Scale(Vector2f(_newScale, _newScale));
		_allElementsSize += _sizeX * _newScale;
	}

	float _currentX = (_totalSizeX - _allElementsSize) / 2.0f;
	const float _y = GetPosition().y;
	for (Widget* _widget : widgets)
	{
		const float _computeSizeX = _widget->GetSize().x * _widget->GetScale().x;
		_widget->SetPosition(Vector2f(_computeSizeX, _y));
		_currentX += _computeSizeX;
	}
}