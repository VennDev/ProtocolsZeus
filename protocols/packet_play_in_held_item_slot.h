#ifndef PACKET_PLAY_IN_HELD_ITEM_SLOT_H
#define PACKET_PLAY_IN_HELD_ITEM_SLOT_H

#include "../compat/packet.h"

using namespace Compat;

namespace Protocols
{
	class PacketPlayInHeldItemSlot : public Packet
	{
	private:
		int _idi;
		int _meta;
		int _slot;
		std::string _name;
		std::string _lore;

	public:
		PacketPlayInHeldItemSlot(
			int id,
			std::string origin,
			double timeCurrent,
			int idi,
			int meta,
			int slot,
			std::string name,
			std::string lore
		) : Packet(id, origin, timeCurrent)
		{
			_idi = idi;
			_meta = meta;
			_slot = slot;
			_name = name;
			_lore = lore;
		}

		int getIdItem()
		{
			return _idi;
		}

		int getMeta()
		{
			return _meta;
		}

		int getSlot()
		{
			return _slot;
		}

		std::string getName()
		{
			return _name;
		}

		std::string getLore()
		{
			return _lore;
		}
	};
}

#endif