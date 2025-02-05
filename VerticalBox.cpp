#include "VerticalBox.h"
#include "Level.h"

VerticalBox::VerticalBox(const BoxData& _data) : Box(_data)
{
	
}

void VerticalBox::Update()
{
	Super::Update();

	const float _totalSizeY = GetSize().y;
	const u_int& _totalElement = GetElementCount();
	const float _spaceY = (_totalSizeY - data.spaceBetween * (_totalElement - 1)) / _totalElement;
	float _allElementsSize = 0.0f;
	for (Widget* _widget : widgets)
	{
		const float _sizeY = _widget->GetSize().y;
		const float _newScale = _sizeY / _spaceY;
		_widget->Scale(Vector2f(_newScale, _newScale));
		_allElementsSize += _sizeY * _newScale;
	}

	float _currentY = (_totalSizeY - _allElementsSize) / 2.0f;
	const float _x = GetPosition().x;
	for (Widget* _widget : widgets)
	{
		const float _computeSizeY = _widget->GetSize().y * _widget->GetScale().y;
		_widget->SetPosition(Vector2f(_x, _computeSizeY));
		_currentY += _computeSizeY;
	}
}