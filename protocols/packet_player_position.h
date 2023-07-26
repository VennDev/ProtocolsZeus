#ifndef PACKET_PLAYER_POSITION_H
#define PACKET_PLAYER_POSITION_H

#include "../compat/packet.h"

using namespace Compat;

namespace Protocols
{
	class PacketPlayerPosition : public Packet
	{
	private:
		float _x;
		float _y;
		float _z;
		float _yaw;
		float _pitch;
		bool _onGround;

	public:
		PacketPlayerPosition(
			int id,
			std::string origin,
			double timeCurrent,
			float x,
			float y,
			float z,
			float yaw,
			float pitch,
			bool onGround
		) : Packet(id, origin, timeCurrent)
		{
			_x = x;
			_y = y;
			_z = z;
			_yaw = yaw;
			_pitch = pitch;
			_onGround = onGround;
		}

		float getX()
		{
			return _x;
		}

		float getY()
		{
			return _y;
		}

		float getZ()
		{
			return _z;
		}

		float getYaw()
		{
			return _yaw;
		}

		float getPitch()
		{
			return _pitch;
		}

		bool isOnGround()
		{
			return _onGround;
		}
	};
}

#endif