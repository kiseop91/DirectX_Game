workspace "DirectStudy"
	configurations
	{
		"Debug",
		"Release"
	}

	platforms
	{
		"x86",
	}
	characterset ("Unicode")

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "DirectPrac"
	location "DirectPrac"
	kind "WindowedApp"
	language "C++"

	-- pchheader "dx3dpch.h"
	-- pchsource "DirectPrac/src/dx3dpch.cpp"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	includedirs
	{
        "%{prj.name}/src",
        "vendor/DirectX/Include"
	}
	libdirs
	{
		--"vendor/fmod/lib",
		"vendor/DirectX/Lib/x86"
	}
	links
	{
		--"fmod_vc.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

	filter "configurations:Debug"
		symbols "On"
	
	filter "configurations:Release"
		optimize "On"
