
#include "lammpsplugin.h"
#include "version.h"

#include "pair_aeam.h"

using namespace LAMMPS_NS;

static Pair *pair_aeam_creator(LAMMPS *lmp)
{
  return new PairAEAM(lmp);
}

extern "C" void lammpsplugin_init(void *lmp, void *handle, void *regfunc)
{
  lammpsplugin_t plugin;
  lammpsplugin_regfunc register_plugin = (lammpsplugin_regfunc) regfunc;

  // register pace pair style
  plugin.version = LAMMPS_VERSION;
  plugin.style = "pair";
  plugin.name = "aeam";
  plugin.info = "AEAM plugin pair style v1.0";
  plugin.author = "Axel Kohlmeyer (akohlmey@gmail.com)";
  plugin.creator.v1 = (lammpsplugin_factory1 *) &pair_aeam_creator;
  plugin.handle = handle;
  (*register_plugin)(&plugin, lmp);
}
