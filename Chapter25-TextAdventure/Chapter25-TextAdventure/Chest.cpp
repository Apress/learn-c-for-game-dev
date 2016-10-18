#include "Chest.h"

Chest::Chest(const Item* item, unsigned int serializableId)
: Serializable(serializableId)
, m_item{item}
{

}

void Chest::Update()
{
	// nothing to do for a chest
}