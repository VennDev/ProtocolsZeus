#ifndef PACKET_PLAY_IN_ROTATION_H
#define PACKET_PLAY_IN_ROTATION_H

#include "../compat/packet.h"

using namespace Compat;

namespace Protocols
{
	class PacketPlayInRotation : public Packet
	{
	private:
		float _yaw;
		float _pitch;

	public:
		PacketPlayInRotation(
			int id,
			std::string origin,
			double timeCurrent,
			float yaw,
			float pitch
		) : Packet(id, origin, timeCurrent)
		{
			_yaw = yaw;
			_pitch = pitch;
		}

		float getYaw()
		{
			return _yaw;
		}

		float getPitch()
		{
			return _pitch;
		}
	};
}

#endif