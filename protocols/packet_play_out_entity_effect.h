#ifndef PACKET_PLAY_OUT_ENTITY_EFFECT_H
#define PACKET_PLAY_OUT_ENTITY_EFFECT_H

#include "../compat/packet.h"

using namespace Compat;

namespace Protocols
{
	class PacketPlayOutEntityEffect : public Packet
	{
	private:
		unsigned char _effectId;
		float _amplifier;
		float _duration;
		unsigned char _flags;

	public:
		unsigned char const ABSORPTION = 22;
		unsigned char const BAD_OMEN = 24;
		unsigned char const BLINDNESS = 15;
		unsigned char const CONDUIT_POWER = 25;
		unsigned char const DOLPHINS_GRACE = 26;
		unsigned char const FIRE_RESISTANCE = 12;
		unsigned char const GLOWING = 25;
		unsigned char const HASTE = 3;
		unsigned char const HEALTH_BOOST = 21;
		unsigned char const HERO_OF_THE_VILLAGE = 27;
		unsigned char const HUNGER = 17;
		unsigned char const INSTANT_DAMAGE = 2;
		unsigned char const INSTANT_HEALTH = 1;
		unsigned char const INVISIBILITY = 14;
		unsigned char const JUMP = 8;
		unsigned char const LEVITATION = 24;
		unsigned char const LUCK = 23;
		unsigned char const MINING_FATIGUE = 4;
		unsigned char const NAUSEA = 9;
		unsigned char const NIGHT_VISION = 16;
		unsigned char const POISON = 19;
		unsigned char const REGENERATION = 10;
		unsigned char const RESISTANCE = 11;
		unsigned char const SATURATION = 23;
		unsigned char const SLOWNESS = 5;
		unsigned char const SLOW_FALLING = 28;
		unsigned char const SPEED = 1;
		unsigned char const STRENGTH = 5;
		unsigned char const UNLUCK = 22;
		unsigned char const WATER_BREATHING = 13;
		unsigned char const WEAKNESS = 18;
		unsigned char const WITHER = 20;

		unsigned char const ADD = 0;
		unsigned char const MODIFY = 1;
		unsigned char const REMOVE = 2;

		PacketPlayOutEntityEffect(
			int id,
			std::string origin,
			double timeCurrent,
			unsigned char effectId,
			float amplifier,
			float duration,
			unsigned char flags
		) : Packet(id, origin, timeCurrent)
		{
			_effectId = effectId;
			_amplifier = amplifier;
			_duration = duration;
			_flags = flags;
		}

		unsigned char getEffectId()
		{
			return _effectId;
		}

		float getAmplifier()
		{
			return _amplifier;
		}

		float getDuration()
		{
			return _duration;
		}

		unsigned char getFlags()
		{
			return _flags;
		}
	};
}

#endif