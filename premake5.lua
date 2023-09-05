workspace "PhysicsEngine"
    architecture "x64"
    
    configurations
    {
        "Debug",
        "Release"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}}"

project "PhysicsEngine"
    location "PhysicsEngine"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"

    targetdir ("bin/" .. outputdir .. "%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "%{prj.name}")

    files
    {
        "%{prj.name}/src/**.cpp",
        "%{prj.name}/src/**.h",
        "%{prj.name}/libraries/glad/src/glad.c",
        "%{prj.name}/libraries/stb/stb/stb_image.cpp"
    }

    includedirs
    {
        "PhysicsEngine/libraries/glm",
        "PhysicsEngine/libraries/glad/include",
        "PhysicsEngine/libraries/GLFW/include",
        "PhysicsEngine/libraries/glm",
        "PhysicsEngine/libraries/stb"
    }

    libdirs
    {
        "PhysicsEngine/libraries/GLFW/lib"
    }

    links
    {
        "glfw3",
        "opengl32"
    }

    filter "configurations:Debug"
        defines "CP_DEBUG"
        symbols "On"

    filter "configurations:Release"
    defines "CP_RELEASE"
    optimize "On"