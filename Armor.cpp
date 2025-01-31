#include "Armor.h"
#include "Utilities.h"

Armor::Armor(const Armor& _other)
{
	equipableData = _other.equipableData;
	itemData = _other.itemData;
}

Armor::Armor()
{
	equipableData.element = ElementType(GetRandomNumberInRange(1, 3));
	equipableData.weight = double(GetRandomNumberInRange(1, 20) / 10);
	equipableData.size = EquipableSize(GetSize());
	itemData.name = ComputeArmorName();
	itemData.description = ComputeArmorDescription();
	itemData.texture = GetArmorTexture();
	itemData.upgradePrice = (equipableData.equipableStat * 10) * double(itemData.rarity);
}
Armor::Armor(ElementType _elementType, double _weight = 1, RarityType _rarity)
{
	equipableData.element = _elementType;
	equipableData.weight = _weight;
	itemData.rarity = _rarity;
	equipableData.size = EquipableSize(GetSize());
	itemData.name = ComputeArmorName();
	itemData.description = ComputeArmorDescription();
	itemData.texture = GetArmorTexture();
	itemData.upgradePrice = (equipableData.equipableStat * 10) * double(itemData.rarity);
}

string Armor::ComputeArmorName()
{
	string _armorName[] = { "Robe", "Tenue", "Armure" };
	return _armorName[equipableData.size - 1];
}

string Armor::ComputeArmorDescription()
{
	return string(ComputeArmorName() + " de qualité " + GetRarityName() + ". \n" + GetFlavorText());
}

Texture Armor::GetArmorTexture()
{
	const int _index = CAST(int, equipableData.size) - 1;
	const vector<function<Texture()>>& _armorTexture =
	{
		[&]()
		{
			return Texture("Assets/Textures/Equipable/Armor/Light/rarity_" + to_string(itemData.rarity) + ".png");
		},
		[&]()
		{
			  return Texture("Assets/Textures/Equipable/Armor/Medium/rarity" + to_string(itemData.rarity) + ".png");
		},
		[&]()
		{
			return Texture("Assets/Textures/Equipable/Armor/Large/rarity_" + to_string(itemData.rarity) + ".png");
		},
	};
	return _armorTexture[_index]();
}

