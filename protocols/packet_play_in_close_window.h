#ifndef PACKET_PLAY_IN_CLOSE_WINDOW_H
#define PACKET_PLAY_IN_CLOSE_WINDOW_H

#include "../compat/packet.h"

using namespace Compat;

namespace Protocols
{
	class PacketPlayInCloseWindow : public Packet
	{
	private:
		bool _cancelled;

	public:
		PacketPlayInCloseWindow(
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