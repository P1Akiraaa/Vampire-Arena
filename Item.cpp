#include "Item.h"

string Item::GetRarityName()
{
    string _rarityName[] = { "Médiocre","Commune" ,"Extravagante" ,"Rare", "Épique", "Légendaire","Sanguine" };
    return _rarityName[itemData.rarity - 1];
}

string Item::GetFlavorText()
{
    string _flavorText[] = { "se moqueront de vous", "regagneront confiance", "se méfieront", "seront sur leur garde", "vous craindront", "s'enfuiront", "vous supplieront de les épargner" };
    return _flavorText[itemData.rarity - 1] + " en voyant un tel objet.";
}
