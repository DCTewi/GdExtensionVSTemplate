#pragma once

#include <godot_cpp/classes/sprite2d.hpp>

namespace godot
{
	class GDExample : public Sprite2D
	{
		GDCLASS(GDExample, Sprite2D)

	private:
		double _time_passed = 0.0;
		double _time_emit = 0.0;
		double _amplitude = 10.0;
		double _speed = 1.0;

	public:
		void set_amplitude(const double& amplitude);
		double get_amplitude() const;
		void set_speed(const double& speed);
		double get_speed() const;

	protected:
		static void _bind_methods();

	public:
		GDExample();
		~GDExample();

		virtual void _process(double delta) override;
	};
}
