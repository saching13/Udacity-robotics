#include <gazebo/gazebo.hh>

namespace gazebo{

   class worldPluginSags : public WorldPlugin{
	public:
		worldPluginSags() : WorldPlugin(){
			printf("Hello World\n");
		}

		void Load(physics::WorldPtr _world, sdf::ElementPtr _sdf){
		}
	
	};
	GZ_REGISTER_WORLD_PLUGIN(worldPluginSags)
   }
