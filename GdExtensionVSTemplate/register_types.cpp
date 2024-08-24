#include "pch.h"

#include "gd_example.h"

namespace entry
{
	godot::ModuleInitializationLevel minimum_init_level = godot::MODULE_INITIALIZATION_LEVEL_SCENE;

	void init_module(godot::ModuleInitializationLevel level)
	{
		switch (level)
		{
		case godot::MODULE_INITIALIZATION_LEVEL_CORE:
		{
			break;
		}
		case godot::MODULE_INITIALIZATION_LEVEL_SERVERS:
		{
			break;
		}
		case godot::MODULE_INITIALIZATION_LEVEL_SCENE:
		{
			godot::ClassDB::register_class<godot::GDExample>();
			break;
		}
		case godot::MODULE_INITIALIZATION_LEVEL_EDITOR:
		{
			break;
		}
		case godot::MODULE_INITIALIZATION_LEVEL_MAX:
		{
			break;
		}
		default:
			break;
		}
	}

	void uninit_module(godot::ModuleInitializationLevel level)
	{
		switch (level)
		{
		case godot::MODULE_INITIALIZATION_LEVEL_CORE:
		{
			break;
		}
		case godot::MODULE_INITIALIZATION_LEVEL_SERVERS:
		{
			break;
		}
		case godot::MODULE_INITIALIZATION_LEVEL_SCENE:
		{
			break;
		}
		case godot::MODULE_INITIALIZATION_LEVEL_EDITOR:
		{
			break;
		}
		case godot::MODULE_INITIALIZATION_LEVEL_MAX:
		{
			break;
		}
		default:
			break;
		}
	}
}

extern "C"
{
	GDExtensionBool GDE_EXPORT gdextension_main(GDExtensionInterfaceGetProcAddress p_get_proc_address,
		const GDExtensionClassLibraryPtr p_library, GDExtensionInitialization* r_initialization)
	{
		godot::GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);

		init_obj.register_initializer(entry::init_module);
		init_obj.register_terminator(entry::uninit_module);

		init_obj.set_minimum_library_initialization_level(entry::minimum_init_level);

		return init_obj.init();
	}
}
