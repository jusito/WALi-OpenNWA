from conans import ConanFile, CMake, tools


class WALiOpenNWAConan(ConanFile):
    name = "WALi-OpenNWA"
    version = "4.2"
    license = "not set"
    author = "not set"
    url = "https://github.com/pdschubert/WALi-OpenNWA"
    description = "WALi weighted automaton library"
    topics = ("WALi", "automaton")
    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False], "fPIC": [True, False]}
    default_options = {"shared": False, "fPIC": True}
    generators = "cmake_find_package", "cmake_paths"
    exports_sources = "*"
    requires = "llvm-core/12.0.0"

    def _patch_sources(self):
        for patch in self.conan_data.get("patches", {}).get(self.version, []):
            tools.patch(**patch)

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def package(self):
        self.copy("LICENSE")
        self.copy("*.h", dst="include", src="Source/wali/include")
        self.copy("*.hpp", dst="include", src="Source/wali/include")
        self.copy("*.dll", dst="bin", keep_path=False)
        self.copy("*.so", dst="lib", keep_path=False)
        self.copy("*.dylib", dst="lib", keep_path=False)
        self.copy("*.a", dst="lib", keep_path=False)

    def package_info(self):
        self.cpp_info.libs = ["hello"]
