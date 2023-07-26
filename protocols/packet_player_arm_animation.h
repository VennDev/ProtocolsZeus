#ifndef PACKET_PLAYER_ARM_ANIMATION_H
#define PACKET_PLAYER_ARM_ANIMATION_H

#include "../compat/packet.h"

using namespace Compat;

namespace Protocols
{
	class PacketPlayerArmAnimation : public Packet
	{
	private:
		bool _cancelled;

	public:
		PacketPlayerArmAnimation(
			int id,
			std::string origin,
			double timeCurrent
		) : Packet(id, origin, timeCurrent)
		{
			_cancelled = false;
		}

		void cancel()
		{
			_cancelled = true;
		}

		bool isCancelled()
		{
			return _cancelled;
		}
	};
}

#endif