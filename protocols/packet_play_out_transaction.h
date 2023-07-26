#ifndef PACKET_PLAY_OUT_TRANSACTION_H
#define PACKET_PLAY_OUT_TRANSACTION_H

#include "../compat/packet.h"

using namespace Compat;

namespace Protocols
{
	class PacketPlayOutTransaction : public Packet
	{
	private:
		int _sourceType;
		int _sourceFlags;
		int _slot;

	public:
		int const SOURCE_CONTAINER = 0;
		int const SOURCE_WORLD = 2;
		int const SOURCE_CREATIVE = 3;
		int const SOURCE_TODO = 99999;
		int const SOURCE_TYPE_CRAFTING_RESULT = -4;
		int const SOURCE_TYPE_CRAFTING_USE_INGREDIENT = -5;
		int const SOURCE_TYPE_ANVIL_RESULT = -12;
		int const SOURCE_TYPE_ANVIL_OUTPUT = -13;
		int const SOURCE_TYPE_ENCHANT_OUTPUT = -17;
		int const SOURCE_TYPE_TRADING_INPUT_1 = -20;
		int const SOURCE_TYPE_TRADING_INPUT_2 = -21;
		int const SOURCE_TYPE_TRADING_USE_INPUTS = -22;
		int const SOURCE_TYPE_TRADING_OUTPUT = -23;
		int const SOURCE_TYPE_BEACON = -24;

		int const ACTION_MAGIC_SLOT_CREATIVE_DELETE_ITEM = 0;
		int const ACTION_MAGIC_SLOT_CREATIVE_CREATE_ITEM = 1;
		int const ACTION_MAGIC_SLOT_DROP_ITEM = 0;
		int const ACTION_MAGIC_SLOT_PICKUP_ITEM = 1;

		PacketPlayOutTransaction(
			int id,
			std::string origin,
			double timeCurrent,
			int sourceType,
			int slot,
			int sourceFlags = 0
		) : Packet(id, origin, timeCurrent)
		{
			_sourceType = sourceType;
			_slot = slot;
			_sourceFlags = sourceFlags;
		}

		int getSourceType()
		{
			return _sourceType;
		}

		int getSlot()
		{
			return _slot;
		}

		int getSourceFlags()
		{
			return _sourceFlags;
		}
	};
}

#endif