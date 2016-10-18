#include "Chest.h"

Chest::Chest(const Item* item, const uint32_t serializableId)
: Serializable(serializableId)
, m_item{item}
{

}

void Chest::Update()
{
	// nothing to do for a chest
}