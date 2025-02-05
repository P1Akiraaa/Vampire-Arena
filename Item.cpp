#include "Item.h"

string Item::GetRarityName()
{
    string _rarityName[] = { "M�diocre","Commune" ,"Extravagante" ,"Rare", "�pique", "L�gendaire","Sanguine" };
    return _rarityName[itemData.rarity - 1];
}

string Item::GetFlavorText()
{
    string _flavorText[] = { "se moqueront de vous", "regagneront confiance", "se m�fieront", "seront sur leur garde", "vous craindront", "s'enfuiront", "vous supplieront de les �pargner" };
    return _flavorText[itemData.rarity - 1] + " en voyant un tel objet.";
}
