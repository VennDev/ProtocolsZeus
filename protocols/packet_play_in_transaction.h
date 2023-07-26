#ifndef PACKET_PLAY_IN_TRANSACTION_H
#define PACKET_PLAY_IN_TRANSACTION_H

#include "../compat/packet.h"

using namespace Compat;

namespace Protocols
{
	class PacketPlayInTransaction : public Packet
	{
	private:
		int _sourceType;
		int _sourceFlags;
		unsigned char _slot;

	public:
		const unsigned char SOURCE_CONTAINER = 0;
		const unsigned char SOURCE_WORLD = 2;
		const unsigned char SOURCE_CREATIVE = 3;
		const unsigned int SOURCE_TODO = 99999;
		const signed char SOURCE_TYPE_CRAFTING_RESULT = -4;
		const signed char SOURCE_TYPE_CRAFTING_USE_INGREDIENT = -5;
		const signed char SOURCE_TYPE_ANVIL_RESULT = -12;
		const signed char SOURCE_TYPE_ANVIL_OUTPUT = -13;
		const signed char SOURCE_TYPE_ENCHANT_OUTPUT = -17;
		const signed char SOURCE_TYPE_TRADING_INPUT_1 = -20;
		const signed char SOURCE_TYPE_TRADING_INPUT_2 = -21;
		const signed char SOURCE_TYPE_TRADING_USE_INPUTS = -22;
		const signed char SOURCE_TYPE_TRADING_OUTPUT = -23;
		const signed char SOURCE_TYPE_BEACON = -24;
		const unsigned char ACTION_MAGIC_SLOT_CREATIVE_DELETE_ITEM = 0;
		const unsigned char ACTION_MAGIC_SLOT_CREATIVE_CREATE_ITEM = 1;
		const unsigned char ACTION_MAGIC_SLOT_DROP_ITEM = 0;
		const unsigned char ACTION_MAGIC_SLOT_PICKUP_ITEM = 1;

		PacketPlayInTransaction(
			int id,
			std::string origin,
			double timeCurrent,
			int sourceType,
			int sourceFlags,
			unsigned char slot
		) : Packet(id, origin, timeCurrent)
		{
			_sourceType = sourceType;
			_sourceFlags = sourceFlags;
			_slot = slot;
		}

		int getSourceType()
		{
			return _sourceType;
		}

		int getSourceFlags()
		{
			return _sourceFlags;
		}

		unsigned char getSlot()
		{
			return _slot;
		}
	};
}

#endif