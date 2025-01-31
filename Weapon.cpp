#include "Weapon.h"
#include "Utilities.h"

Weapon::Weapon(const Weapon& _other)
{
	equipableData = _other.equipableData;
	itemData = _other.itemData;
}

Weapon::Weapon()
{
	equipableData.element = ElementType(GetRandomNumberInRange(1, 3));
	equipableData.weight = double(GetRandomNumberInRange(1, 20) / 10);
	equipableData.size = EquipableSize(GetSize());
	itemData.name = ComputeWeaponName();
	itemData.description = ComputeWeaponDescription();
	itemData.texture = GetWeaponTexture();
	itemData.upgradePrice = (equipableData.equipableStat * 10) * double(itemData.rarity);	
}
Weapon::Weapon(ElementType _elementType, double _weight, RarityType _rarity)
{
	equipableData.element = _elementType;
	equipableData.weight = _weight;
	itemData.rarity = _rarity;
	equipableData.size = EquipableSize(GetSize());
	itemData.name = ComputeWeaponName();
	itemData.description = ComputeWeaponDescription();
	itemData.texture = GetWeaponTexture();
	itemData.upgradePrice = (equipableData.equipableStat * 10) * double(itemData.rarity);
}

string Weapon::ComputeWeaponName()
{
	const int _index = CAST(int, equipableData.element) - 1;
	const vector<function<string()>>& _weaponName =
	{
		[&]()
		{
			string _slashName[] = { "Dagger", "Sword", "Claymore" };
			return _slashName[equipableData.size - 1];
		},
		[&]()
		{
			 string _bluntName[] = { "Fist", "Mace", "Hammer" };
			 return _bluntName[equipableData.size - 1];
		},
		[&]()
		{
			string _pierceName[] = { "Katar", "Spear", "Lance" };
		    return _pierceName[equipableData.size - 1];
		},
	};
	return _weaponName[_index]();
}

string Weapon::ComputeWeaponDescription()
{
	return string(ComputeWeaponName() + " de qualité " + GetRarityName() + ". \n" + GetFlavorText());
}

Texture Weapon::GetWeaponTexture()
{
	const int _index = CAST(int, equipableData.element) - 1;
	const vector<function<Texture()>>& _weaponTexture =
	{
		[&]()
		{
			string _slashName[] = { "Dagger", "Sword", "Claymore" };
		return Texture("Assets/Textures/Equipable/Weapon/Slash/" + _slashName[equipableData.size - 1] 
					 + "/" + "rarity" + to_string(itemData.rarity) + ".png");
		},
		[&]()
		{
			 string _bluntName[] = { "Fist", "Mace", "Hammer" };
		return Texture("Assets/Textures/Equipable/Weapon/Slash/" + _bluntName[equipableData.size - 1] 
					 + "/" + "rarity" + to_string(itemData.rarity) + ".png");
		},
		[&]()
		{
			string _pierceName[] = { "Katar", "Spear", "Lance" };
		return Texture("Assets/Textures/Equipable/Weapon/Slash/" + _pierceName[equipableData.size - 1] 
					 + "/" + "rarity" + to_string(itemData.rarity) + ".png");
		},
	};
	return _weaponTexture[_index]();
}

