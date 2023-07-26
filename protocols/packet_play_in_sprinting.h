#ifndef PACKET_PLAY_IN_SPRINTING_H
#define PACKET_PLAY_IN_SPRINTING_H

#include "../compat/packet.h"

using namespace Compat;

namespace Protocols
{
	class PacketPlayInSprinting : public Packet
	{
	private:
		bool _cancelled;

	public:
		PacketPlayInSprinting(
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