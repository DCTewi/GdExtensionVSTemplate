#include "pch.h"
#include "gd_example.h"

void godot::GDExample::set_amplitude(const double& amplitude)
{
	_amplitude = amplitude;
}

double godot::GDExample::get_amplitude() const
{
	return _amplitude;
}

void godot::GDExample::set_speed(const double& speed)
{
	_speed = speed;
}

double godot::GDExample::get_speed() const
{
	return _speed;
}

void godot::GDExample::_bind_methods()
{
	ClassDB::bind_method(D_METHOD("get_amplitude"), &GDExample::get_amplitude);
	ClassDB::bind_method(D_METHOD("set_amplitude"), &GDExample::set_amplitude);
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "amplitude"), "set_amplitude", "get_amplitude");

	ClassDB::bind_method(D_METHOD("get_speed"), &GDExample::get_speed);
	ClassDB::bind_method(D_METHOD("set_speed"), &GDExample::set_speed);
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "speed", PROPERTY_HINT_RANGE, "0,20,0.01"), "set_speed", "get_speed");

	ADD_SIGNAL(MethodInfo("position_changed", PropertyInfo(Variant::OBJECT, "node"), PropertyInfo(Variant::VECTOR2, "new_pos")));
}

godot::GDExample::GDExample()
{
}

godot::GDExample::~GDExample()
{
}

void godot::GDExample::_process(double delta)
{
	_time_passed += _speed * delta;

	Vector2 new_position = Vector2(
		_amplitude + (_amplitude * sin(_time_passed * 2.0)),
		_amplitude + (_amplitude * cos(_time_passed * 1.5))
	);

	set_position(new_position);

	_time_emit += delta;
	if (_time_emit > 1.0)
	{
		emit_signal("position_changed", this, new_position);
		_time_emit = 0.0;
	}
}
