#include "DoorRotatingEntity.h"
#include "TimeUtil.h"
#include "Audio/AudioDevice.h"
#include "Audio/AudioClip.h"

namespace Freeking
{
	DoorRotatingEntity::DoorRotatingEntity() : BrushModelEntity(),
		_speed(100.0f),
		_angle(0.0f),
		_distance(0.0f),
		_wait(3.0f),
		_currentDistance(0.0f),
		_timeToClose(0.0),
		_open(false)
	{
	}

	void DoorRotatingEntity::Tick(double dt)
	{
		BrushModelEntity::Tick(dt);

		if (_open && _wait > 0.0f && Time::Now() >= _timeToClose)
		{
			Close();
		}

		_currentDistance += ((_speed * dt) * (_open ? 1.0f : -1.0f));
		_currentDistance = Math::Clamp(_currentDistance, 0.0f, _distance);

		SetRotation(Quaternion::FromDegreeYaw(_currentDistance * -1.0f));
	}

	void DoorRotatingEntity::OnTrigger()
	{
		if (!_open)
		{
			Open();
		}
	}

	void DoorRotatingEntity::Open()
	{
		_open = true;
		_timeToClose = Time::Now() + _wait;

		AudioDevice::Current->Play(AudioClip::Library.Get("sound/world/doors/dr3_strt.wav").get(), GetTransformCenter().Translation());
	}

	void DoorRotatingEntity::Close()
	{
		_open = false;

		AudioDevice::Current->Play(AudioClip::Library.Get("sound/world/doors/dr3_strt.wav").get(), GetTransformCenter().Translation());
	}

	bool DoorRotatingEntity::SetProperty(const EntityProperty& property)
	{
		if (property.IsKey("speed"))
		{
			return property.ValueAsFloat(_speed);
		}
		else if (property.IsKey("distance"))
		{
			return property.ValueAsFloat(_distance);
		}
		else if (property.IsKey("wait"))
		{
			return property.ValueAsFloat(_wait);
		}

		return BrushModelEntity::SetProperty(property);
	}

	void DoorRotatingEntity::InitializeAngleProperty(float angle)
	{
		// "angle" for this entity is used for direction and not entity rotation
		_angle = angle;
	}
}
