-- premake5.lua
workspace "Neurovisualization"
   architecture "x64"
   configurations { "Debug", "Release", "Dist" }
   startproject "RADBI"

   -- Workspace-wide build options for MSVC
   filter "system:windows"
      buildoptions { "/EHsc", "/Zc:preprocessor", "/Zc:__cplusplus" }

OutputDir = "%{cfg.system}-%{cfg.architecture}/%{cfg.buildcfg}"

group "Core"
	include "Core/Build-Core.lua"
group ""

include "RADBI/Build-RADBI.lua"

include "Hippo/Build-Hippo.lua"