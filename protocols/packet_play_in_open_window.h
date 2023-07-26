#ifndef PACKET_PLAY_OPEN_WINDOW_H
#define PACKET_PLAY_OPEN_WINDOW_H

#include "../compat/packet.h"

using namespace Compat;

namespace Protocols
{
	class PacketPlayInOpenWindow : public Packet
	{
	private:
		bool _cancelled;

	public:
		PacketPlayInOpenWindow(
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